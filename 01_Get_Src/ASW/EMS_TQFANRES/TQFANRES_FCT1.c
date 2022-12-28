/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQFANRES                                                */
/* !Description     : TQFANRES component                                      */
/*                                                                            */
/* !Module          : TQFANRES                                                */
/* !Description     : RESERVE DE COUPLE GMV                                   */
/*                                                                            */
/* !File            : TQFANRES_FCT1.C                                         */
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
/*   1 / TQFANRES_vidInitOutput                                               */
/*   2 / TQFANRES_vidReserveGMV                                               */
/*   3 / TQFANRES_vidTraitementEntreesGMV                                     */
/*   4 / TQFANRES_vidCoupleTransitoireGMV                                     */
/*   5 / TQFANRES_vidConditionReserveGMV                                      */
/*   6 / TQFANRES_vidLoSpdDelayOn                                             */
/*   7 / TQFANRES_vidHiSpdDelayOn                                             */
/*   8 / TQFANRES_vidStFanDelayOff                                            */
/*   9 / TQFANRES_vidCalculReserveGMV                                         */
/*                                                                            */
/* !Reference   : V02 NT 10 05001 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0180 / 2.1                                      */
/* !OtherRefs   : VEMS V02 ECU#050195                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQFANRES/TQFANRES$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "Std_Types.h"
#include "Mathsrv.h"
#include "TQFANRES.h"
#include "TQFANRES_L.h"
#include "TQFANRES_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des sorties.                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Ext_stCfFan;                                                  */
/*  input uint16 TqRes_spdVehFanRes_A[8];                                     */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqRes_nEngFanRes_A[8];                                       */
/*  input uint8 TqRes_facCmpFanRes_M[8][8];                                   */
/*  input uint16 TqRes_tqCmpB1FanLoss_C;                                      */
/*  input boolean TqRes_bCmdHiSpdFan;                                         */
/*  input boolean TqRes_bCmdLoSpdFan;                                         */
/*  input uint16 TqRes_tqCmpPvGvB2FanLoss_C;                                  */
/*  input uint16 TqRes_tqCmpGvB2FanLoss_C;                                    */
/*  input uint16 TqRes_tqCmpPvB2FanLoss_C;                                    */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  output uint16 TqRes_facCmpFanRes;                                         */
/*  output uint16 TqRes_tqFanStrtLoss;                                        */
/*  output uint32 TQFANRES_u32FiltredFanStrtLosMem;                           */
/*  output boolean TqRes_bCdnFanRes;                                          */
/*  output uint16 TqRes_tqFanRes;                                             */
/*  output boolean TQFANRES_bCmdHiSpdFanPrev;                                 */
/*  output boolean TQFANRES_bCmdLoSpdFanPrev;                                 */
/*  output boolean TQFANRES_bTurnOffDelayIn;                                  */
/*  output uint16 TQFANRES_u16tiFanResCpt1;                                   */
/*  output uint16 TQFANRES_u16tiFanResCpt2;                                   */
/*  output uint16 TQFANRES_u16tiFanResCpt3;                                   */
/*  output boolean TQFANRES_bGmvTrigger;                                      */
/*  output boolean TqRes_bCdnLnrSpdFanRes_MP;                                 */
/*  output boolean TQFANRES_bCdnFanResPrev;                                   */
/*  output uint16 TqRes_tqFanResSat_MP;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidInitOutput(void)
{
   uint8   u8LocalInterp;
   uint8   u8LocalExt_stCfFan;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalTqResfacCmpFanRes;
   uint16  u16LocalInitFilter;
   uint16  u16LocalTqRes_tqFanStrtLoss;
   uint16  u16LocalTqRes_tqIdlRes;
   uint32  u32LocalInitFilter;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(Ext_stCfFan, u8LocalExt_stCfFan);

   u16LocalVeh_spdVeh = (uint16)(u16LocalVeh_spdVeh / 32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqRes_spdVehFanRes_A,
                                                u16LocalVeh_spdVeh,
                                                8);

   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(TqRes_nEngFanRes_A,
                                                u16LocalEng_nCkFil,
                                                8);

   u8LocalInterp = MATHSRV_u8Interp2d(&TqRes_facCmpFanRes_M[0][0],
                                      u16LocalParaX,
                                      u16LocalParaY,
                                      8);
   u16LocalTqResfacCmpFanRes = (uint16)(u8LocalInterp * 8);
   TqRes_facCmpFanRes = (uint16)MATHSRV_udtMIN(u16LocalTqResfacCmpFanRes, 1024);
   u8LocalExt_stCfFan = (uint8)MATHSRV_udtMIN(u8LocalExt_stCfFan, 2);
   if (u8LocalExt_stCfFan == 0)
   {
      u16LocalInitFilter = TqRes_tqCmpB1FanLoss_C;
   }
   else
   {
      if (u8LocalExt_stCfFan == 1)
      {
         if (TqRes_bCmdHiSpdFan != 0)
         {
            if (TqRes_bCmdLoSpdFan != 0)
            {
               u16LocalInitFilter = TqRes_tqCmpPvGvB2FanLoss_C;
            }
            else
            {
               u16LocalInitFilter = TqRes_tqCmpGvB2FanLoss_C;
            }
         }
         else
         {
            u16LocalInitFilter = TqRes_tqCmpPvB2FanLoss_C;
         }
      }
      else
      {
         u16LocalInitFilter = 0;
      }
   }
   u32LocalInitFilter =
      (uint32)((u16LocalInitFilter * u16LocalTqResfacCmpFanRes) / 1024) ;
   u16LocalTqRes_tqFanStrtLoss =
      (uint16)MATHSRV_udtMIN(u32LocalInitFilter, 1600);
   VEMS_vidSET(TqRes_tqFanStrtLoss, u16LocalTqRes_tqFanStrtLoss);
   TQFANRES_u32FiltredFanStrtLosMem =
      (uint32)(u16LocalTqRes_tqFanStrtLoss * 256);

   VEMS_vidSET(TqRes_bCdnFanRes, 0);
   VEMS_vidSET(TqRes_tqFanRes, 0);
   TQFANRES_bCmdHiSpdFanPrev = 0;
   TQFANRES_bCmdLoSpdFanPrev = 0;
   TQFANRES_bTurnOffDelayIn = 0;
   TQFANRES_u16tiFanResCpt1 = 0;
   TQFANRES_u16tiFanResCpt2 = 0;
   TQFANRES_u16tiFanResCpt3 = 0;
   TQFANRES_bGmvTrigger = 0;
   TqRes_bCdnLnrSpdFanRes_MP = 0;
   TQFANRES_bCdnFanResPrev = 0;
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   TqRes_tqFanResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidReserveGMV                                     */
/* !Description :  La fonction traite trois types de GMV : GMV classe B1 à    */
/*                 vitesse continue, GMV classe B2 à deux vitesses variables  */
/*                 et le GMV classe C à vitesse variable.                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_08_07509_001.01                                     */
/*                 VEMS_R_10_05001_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQFANRES_vidTraitementEntreesGMV();                      */
/*  extf argret void TQFANRES_vidCoupleTransitoireGMV();                      */
/*  extf argret void TQFANRES_vidConditionReserveGMV();                       */
/*  extf argret void TQFANRES_vidCalculReserveGMV();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidReserveGMV(void)
{
   TQFANRES_vidTraitementEntreesGMV();
   TQFANRES_vidCoupleTransitoireGMV();
   TQFANRES_vidConditionReserveGMV();
   TQFANRES_vidCalculReserveGMV();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidTraitementEntreesGMV                           */
