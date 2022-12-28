/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FLOWMNG                                                 */
/* !Description     : FLOWMNG Component                                       */
/*                                                                            */
/* !Module          : FLOWMNG                                                 */
/* !Description     : Management of the configurable information flow         */
/*                                                                            */
/* !File            : FLOWMNG_FCT2.C                                          */
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
/*   1 / FLOWMNG_vidBrk_CAN_Info                                              */
/*   2 / FLOWMNG_vidBrkHorsDiagBVH2P                                          */
/*   3 / FLOWMNG_vidHorsDiagBVH2P_ABS                                         */
/*   4 / FLOWMNG_vidBrkDiagBVH2P                                              */
/*   5 / FLOWMNG_vidAlt_Bss_Load_Time                                         */
/*   6 / FLOWMNG_vidFirstDayCtMngInit                                         */
/*   7 / FLOWMNG_vidGMV                                                       */
/*   8 / FLOWMNG_vidFirstCases                                                */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT2.C_v        $*/
/* $Revision::   1.17     $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   10 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "MATHSRV.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidBrk_CAN_Info                                    */
/* !Description :  fonction qui traite le flux de données relatives aux       */
/*                 freinage en fonction de la présence ou d'abscence de l 'ABS*/
/*                 ou de l'ESP.                                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_022.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidBrkHorsDiagBVH2P();                           */
/*  extf argret void FLOWMNG_vidHorsDiagBVH2P_ABS();                          */
/*  extf argret void FLOWMNG_vidBrkDiagBVH2P();                               */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bASRESPCf;                                              */
/*  input boolean Ext_bABSCf;                                                 */
/*  input boolean Ext_bBrkDiagRelbCf;                                         */
/*  input boolean Ext_bBrkMainInfoCf;                                         */
/*  input boolean Ext_bMainBrkPedPrssHsMes;                                   */
/*  input boolean Ext_bMainBrkPedPrssMes;                                     */
/*  output boolean Bps_brake_pedal_can_hs;                                    */
/*  output boolean Bps_brake_pedal_can_input;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidBrk_CAN_Info(void)
{
   boolean bLocalExt_bBrkDiagRelbCf;
   boolean bLocalBps_brake_pedal_can_hs;
   boolean bLocalBps_brake_pedal_can_input;
   boolean bLocalExt_bBrkMainInfoCf;
   boolean bLocalExt_bASRESPCf;
   boolean bLocalExt_bABSCf;


   VEMS_vidGET(Ext_bASRESPCf, bLocalExt_bASRESPCf);
   VEMS_vidGET(Ext_bABSCf, bLocalExt_bABSCf);
   VEMS_vidGET(Ext_bBrkDiagRelbCf, bLocalExt_bBrkDiagRelbCf);
   VEMS_vidGET(Ext_bBrkMainInfoCf, bLocalExt_bBrkMainInfoCf);

   if (  (  (bLocalExt_bASRESPCf == 0)
         && (bLocalExt_bABSCf == 0))
      || (  (bLocalExt_bBrkDiagRelbCf == 0)
         && (bLocalExt_bBrkMainInfoCf == 0)))
   {
      FLOWMNG_vidBrkHorsDiagBVH2P();
   }
   if (  (bLocalExt_bBrkDiagRelbCf == 0)
      && (bLocalExt_bABSCf != 0)
      && (bLocalExt_bBrkMainInfoCf != 0))
   {
      FLOWMNG_vidHorsDiagBVH2P_ABS();
   }
   if (  (bLocalExt_bBrkDiagRelbCf != 0)
      && (bLocalExt_bABSCf != 0))
   {
      FLOWMNG_vidBrkDiagBVH2P();
   }
   VEMS_vidGET(Ext_bMainBrkPedPrssHsMes, bLocalBps_brake_pedal_can_hs);
   VEMS_vidSET(Bps_brake_pedal_can_hs, bLocalBps_brake_pedal_can_hs);
   VEMS_vidGET(Ext_bMainBrkPedPrssMes, bLocalBps_brake_pedal_can_input);
   VEMS_vidSET(Bps_brake_pedal_can_input, bLocalBps_brake_pedal_can_input);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidBrkHorsDiagBVH2P                                */
/* !Description :  Cette fonction met à jour l'etat du frein primaire.        */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean CoReqVeh_bMainBrkPedPrssHS;                                 */
/*  input boolean CoReqVeh_bMainBrkPedPrss;                                   */
/*  output boolean Ext_bMainBrkPedPrssHsMes;                                  */
/*  output boolean Ext_bMainBrkPedPrssMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidBrkHorsDiagBVH2P(void)
{
   boolean bLocalCoReqVeh_bMainBrkPedPrssHS;
   boolean bLocalCoReqVeh_bMainBrkPedPrss;


   VEMS_vidGET(CoReqVeh_bMainBrkPedPrssHS, bLocalCoReqVeh_bMainBrkPedPrssHS);
   VEMS_vidGET(CoReqVeh_bMainBrkPedPrss, bLocalCoReqVeh_bMainBrkPedPrss);

   VEMS_vidSET(Ext_bMainBrkPedPrssHsMes, bLocalCoReqVeh_bMainBrkPedPrssHS);
   VEMS_vidSET(Ext_bMainBrkPedPrssMes, bLocalCoReqVeh_bMainBrkPedPrss);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidHorsDiagBVH2P_ABS                               */