/* !Description :  La fonction retraite les commandes des GMV quelque soit    */
/*                 leur type. Lorsque Ext_stCfFan = 1, le GMV tourne à grande */
/*                 vitesse. Lorsque Ext_stCfFan = 2, le GMV peut tourner à    */
/*                 deux vitesses différentes. Lorsque Ext_stCfFan = 0, le GMV */
/*                 est en vitesse continue                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05001_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input boolean ThMgt_bCmdLowSpdFan;                                        */
/*  input boolean ThMgt_bTarLowSpdFan;                                        */
/*  input boolean ThMgt_bTarHiSpdFan;                                         */
/*  input boolean ThMgt_bCmdHiSpdFan;                                         */
/*  input uint8 Ext_stCfFan;                                                  */
/*  output boolean TqRes_bCmdHiSpdFan;                                        */
/*  output boolean TqRes_bTarHiSpdFan;                                        */
/*  output boolean TqRes_bCmdLoSpdFan;                                        */
/*  output boolean TqRes_bTarLoSpdFan;                                        */
/*  output uint8 TqRes_rSpdFanReq;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidTraitementEntreesGMV(void)
{
   boolean  bLocalThMgt_bTarLowSpdFan;
   boolean  bLocalThMgt_bCmdLowSpdFan;
   boolean  bLocalThMgt_bTarHiSpdFan;
   boolean  bLocalThMgt_bCmdHiSpdFan;
   uint8    u8LocalExt_stCfFan;
   uint8    u8LocalThMgt_rSpdFanReq;


   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgt_rSpdFanReq);
   VEMS_vidGET(ThMgt_bCmdLowSpdFan, bLocalThMgt_bCmdLowSpdFan);
   VEMS_vidGET(ThMgt_bTarLowSpdFan, bLocalThMgt_bTarLowSpdFan);
   VEMS_vidGET(ThMgt_bTarHiSpdFan, bLocalThMgt_bTarHiSpdFan);
   VEMS_vidGET(ThMgt_bCmdHiSpdFan, bLocalThMgt_bCmdHiSpdFan);
   VEMS_vidGET(Ext_stCfFan, u8LocalExt_stCfFan);

   if (  (u8LocalExt_stCfFan == 0)
      || (u8LocalExt_stCfFan == 1))
   {
      TqRes_bCmdHiSpdFan = bLocalThMgt_bCmdHiSpdFan;
      TqRes_bTarHiSpdFan = bLocalThMgt_bTarHiSpdFan;
   }
   else
   {
      TqRes_bCmdHiSpdFan = 0;
      TqRes_bTarHiSpdFan = 0;
   }

   if (u8LocalExt_stCfFan == 1)
   {
      TqRes_bCmdLoSpdFan = bLocalThMgt_bCmdLowSpdFan;
      TqRes_bTarLoSpdFan = bLocalThMgt_bTarLowSpdFan;
   }
   else
   {
      TqRes_bCmdLoSpdFan = 0;
      TqRes_bTarLoSpdFan = 0;
   }

   if (  (u8LocalExt_stCfFan == 2)
      || (u8LocalExt_stCfFan == 3))
   {
      TqRes_rSpdFanReq =
            (uint8)MATHSRV_udtMIN(u8LocalThMgt_rSpdFanReq,110);
   }
   else
   {
      TqRes_rSpdFanReq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidCoupleTransitoireGMV                           */
/* !Description :  Le couple GMV compensé est le produit d’une valeur de      */
/*                 couple calibrable sélectionnée suivant le type de GMV et le*/
/*                 facteur d’atténuation qui varie en fonction du régime      */
/*                 moteur et la vitesse véhicule dans une cartographie        */
/*                 calibrable.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05001_004.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 Ext_stCfFan;                                                  */
/*  input uint16 TqRes_spdVehFanRes_A[8];                                     */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqRes_nEngFanRes_A[8];                                       */
/*  input uint8 TqRes_facCmpFanRes_M[8][8];                                   */
/*  input uint16 TqRes_tqCmpB1FanLoss_C;                                      */
/*  input boolean TqRes_bCmdHiSpdFan;                                         */
/*  input boolean TqRes_bCmdLoSpdFan;                                         */
/*  input uint16 TqRes_tqCmpPvGvB2FanLoss_C;                                  */
/*  input uint16 TqRes_tqCmpGvB2FanLoss_C;                                    */
/*  input uint16 TqRes_tqCmpPvB2FanLoss_C;                                    */
/*  input boolean TQFANRES_bCmdHiSpdFanPrev;                                  */
/*  input boolean TQFANRES_bCmdLoSpdFanPrev;                                  */
/*  input boolean TqRes_bRstTqFanLoss_MP;                                     */
/*  input uint16 TqRes_facCmpFanRes;                                          */
/*  input uint8 TqRes_facFilTqFanLoss_C;                                      */
/*  input uint32 TQFANRES_u32FiltredFanStrtLosMem;                            */
/*  output uint16 TqRes_facCmpFanRes;                                         */
/*  output boolean TqRes_bRstTqFanLoss_MP;                                    */
/*  output uint32 TQFANRES_u32FiltredFanStrtLosMem;                           */
/*  output uint16 TqRes_tqFanStrtLoss;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidCoupleTransitoireGMV(void)
{
   uint8   u8LocalInterp;
   uint8   u8LocalExt_stCfFan;
   uint8   u8LocalFilterGain;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalTqResfacCmpFanRes;
   uint16  u16LocalInitFilter;
   uint16  u16LocalTqRes_tqFanStrtLoss;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(Ext_stCfFan, u8LocalExt_stCfFan);

   u16LocalVeh_spdVeh = (uint16)(u16LocalVeh_spdVeh / 32);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqRes_spdVehFanRes_A,
                                                u16LocalVeh_spdVeh,
                                                8);

   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(TqRes_nEngFanRes_A,
                                                u16LocalEng_nCkFil,
                                                8);

   u8LocalInterp = MATHSRV_u8Interp2d(&TqRes_facCmpFanRes_M[0][0],
                                      u16LocalParaX,
                                      u16LocalParaY,
                                      8);
   u16LocalTqResfacCmpFanRes = (uint16)(u8LocalInterp * 8);
   TqRes_facCmpFanRes = (uint16)MATHSRV_udtMIN(u16LocalTqResfacCmpFanRes, 1024);

   u8LocalExt_stCfFan = (uint8)MATHSRV_udtMIN(u8LocalExt_stCfFan, 2);
   if (u8LocalExt_stCfFan == 0)
   {
      u16LocalInitFilter = TqRes_tqCmpB1FanLoss_C;
   }
   else
   {
      if (u8LocalExt_stCfFan == 1)
      {
         if (TqRes_bCmdHiSpdFan != 0)
         {
            if (TqRes_bCmdLoSpdFan != 0)
            {
               u16LocalInitFilter = TqRes_tqCmpPvGvB2FanLoss_C;
            }
            else
            {
               u16LocalInitFilter = TqRes_tqCmpGvB2FanLoss_C;
            }
         }
         else
         {
            u16LocalInitFilter = TqRes_tqCmpPvB2FanLoss_C;
         }
      }
      else
      {
         u16LocalInitFilter = 0;
      }
   }

   if (  ((TqRes_bCmdHiSpdFan != 0) && (TQFANRES_bCmdHiSpdFanPrev == 0))
      || ((TqRes_bCmdLoSpdFan != 0) && (TQFANRES_bCmdLoSpdFanPrev == 0)))
   {
      TqRes_bRstTqFanLoss_MP = 1;
   }
   else
   {
      TqRes_bRstTqFanLoss_MP = 0;
   }
   if (TqRes_bRstTqFanLoss_MP != 0)
   {
      u16LocalInitFilter =
         (uint16)((u16LocalInitFilter * TqRes_facCmpFanRes) / 1024) ;
      u16LocalTqRes_tqFanStrtLoss = u16LocalInitFilter ;
      TQFANRES_u32FiltredFanStrtLosMem = (uint32)(u16LocalInitFilter * 256);
   }
   else
   {
      if (TqRes_facFilTqFanLoss_C < 128)
      {
         u8LocalFilterGain = (uint8)(TqRes_facFilTqFanLoss_C * 2);
         u16LocalTqRes_tqFanStrtLoss =
            MATHSRV_u16FirstOrderFilterGu8(u8LocalFilterGain,
                                           &TQFANRES_u32FiltredFanStrtLosMem,
                                           0);
      }
      else
      {
         u16LocalTqRes_tqFanStrtLoss = 0;
         TQFANRES_u32FiltredFanStrtLosMem = 0;
      }
   }
   u16LocalTqRes_tqFanStrtLoss =
      (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqFanStrtLoss, 1600);
   VEMS_vidSET(TqRes_tqFanStrtLoss, u16LocalTqRes_tqFanStrtLoss);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidConditionReserveGMV                            */