/* !Description :  Cette fonction met à jour l'etat du frein primaire.        */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean MonBrk_bMainBrkPedPrssHS;                                   */
/*  input boolean Cha_bMainBrkPedPrssMes;                                     */
/*  output boolean Ext_bMainBrkPedPrssHsMes;                                  */
/*  output boolean Ext_bMainBrkPedPrssMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidHorsDiagBVH2P_ABS(void)
{
   boolean bLocalMonBrk_bMainBrkPedPrssHS;
   boolean bLocalCha_bMainBrkPedPrssMes;

   VEMS_vidGET(MonBrk_bMainBrkPedPrssHS, bLocalMonBrk_bMainBrkPedPrssHS);
   VEMS_vidGET(Cha_bMainBrkPedPrssMes, bLocalCha_bMainBrkPedPrssMes);

   VEMS_vidSET(Ext_bMainBrkPedPrssHsMes, bLocalMonBrk_bMainBrkPedPrssHS);
   VEMS_vidSET(Ext_bMainBrkPedPrssMes, bLocalCha_bMainBrkPedPrssMes);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidBrkDiagBVH2P                                    */
/* !Description :  Cette fonction met à jour l'etat du frein primaire.        */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean MonBrk_bMainBrkPedPrssHS;                                   */
/*  input boolean CoReqVeh_bMainBrkPedPrss;                                   */
/*  output boolean Ext_bMainBrkPedPrssHsMes;                                  */
/*  output boolean Ext_bMainBrkPedPrssMes;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidBrkDiagBVH2P(void)
{
   boolean bLocalMonBrk_bMainBrkPedPrssHS;
   boolean bLocalCoReqVeh_bMainBrkPedPrss;

   VEMS_vidGET(MonBrk_bMainBrkPedPrssHS, bLocalMonBrk_bMainBrkPedPrssHS);
   VEMS_vidGET(CoReqVeh_bMainBrkPedPrss, bLocalCoReqVeh_bMainBrkPedPrss);

   VEMS_vidSET(Ext_bMainBrkPedPrssHsMes, bLocalMonBrk_bMainBrkPedPrssHS);
   VEMS_vidSET(Ext_bMainBrkPedPrssMes, bLocalCoReqVeh_bMainBrkPedPrss);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Bss_Load_Time                               */
/* !Description :  Fonction qui traite le temps progressive de chargement de  */
/*                 l'aternateur en fonction de la valeur de la variable       */
/*                 ElProdMgt_stProdPrgCh                                      */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ElProdMgt_stProdPrgCh;                                        */
/*  output uint8 Ext_stPrgBSSCh;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Bss_Load_Time(void)
{
   uint8 u8LocalElProdMgt_stProdPrgCh;
   uint8 u8LocalExt_stPrgBSSCh;

   VEMS_vidGET(ElProdMgt_stProdPrgCh, u8LocalElProdMgt_stProdPrgCh);

   if (u8LocalElProdMgt_stProdPrgCh <= PRODPRGCH_06)
   {
      u8LocalExt_stPrgBSSCh = EXT_STPRGBSSCH_0;
   }
   else
   {
      if (u8LocalElProdMgt_stProdPrgCh <= PRODPRGCH_10)
      {
         u8LocalExt_stPrgBSSCh = EXT_STPRGBSSCH_1;
      }
      else
      {
         if (u8LocalElProdMgt_stProdPrgCh <= PRODPRGCH_14)
         {
            u8LocalExt_stPrgBSSCh = EXT_STPRGBSSCH_2;
         }
         else
         {
            u8LocalExt_stPrgBSSCh = EXT_STPRGBSSCH_3;
         }
      }
   }
   VEMS_vidSET(Ext_stPrgBSSCh, u8LocalExt_stPrgBSSCh);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidFirstDayCtMngInit                               */