/* !Description :  La condition réserve de couple GMV est active si au moins  */
/*                 une des trois conditions est valide.                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05001_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQFANRES_vidLoSpdDelayOn();                              */
/*  extf argret void TQFANRES_vidHiSpdDelayOn();                              */
/*  extf argret void TQFANRES_vidStFanDelayOff();                             */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 TqRes_tiFanRes_C;                                             */
/*  input boolean TqRes_bCdnLoSpdFanRes_MP;                                   */
/*  input boolean TqRes_bCdnHiSpdFanRes_MP;                                   */
/*  input boolean TqRes_bCdnLnrSpdFanRes_MP;                                  */
/*  output uint8 TqRes_tiFanRes;                                              */
/*  output boolean TqRes_bCdnFanRes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidConditionReserveGMV(void)
{
   TqRes_tiFanRes = (uint8)MATHSRV_udtMIN(TqRes_tiFanRes_C, 240);
   TQFANRES_vidLoSpdDelayOn();
   TQFANRES_vidHiSpdDelayOn();
   TQFANRES_vidStFanDelayOff();

   if (  (TqRes_bCdnLoSpdFanRes_MP != 0)
      || (TqRes_bCdnHiSpdFanRes_MP != 0)
      || (TqRes_bCdnLnrSpdFanRes_MP != 0) )
   {
      VEMS_vidSET(TqRes_bCdnFanRes, 1);
   }
   else
   {
      VEMS_vidSET(TqRes_bCdnFanRes, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidLoSpdDelayOn                                   */
/* !Description :  Produit le booléen d'activation de la petite vitesse (PV)  */
/*                 du GMV.                                                    */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TqRes_bCmdLoSpdFan;                                         */
/*  input boolean TQFANRES_bCmdLoSpdFanPrev;                                  */
/*  input uint8 TqRes_tiFanRes;                                               */
/*  input uint16 TQFANRES_u16tiFanResCpt1;                                    */
/*  input boolean TqRes_bTarLoSpdFan;                                         */
/*  output uint16 TQFANRES_u16tiFanResCpt1;                                   */
/*  output boolean TQFANRES_bCmdLoSpdFanPrev;                                 */
/*  output boolean TqRes_bCdnLoSpdFanRes_MP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidLoSpdDelayOn(void)
{
   boolean bLocalDelayOutput;
   uint16  u16LocalScalTqRestiFanResC;


   if ( TqRes_bCmdLoSpdFan != 0 )
   {
      if ( TQFANRES_bCmdLoSpdFanPrev == 0 )
      {
         u16LocalScalTqRestiFanResC = (uint16)((25 * TqRes_tiFanRes) / 4);
         TQFANRES_u16tiFanResCpt1 = (uint16)MATHSRV_udtMIN(
                                            u16LocalScalTqRestiFanResC,
                                            1500);
      }
      else
      {
         if ( TQFANRES_u16tiFanResCpt1 > 0 )
         {
            TQFANRES_u16tiFanResCpt1 = (uint16)(TQFANRES_u16tiFanResCpt1 - 1);
         }
      }
      if ( TQFANRES_u16tiFanResCpt1 == 0 )
      {
         bLocalDelayOutput = 1;
      }
      else
      {
         bLocalDelayOutput = 0;
      }
   }
   else
   {
      bLocalDelayOutput = 0;
   }
   TQFANRES_bCmdLoSpdFanPrev = TqRes_bCmdLoSpdFan;

   if ( (bLocalDelayOutput == 0) && (TqRes_bTarLoSpdFan != 0) )
   {
      TqRes_bCdnLoSpdFanRes_MP =  1;
   }
   else
   {
      TqRes_bCdnLoSpdFanRes_MP =  0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidHiSpdDelayOn                                   */
/* !Description :  Produit le booléen d'activation de la grande vitesse (GV)  */
/*                 du GMV.                                                    */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TqRes_bCmdHiSpdFan;                                         */
/*  input boolean TQFANRES_bCmdHiSpdFanPrev;                                  */
/*  input uint8 TqRes_tiFanRes;                                               */
/*  input uint16 TQFANRES_u16tiFanResCpt2;                                    */
/*  input boolean TqRes_bTarHiSpdFan;                                         */
/*  output uint16 TQFANRES_u16tiFanResCpt2;                                   */
/*  output boolean TQFANRES_bCmdHiSpdFanPrev;                                 */
/*  output boolean TqRes_bCdnHiSpdFanRes_MP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidHiSpdDelayOn(void)
{
   boolean bLocalDelayOutput;
   uint16  u16LocalScalTqRestiFanResC;

   if (TqRes_bCmdHiSpdFan != 0)
   {
      if (TQFANRES_bCmdHiSpdFanPrev == 0)
      {
         u16LocalScalTqRestiFanResC = (uint16)((25 * TqRes_tiFanRes) / 4);
         TQFANRES_u16tiFanResCpt2 = (uint16)MATHSRV_udtMIN(
                                           u16LocalScalTqRestiFanResC,
                                           1500);
      }
      else
      {
         if (TQFANRES_u16tiFanResCpt2 > 0)
         {
            TQFANRES_u16tiFanResCpt2 = (uint16)(TQFANRES_u16tiFanResCpt2 - 1);
         }
      }
      if (TQFANRES_u16tiFanResCpt2 == 0)
      {
         bLocalDelayOutput = 1 ;
      }
      else
      {
         bLocalDelayOutput = 0;
      }
   }
   else
   {
      bLocalDelayOutput = 0 ;
   }
   TQFANRES_bCmdHiSpdFanPrev = TqRes_bCmdHiSpdFan;

   if ( (bLocalDelayOutput == 0) && (TqRes_bTarHiSpdFan != 0) )
   {
      TqRes_bCdnHiSpdFanRes_MP =  1;
   }
   else
   {
      TqRes_bCdnHiSpdFanRes_MP =  0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidStFanDelayOff                                  */