/* !Description :  Fonction d'initialisation de la variable                   */
/*                 FlowMng_bFirstDayCtMng.                                    */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean FlowMng_bFirstTiCntMng;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidFirstDayCtMngInit(void)
{
   /*04_bFirstDayCtMng_Init*/
   FlowMng_bFirstTiCntMng = 1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidGMV                                             */
/* !Description :  Fonction qui détermine la vitesse predite ou recommandée du*/
/*                 ventilateur en fonction de la configuration de MDF.        */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stCfFan;                                                  */
/*  input uint8 ThMgt_rSpdFanReq;                                             */
/*  input uint8 Ext_rSpdFanPredB2;                                            */
/*  input uint8 Ext_rSpdFanPredC;                                             */
/*  output uint8 Ext_rSpdFanReqB2;                                            */
/*  output uint8 Ext_rSpdFanPred;                                             */
/*  output uint8 Ext_rSpdFanReqC;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidGMV(void)
{
   uint8 u8LocalExt_stCfFan;
   uint8 u8LocalThMgt_rSpdFanReq;
   uint8 u8LocalExt_rSpdFanPredB2;
   uint8 u8LocalExt_rSpdFanPredC;
   uint8 u8LocalExt_rSpdFanReqB2;
   uint8 u8LocalExt_rSpdFanPred;
   uint8 u8LocalExt_rSpdFanReqC;


   VEMS_vidGET(Ext_stCfFan, u8LocalExt_stCfFan);
   VEMS_vidGET(ThMgt_rSpdFanReq, u8LocalThMgt_rSpdFanReq);
   VEMS_vidGET(Ext_rSpdFanPredB2, u8LocalExt_rSpdFanPredB2);
   VEMS_vidGET(Ext_rSpdFanPredC, u8LocalExt_rSpdFanPredC);
   if (  (u8LocalExt_stCfFan == 1)
      || (u8LocalExt_stCfFan == 4))
   {
      u8LocalExt_rSpdFanReqB2 = u8LocalThMgt_rSpdFanReq;
      u8LocalExt_rSpdFanPred = u8LocalExt_rSpdFanPredB2;
      u8LocalExt_rSpdFanReqC = 0;
   }
   else
   {
      if (  (u8LocalExt_stCfFan == 2)
         || (u8LocalExt_stCfFan == 3))
      {
         u8LocalExt_rSpdFanReqB2 = 0;
         u8LocalExt_rSpdFanPred = u8LocalExt_rSpdFanPredC;
         u8LocalExt_rSpdFanReqC = u8LocalThMgt_rSpdFanReq;
      }
      else
      {
         u8LocalExt_rSpdFanReqB2 = 0;
         u8LocalExt_rSpdFanReqC = 0;
         u8LocalExt_rSpdFanPred = 0;
      }
   }

   u8LocalExt_rSpdFanReqB2 =
      (uint8)MATHSRV_udtMIN(u8LocalExt_rSpdFanReqB2, 110);
   u8LocalExt_rSpdFanPred =
      (uint8)MATHSRV_udtMIN(u8LocalExt_rSpdFanPred, 110);
   u8LocalExt_rSpdFanReqC =
      (uint8)MATHSRV_udtMIN(u8LocalExt_rSpdFanReqC, 110);
   VEMS_vidSET(Ext_rSpdFanReqB2, u8LocalExt_rSpdFanReqB2);
   VEMS_vidSET(Ext_rSpdFanPred, u8LocalExt_rSpdFanPred);
   VEMS_vidSET(Ext_rSpdFanReqC, u8LocalExt_rSpdFanReqC);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidFirstCases                                      */
/* !Description :  First cases of Position Gear Level                         */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stPosATLevExtdCAN;                                        */
/*  input uint8 Ext_stPosATLevPNCAN;                                          */
/*  output boolean Ext_bPosAT_FrstCases;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidFirstCases(void)
{
   boolean bLocal_DftInvPosATLevPN;
   uint8   u8LocalExt_stPosATLevExtdCAN;
   uint8   u8LocalExt_stPosATLevPNCAN;


   bLocal_DftInvPosATLevPN = GDGAR_bGetFRM(FRM_FRM_DFTINVPOSATLEVPN);
   VEMS_vidGET(Ext_stPosATLevExtdCAN, u8LocalExt_stPosATLevExtdCAN);
   VEMS_vidGET(Ext_stPosATLevPNCAN, u8LocalExt_stPosATLevPNCAN);

   if( bLocal_DftInvPosATLevPN != 0)
   {
      Ext_bPosAT_FrstCases = 1;
   }
   else
   {
      if (  (  (u8LocalExt_stPosATLevExtdCAN == 0)
            && (u8LocalExt_stPosATLevPNCAN == 0))
         || (  (u8LocalExt_stPosATLevExtdCAN == 2)
            && (u8LocalExt_stPosATLevPNCAN == 1))
         || (  (u8LocalExt_stPosATLevExtdCAN == 1)
            && (u8LocalExt_stPosATLevPNCAN == 2))
         || (  (u8LocalExt_stPosATLevExtdCAN == 3)
            && (u8LocalExt_stPosATLevPNCAN == 2)))
      {
         Ext_bPosAT_FrstCases = 1;
      }
      else
      {
         Ext_bPosAT_FrstCases = 0;
      }
   }
}
/*------------------------------- end of file --------------------------------*/