/* !Description :  Produit le booléen d'activation du GMV de type C.          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean TQFANRES_bGmvTrigger;                                       */
/*  input uint8 TqRes_rSpdFanReq;                                             */
/*  input uint8 TqRes_rSpdThrFanRes_C;                                        */
/*  input boolean TQFANRES_bTurnOffDelayIn;                                   */
/*  input uint8 TqRes_tiFanRes;                                               */
/*  input uint16 TQFANRES_u16tiFanResCpt3;                                    */
/*  output boolean TQFANRES_bGmvTrigger;                                      */
/*  output boolean TqRes_bCdnLnrSpdFanRes_MP;                                 */
/*  output uint16 TQFANRES_u16tiFanResCpt3;                                   */
/*  output boolean TQFANRES_bTurnOffDelayIn;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidStFanDelayOff(void)
{
   boolean bLocalGmvTriggerPrev;
   boolean bLocalTurnOffDelayIn;
   uint16  u16LocalScalTqRestiFanResC;


   bLocalGmvTriggerPrev = TQFANRES_bGmvTrigger;
   if (TqRes_rSpdFanReq >= TqRes_rSpdThrFanRes_C)
   {
      TQFANRES_bGmvTrigger = 1;
   }
   else
   {
      TQFANRES_bGmvTrigger = 0;
   }

   if (  (TQFANRES_bGmvTrigger != 0)
      && (bLocalGmvTriggerPrev == 0))
   {
      bLocalTurnOffDelayIn = 1;
      TqRes_bCdnLnrSpdFanRes_MP = 1;
   }
   else
   {
      bLocalTurnOffDelayIn = 0;
      if (TQFANRES_bTurnOffDelayIn != 0)
      {
         u16LocalScalTqRestiFanResC = (uint16)((25 * TqRes_tiFanRes) / 4);
         TQFANRES_u16tiFanResCpt3 = (uint16)MATHSRV_udtMIN(
                                            u16LocalScalTqRestiFanResC,
                                            1500);
      }
      else
      {
         if (TQFANRES_u16tiFanResCpt3 > 0)
         {
            TQFANRES_u16tiFanResCpt3 = (uint16)(TQFANRES_u16tiFanResCpt3 - 1);
         }
      }
      if (TQFANRES_u16tiFanResCpt3 == 0)
      {
         TqRes_bCdnLnrSpdFanRes_MP = 0;
      }
      else
      {
         TqRes_bCdnLnrSpdFanRes_MP = 1;
      }
   }

   TQFANRES_bTurnOffDelayIn = bLocalTurnOffDelayIn;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQFANRES_vidCalculReserveGMV                               */
/* !Description :  La réserve de couple demandée varie entre la valeur 0 et le*/
/*                 produit du facteur  d’atténuation GMV  et  d’une  valeur   */
/*                 calibrable suivant  le  type  de GMV. Elle se  dégrade     */
/*                 progressivement  si  la  condition  réserve GMV  est  non  */
/*                 active.                                                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05001_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bCdnFanRes;                                           */
/*  input uint8 Ext_stCfFan;                                                  */
/*  input uint16 TqRes_tqFanResB1_C;                                          */
/*  input uint16 TqRes_tqFanResB2_C;                                          */
/*  input uint16 TqRes_tqFanResC_C;                                           */
/*  input uint16 TqRes_facCmpFanRes;                                          */
/*  input boolean TQFANRES_bCdnFanResPrev;                                    */
/*  input uint16 TqRes_tqIncMaxFanRes_C;                                      */
/*  input sint16 TqRes_tqDecMaxFanRes_C;                                      */
/*  input uint16 TqRes_tqFanResSat_MP;                                        */
/*  input uint16 TqRes_tqFanResNotSat_MP;                                     */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqRes_tqFanStrtLoss;                                         */
/*  output uint16 TqRes_tqFanResNotSat_MP;                                    */
/*  output uint16 TqRes_tqFanResSat_MP;                                       */
/*  output uint16 TqRes_tqFanRes;                                             */
/*  output boolean TQFANRES_bCdnFanResPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQFANRES_vidCalculReserveGMV(void)
{
   boolean bLocalTqRes_bCdnFanRes;
   boolean bLocalEnable;
   uint8   u8LocalExt_stCfFan;
   uint16  u16LocalTqRes_tqFanRe;
   uint16  u16LocalInc;
   uint16  u16LocalDec;
   uint16  u16LocalTqRes_tqFanStrtLoss;
   uint16  u16LocalTqRes_tqFanRes;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqRes_tqFanResSat_MP;
   uint32  u32LocalTqCdnStFanFanResMP;
   sint16  s16LocalDec;
   sint32  s32LocalTqRes_tqFanRes;


   VEMS_vidGET(TqRes_bCdnFanRes, bLocalTqRes_bCdnFanRes);

   if (bLocalTqRes_bCdnFanRes != 0)
   {
      VEMS_vidGET(Ext_stCfFan, u8LocalExt_stCfFan);
      u8LocalExt_stCfFan = (uint8)MATHSRV_udtMIN(u8LocalExt_stCfFan, 2);
      if (u8LocalExt_stCfFan == 0)
      {
         u16LocalTqRes_tqFanRe = TqRes_tqFanResB1_C;
      }
      else
      {
         if (u8LocalExt_stCfFan == 1)
         {
            u16LocalTqRes_tqFanRe = TqRes_tqFanResB2_C;
         }
         else
         {
            u16LocalTqRes_tqFanRe = TqRes_tqFanResC_C;
         }
      }
      u32LocalTqCdnStFanFanResMP =
         (uint32)((u16LocalTqRes_tqFanRe * TqRes_facCmpFanRes) / 1024);
      TqRes_tqFanResNotSat_MP =
         (uint16)MATHSRV_udtMIN(u32LocalTqCdnStFanFanResMP,1600);
   }
   else
   {
      TqRes_tqFanResNotSat_MP = 0;
   }

   if (  (bLocalTqRes_bCdnFanRes == 0)
      || (TQFANRES_bCdnFanResPrev !=0))
   {
      bLocalEnable = 1;
   }
   else
   {
      bLocalEnable = 0;
   }

   if (bLocalEnable != 0)
   {
      u16LocalInc = (uint16)(TqRes_tqIncMaxFanRes_C /25);
      s16LocalDec =  (sint16)(((-1) * TqRes_tqDecMaxFanRes_C) / 25);
      u16LocalDec =  (uint16)MATHSRV_udtMAX(s16LocalDec, 0);
      u16LocalTqRes_tqFanResSat_MP =
         MATHSRV_u16SlewFilter(TqRes_tqFanResSat_MP,
                               TqRes_tqFanResNotSat_MP,
                               u16LocalInc,
                               u16LocalDec);
      TqRes_tqFanResSat_MP =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqFanResSat_MP, 1600);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
      TqRes_tqFanResSat_MP =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes, 1600);
   }
   VEMS_vidGET(TqRes_tqFanStrtLoss,u16LocalTqRes_tqFanStrtLoss);
   s32LocalTqRes_tqFanRes =
      (sint32)(TqRes_tqFanResSat_MP - u16LocalTqRes_tqFanStrtLoss);
   u16LocalTqRes_tqFanRes =
      (uint16)MATHSRV_udtMAX(s32LocalTqRes_tqFanRes, 0);
   VEMS_vidSET(TqRes_tqFanRes,u16LocalTqRes_tqFanRes);
   TQFANRES_bCdnFanResPrev = bLocalTqRes_bCdnFanRes;

}
/*---------------------------------End Of File--------------------------------*/