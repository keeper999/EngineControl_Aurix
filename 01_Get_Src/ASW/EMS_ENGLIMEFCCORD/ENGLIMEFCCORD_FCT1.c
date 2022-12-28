/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : ENGLIMEFCCORD                                           */
/* !Description     : ENGLIMEFCCORD Component.                                */
/*                                                                            */
/* !Module          : ENGLIMEFCCORD                                           */
/* !Description     : Coordination des limitations CME.                       */
/*                                                                            */
/* !File            : ENGLIMEFCCORD_FCT1.C                                    */
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
/*   1 / ENGLIMEFCCORD_vidInitOutput                                          */
/*   2 / ENGLIMEFCCORD_vidCoord_Lim_CME                                       */
/*   3 / ENGLIMEFCCORD_vidLim_Stat_Air_Av                                     */
/*   4 / ENGLIMEFCCORD_vidLim_Preventif                                       */
/*   5 / ENGLIMEFCCORD_vidLimit_InterSys                                      */
/*   6 / ENGLIMEFCCORD_vidLim_BVAuto_1                                        */
/*   7 / ENGLIMEFCCORD_vidLim_BVAuto_2                                        */
/*   8 / ENGLIMEFCCORD_vidLim_ESP                                             */
/*   9 / ENGLIMEFCCORD_vidLim_ModSpt                                          */
/*   10 / ENGLIMEFCCORD_vidLimit_Divers                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 03267 / 03                                        */
/* !OtherRefs   : CSMT_CGMT08_0923 / 2.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/ENGLIMEFCCORD/ENG$*/
/* $Revision::   1.12                                                        $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "ENGLIMEFCCORD.h"
#include "ENGLIMEFCCORD_L.h"
#include "ENGLIMEFCCORD_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidInitOutput                                */
/* !Description :  Initialise les variables produites par la spec             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output sint16 EngLim_tqCkDrivFil;                                         */
/*  output sint16 EngLim_tqCkEfcACCmprLim;                                    */
/*  output sint16 EngLim_tqCkEfcATLimCordEL2;                                 */
/*  output sint16 EngLim_tqCkEfcAirGBxLimCord;                                */
/*  output sint16 EngLim_tqCkEfcAirLim;                                       */
/*  output sint16 EngLim_tqCkEfcChaLim;                                       */
/*  output sint16 EngLim_tqCkEfcGBxLimCord;                                   */
/*  output sint16 EngLim_tqCkEfcGBxLimCordEL2;                                */
/*  output sint16 EngLim_tqEfcMaxDynVehSpdCtl;                                */
/*  output sint16 EngLim_tqEfcMaxStatVehSpdCtl;                               */
/*  output sint16 EngLim_tqEfcNRegTakeOffLim;                                 */
/*  output sint16 EngLim_tqCkEfcModSptLim;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidInitOutput(void)
{
   VEMS_vidSET(EngLim_tqCkDrivFil, 32000);
   VEMS_vidSET(EngLim_tqCkEfcACCmprLim, 32000);
   VEMS_vidSET(EngLim_tqCkEfcATLimCordEL2, 32000);
   VEMS_vidSET(EngLim_tqCkEfcAirGBxLimCord, 32000);
   VEMS_vidSET(EngLim_tqCkEfcAirLim, 32000);
   VEMS_vidSET(EngLim_tqCkEfcChaLim, 32000);
   VEMS_vidSET(EngLim_tqCkEfcGBxLimCord, 32000);
   VEMS_vidSET(EngLim_tqCkEfcGBxLimCordEL2, 32000);
   VEMS_vidSET(EngLim_tqEfcMaxDynVehSpdCtl, 32000);
   VEMS_vidSET(EngLim_tqEfcMaxStatVehSpdCtl, 32000);
   VEMS_vidSET(EngLim_tqEfcNRegTakeOffLim, 32000);
   VEMS_vidSET(EngLim_tqCkEfcModSptLim, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidCoord_Lim_CME                             */
/* !Description :  La fonction de coordination des limitations GMP fournit les*/
/*                 couples de limitation utilisés par l’agrément, la xVV, la  */
/*                 boite, l’ESP pour créer des couples inter-systèmes.        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_001.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void ENGLIMEFCCORD_vidLim_Stat_Air_Av();                      */
/*  extf argret void ENGLIMEFCCORD_vidLim_Preventif();                        */
/*  extf argret void ENGLIMEFCCORD_vidLimit_InterSys();                       */
/*  extf argret void ENGLIMEFCCORD_vidLimit_Divers();                         */
/*  extf argret void ENGLIMEFCCORD_vidLimitCpleAirDsl();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidCoord_Lim_CME(void)
{
   ENGLIMEFCCORD_vidLim_Stat_Air_Av();
   ENGLIMEFCCORD_vidLim_Preventif();
   ENGLIMEFCCORD_vidLimit_InterSys();
   ENGLIMEFCCORD_vidLimit_Divers();
   ENGLIMEFCCORD_vidLimitCpleAirDsl();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_Stat_Air_Av                           */
/* !Description :  Les limitations de protection boite (statique et dynamique)*/
/*                 sont calculées dans ce bloc. On distingue les limitations  */
/*                 sur la branche avance et sur la branche air. On ajoute une */
/*                 coordination en prenant en compte le type de carburant.    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcInrtLim;                                       */
/*  input boolean EngLim_bLimDynSel_C;                                        */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input boolean TqRes_bAcvCll;                                              */
/*  input boolean TqSys_bTypFu;                                               */
/*  output sint16 EngLim_tqCkEfcAirGBxLimCord;                                */
/*  output sint16 EngLim_tqCkEfcGBxLimCord;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_Stat_Air_Av(void)
{
   boolean bLocalTqRes_bAcvCll;
   boolean bLocalTqSys_bTypFu;
   sint16  s16LocalAirGbxLimCord;
   sint16  s16LocalEngLim_tqCkEfcInrtLim;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqCkEfcGbxLimCord;


   VEMS_vidGET(EngLim_tqCkEfcInrtLim, s16LocalEngLim_tqCkEfcInrtLim);
   if (EngLim_bLimDynSel_C != 0)
   {
      s16LocalAirGbxLimCord = s16LocalEngLim_tqCkEfcInrtLim;
   }
   else
   {
      s16LocalAirGbxLimCord = 32000;
   }
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   s16LocalAirGbxLimCord = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcStatLim,
                                                  s16LocalAirGbxLimCord);

   s16LocalAirGbxLimCord = (sint16)MATHSRV_udtCLAMP(s16LocalAirGbxLimCord,
                                                    -32000,
                                                    32000);
   VEMS_vidSET(EngLim_tqCkEfcAirGBxLimCord, s16LocalAirGbxLimCord);

   VEMS_vidGET(TqRes_bAcvCll, bLocalTqRes_bAcvCll);
   VEMS_vidGET(TqSys_bTypFu, bLocalTqSys_bTypFu);
   if (  (bLocalTqRes_bAcvCll != 0)
      || (bLocalTqSys_bTypFu == 0))
   {
      s16LocalEngLim_tqCkEfcGbxLimCord =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcInrtLim,
                                s16LocalEngLim_tqCkEfcStatLim);
   }
   else
   {
      s16LocalEngLim_tqCkEfcGbxLimCord = s16LocalEngLim_tqCkEfcInrtLim;
   }
   s16LocalEngLim_tqCkEfcGbxLimCord =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkEfcGbxLimCord,
                               -32000,
                               32000);
   VEMS_vidSET(EngLim_tqCkEfcGBxLimCord, s16LocalEngLim_tqCkEfcGbxLimCord);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_Preventif                             */
/* !Description :  La limitation pour la fonction agrément est différente     */
/*                 selon que l’on est en présence d’une boite auto, dans ce   */
/*                 cas lors des SIP, elle prend en compte en plus le couple   */
/*                 max envoyé par la boite.                                   */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 EngLim_tqCkEfcSmkLim;                                        */
/*  input sint16 EngLim_tqCkEfcFLdLim;                                        */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input boolean TqSys_bTypFu;                                               */
/*  input sint16 EngLim_tqEfcEngCurMax;                                       */
/*  input boolean CoPt_bAcvTqMaxEstimSIP;                                     */
/*  input sint16 CoPt_tqEfcAirMaxEstim;                                       */
/*  input boolean EngLim_bSmkLimDrivFil_C;                                    */
/*  output sint16 EngLim_tqCkDrivFil;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_Preventif(void)
{
   boolean bLocalCoPt_bAcvTqMaxEstimSIP;
   boolean bLocalTqSys_bTypFu;
   sint16  s16LocalEngLim_tqCkEfcSmkLim;
   sint16  s16LocalOutSwitch;
   sint16  s16LocalEngLim_tqCkEfcFLdLim;
   sint16  s16LocalOutMin;
   sint16  s16LocalEngLim_tqCkEfcStatLim;
   sint16  s16LocalEngLim_tqEfc;
   sint16  s16LocalEngLim_tqEfcEngCurMax;
   sint16  s16LocalEngLim_tqCkDrivFil;
   sint16  s16LocalCoPt_tqEfcAirMaxEstim;


   VEMS_vidGET(EngLim_tqCkEfcSmkLim, s16LocalEngLim_tqCkEfcSmkLim);
   VEMS_vidGET(EngLim_tqCkEfcFLdLim, s16LocalEngLim_tqCkEfcFLdLim);
   VEMS_vidGET(EngLim_tqCkEfcStatLim, s16LocalEngLim_tqCkEfcStatLim);
   VEMS_vidGET(TqSys_bTypFu, bLocalTqSys_bTypFu);
   VEMS_vidGET(EngLim_tqEfcEngCurMax, s16LocalEngLim_tqEfcEngCurMax);
   VEMS_vidGET(CoPt_bAcvTqMaxEstimSIP, bLocalCoPt_bAcvTqMaxEstimSIP);
   VEMS_vidGET(CoPt_tqEfcAirMaxEstim, s16LocalCoPt_tqEfcAirMaxEstim);
   if (bLocalTqSys_bTypFu != 0)
   {
      s16LocalEngLim_tqEfc = s16LocalEngLim_tqEfcEngCurMax;
   }
   else
   {
      if (EngLim_bSmkLimDrivFil_C != 0)
      {
         s16LocalOutSwitch = s16LocalEngLim_tqCkEfcSmkLim;
      }
      else
      {
         s16LocalOutSwitch = 32000;
      }
      s16LocalOutMin = (sint16)MATHSRV_udtMIN(s16LocalOutSwitch,
                                              s16LocalEngLim_tqCkEfcFLdLim);
      s16LocalOutMin = (sint16)MATHSRV_udtMIN(s16LocalOutMin,
                                              s16LocalEngLim_tqCkEfcStatLim);
      s16LocalEngLim_tqEfc = s16LocalOutMin;
   }
   if (bLocalCoPt_bAcvTqMaxEstimSIP != 0)
   {
      s16LocalEngLim_tqCkDrivFil =
         (sint16)MATHSRV_udtMAX(s16LocalCoPt_tqEfcAirMaxEstim,
                                s16LocalEngLim_tqEfc);
   }
   else
   {
      s16LocalEngLim_tqCkDrivFil = s16LocalEngLim_tqEfc;
   }
   s16LocalEngLim_tqCkDrivFil =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkDrivFil, -32000, 32000);
   VEMS_vidSET(EngLim_tqCkDrivFil, s16LocalEngLim_tqCkDrivFil);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLimit_InterSys                            */
/* !Description :  Chaque couple de limitation crée est configuré par une     */
/*                 calibration. Cette calibration correspond à la somme des   */
/*                 valeurs couples de limitation à utiliser.                  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_004.03                                     */
/*                 VEMS_R_10_03267_005.01                                     */
/*                 VEMS_R_10_03267_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_BVAuto_1(argin sint16 s16TqSys1,    */
/* argin sint16 s16TqSys2, argin sint16 s16TqSys3);                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_BVAuto_2(argin sint16 s16TqSys1,    */
/* argin sint16 s16TqSys2, argin sint16 s16TqSys3);                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_ESP(argin sint16 s16TqSys1, argin   */
/* sint16 s16TqSys2, argin sint16 s16TqSys3);                                 */
/*  extf argret void ENGLIMEFCCORD_vidLim_ModSpt(argin sint16 s16TqSys1, argin*/
/* sint16 s16TqSys2, argin sint16 s16TqSys3);                                 */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bTypFu;                                               */
/*  input sint16 ThMgt_tqEfcLimAntiBoilProt;                                  */
/*  input sint16 EngLim_tqEfcLdMaxTrbMax;                                     */
/*  input sint16 EngLim_tqEfcPresUsThrMax;                                    */
/*  input sint16 EngLim_tqEfcEngCurMax;                                       */
/*  input sint16 EngLim_tqCkEfcFLdLim;                                        */
/*  input sint16 EngLim_tqCkEfcSmkLim;                                        */
/*  input sint16 EngLim_tqCkEfcLim;                                           */
/*  input sint16 EngLim_tqCkEfcChaLim;                                        */
/*  input boolean EngLim_bProtDfltChaSel_C;                                   */
/*  input sint16 CoPt_tqEfcMaxProtDftl;                                       */
/*  input sint16 EngLim_tqCkEfcModSptLim;                                     */
/*  input boolean EngLim_bProtDfltModSptSel_C;                                */
/*  output sint16 EngLim_tqCkEfcChaLim;                                       */
/*  output sint16 EngLim_tqCkEfcModSptLim;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLimit_InterSys(void)
{
   boolean  bLocalTqSys_bTypFu;
   sint16   s16LocalEngLim_tqCkEfcGBxLim;
   sint16   s16LocalEngLim_tqCkEfcATLim;
   sint16   s16LocalEngLim_tqCkEfcChaLim;
   sint16   s16LocalEThMgt_tqEfLimAntBoilPrt;
   sint16   s16LocalEngLim_tqEfcLdMaxTrbMax;
   sint16   s16LocalEngLim_tqEfcPresUsThrMax;
   sint16   s16LocalEngLim_tqEfcEngCurMax;
   sint16   s16LocalEngLim_tqCkEfcFLdLim;
   sint16   s16LocalEngLim_tqCkEfcSmkLim;
   sint16   s16LocalEngLim_tqCkEfcLim;
   sint16   s16LocalEngLim_tqCkEfcCha;
   sint16   s16LocalEngLim_tqCkEfcModSptLim;
   sint16   s16LocalCoPt_tqEfcMaxProtDftl;


   VEMS_vidGET(TqSys_bTypFu,bLocalTqSys_bTypFu);
   VEMS_vidGET(ThMgt_tqEfcLimAntiBoilProt,s16LocalEThMgt_tqEfLimAntBoilPrt);
   VEMS_vidGET(EngLim_tqEfcLdMaxTrbMax,s16LocalEngLim_tqEfcLdMaxTrbMax);
   VEMS_vidGET(EngLim_tqEfcPresUsThrMax,s16LocalEngLim_tqEfcPresUsThrMax);
   VEMS_vidGET(EngLim_tqEfcEngCurMax,s16LocalEngLim_tqEfcEngCurMax);
   if (bLocalTqSys_bTypFu != 0)
   {
      s16LocalEngLim_tqCkEfcGBxLim =
         (sint16)MATHSRV_udtMIN(s16LocalEThMgt_tqEfLimAntBoilPrt,
                                s16LocalEngLim_tqEfcLdMaxTrbMax);
      s16LocalEngLim_tqCkEfcATLim =
         (sint16)MATHSRV_udtMIN(s16LocalEThMgt_tqEfLimAntBoilPrt,
                                s16LocalEngLim_tqEfcPresUsThrMax);
      s16LocalEngLim_tqCkEfcChaLim =
         (sint16)MATHSRV_udtMIN(s16LocalEThMgt_tqEfLimAntBoilPrt,
                                s16LocalEngLim_tqEfcEngCurMax);
   }
   else
   {
      VEMS_vidGET(EngLim_tqCkEfcFLdLim,s16LocalEngLim_tqCkEfcFLdLim);
      VEMS_vidGET(EngLim_tqCkEfcSmkLim,s16LocalEngLim_tqCkEfcSmkLim);
      VEMS_vidGET(EngLim_tqCkEfcLim,s16LocalEngLim_tqCkEfcLim);
      s16LocalEngLim_tqCkEfcGBxLim = s16LocalEngLim_tqCkEfcFLdLim;
      s16LocalEngLim_tqCkEfcATLim = s16LocalEngLim_tqCkEfcSmkLim;
      s16LocalEngLim_tqCkEfcChaLim = s16LocalEngLim_tqCkEfcLim;
   }

   ENGLIMEFCCORD_vidLim_BVAuto_1(s16LocalEngLim_tqCkEfcGBxLim,
                                 s16LocalEngLim_tqCkEfcATLim,
                                 s16LocalEngLim_tqCkEfcChaLim);

   ENGLIMEFCCORD_vidLim_BVAuto_2(s16LocalEngLim_tqCkEfcGBxLim,
                                 s16LocalEngLim_tqCkEfcATLim,
                                 s16LocalEngLim_tqCkEfcChaLim);

   ENGLIMEFCCORD_vidLim_ESP(s16LocalEngLim_tqCkEfcGBxLim,
                            s16LocalEngLim_tqCkEfcATLim,
                            s16LocalEngLim_tqCkEfcChaLim);

   ENGLIMEFCCORD_vidLim_ModSpt(s16LocalEngLim_tqCkEfcGBxLim,
                               s16LocalEngLim_tqCkEfcATLim,
                               s16LocalEngLim_tqCkEfcChaLim);

   VEMS_vidGET(EngLim_tqCkEfcChaLim,s16LocalEngLim_tqCkEfcCha);
   if (EngLim_bProtDfltChaSel_C != 0)
   {
      VEMS_vidGET(CoPt_tqEfcMaxProtDftl, s16LocalCoPt_tqEfcMaxProtDftl);
      s16LocalEngLim_tqCkEfcCha =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcCha,
                                s16LocalCoPt_tqEfcMaxProtDftl);
   }
   else
   {
      s16LocalEngLim_tqCkEfcCha =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcCha,32000);
   }
   s16LocalEngLim_tqCkEfcCha =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkEfcCha, -32000, 32000);
   VEMS_vidSET(EngLim_tqCkEfcChaLim, s16LocalEngLim_tqCkEfcCha);

   VEMS_vidGET(EngLim_tqCkEfcModSptLim, s16LocalEngLim_tqCkEfcModSptLim);

   if (EngLim_bProtDfltModSptSel_C != 0)
   {
      VEMS_vidGET(CoPt_tqEfcMaxProtDftl, s16LocalCoPt_tqEfcMaxProtDftl);
      s16LocalEngLim_tqCkEfcModSptLim =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcModSptLim,
                                s16LocalCoPt_tqEfcMaxProtDftl);
   }
   else
   {
      s16LocalEngLim_tqCkEfcModSptLim =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqCkEfcModSptLim, 32000);
   }
   s16LocalEngLim_tqCkEfcModSptLim =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkEfcModSptLim, -32000, 32000);
   VEMS_vidSET(EngLim_tqCkEfcModSptLim, s16LocalEngLim_tqCkEfcModSptLim);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_BVAuto_1                              */
/* !Description :  Réinitialisation du filtre de niveau 1 de la stratégie     */
/*                 d’agrément curatif.                                        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_BVAuto_1_2(argin sint16             */
/* s16GbxBVAuto_1_2);                                                         */
/*  input uint8 EngLim_idxCoPtLim_C;                                          */
/*  input sint16 EngLim_tqEfcEngProt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_BVAuto_1
(
   sint16 s16TqSys1,
   sint16 s16TqSys2,
   sint16 s16TqSys3
)
{
   sint16 s16LocalGbx;
   sint16 s16LocalEngLim_tqEfcEngProt;


   s16LocalGbx = 32000;
   if ((EngLim_idxCoPtLim_C & 0x1) != 0)
   {
      s16LocalGbx = (sint16)MATHSRV_udtMIN(s16TqSys1, s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x2) != 0)
   {
      s16LocalGbx = (sint16)MATHSRV_udtMIN(s16TqSys2, s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x4) != 0)
   {
      s16LocalGbx = (sint16)MATHSRV_udtMIN(s16TqSys3, s16LocalGbx);
   }
   if ((EngLim_idxCoPtLim_C & 0x8) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcEngProt, s16LocalEngLim_tqEfcEngProt);
      s16LocalGbx =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcEngProt, s16LocalGbx);
   }
   ENGLIMEFCCORD_vidLim_BVAuto_1_2(s16LocalGbx);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_BVAuto_2                              */
/* !Description :  La deuxième limitation pour la fonction BVA/BVMP est       */
/*                 configurée en fonction de la valeur de EngLim_CoPtLimTyp2_C*/
/*                 correspondant à la somme des valeurs couples de limitation */
/*                 à utiliser.                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_BVAuto_2_2(argin sint16             */
/* s16ATBVAuto_2_2);                                                          */
/*  input uint8 EngLim_idxCoPtLimAT_C;                                        */
/*  input sint16 EngLim_tqEfcEngProt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_BVAuto_2
(
   sint16 s16TqSys1,
   sint16 s16TqSys2,
   sint16 s16TqSys3
)
{
   sint16 s16LocalAT;
   sint16 s16LocalEngLim_tqEfcEngProt;


   s16LocalAT = 32000;
   if ((EngLim_idxCoPtLimAT_C & 0x1) != 0)
   {
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16TqSys1, s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x2) != 0)
   {
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16TqSys2, s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x4) != 0)
   {
      s16LocalAT = (sint16)MATHSRV_udtMIN(s16TqSys3, s16LocalAT);
   }
   if ((EngLim_idxCoPtLimAT_C & 0x8) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcEngProt, s16LocalEngLim_tqEfcEngProt);
      s16LocalAT =
         (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcEngProt, s16LocalAT);
   }
   ENGLIMEFCCORD_vidLim_BVAuto_2_2(s16LocalAT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_ESP                                   */
/* !Description :  La deuxième limitation pour la fonction ESP est configurée */
/*                 en fonction de la valeur de EngLim_ChaLim_C correspondant à*/
/*                 la somme des valeurs couples de limitation à utiliser.     */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_ESP1(argin sint16 s16tqEfcESP1);    */
/*  input uint8 EngLim_idxChaLim_C;                                           */
/*  input sint16 EngLim_tqEfcEngProt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_ESP
(
   sint16 s16TqSys1,
   sint16 s16TqSys2,
   sint16 s16TqSys3
)
{
   sint16 s16LocalChaLim;
   sint16 s16LocalEngLim_tqEfcEngProt;


   s16LocalChaLim = 32000;
   if ((EngLim_idxChaLim_C & 0x1) != 0)
   {
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16TqSys1, s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x2) != 0)
   {
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16TqSys2, s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x4) != 0)
   {
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16TqSys3, s16LocalChaLim);
   }
   if ((EngLim_idxChaLim_C & 0x8) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcEngProt, s16LocalEngLim_tqEfcEngProt);
      s16LocalChaLim = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcEngProt,
                                              s16LocalChaLim);
   }
   ENGLIMEFCCORD_vidLim_ESP1(s16LocalChaLim);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLim_ModSpt                                */
/* !Description :  La deuxième limitation pour la fonction superviseur du mode*/
/*                 sport est configurée en fonction de la valeur de           */
/*                 EngLim_idxModSptLim_C correspondant à la somme des valeurs */
/*                 couples de limitation à utiliser.                          */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  Arslen.Memi                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void ENGLIMEFCCORD_vidLim_ModSpt1(argin sint16                */
/* s16tqEfcModSpt1);                                                          */
/*  input uint8 EngLim_idxModSptLim_C;                                        */
/*  input sint16 EngLim_tqEfcEngProt;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLim_ModSpt
(
   sint16 s16TqSys1,
   sint16 s16TqSys2,
   sint16 s16TqSys3
)
{
   sint16 s16LocalModSpt;
   sint16 s16LocalEngLim_tqEfcEngProt;


   s16LocalModSpt = 32000;
   if ((EngLim_idxModSptLim_C & 0x1) != 0)
   {
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16TqSys1, s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x2) != 0)
   {
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16TqSys2, s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x4) != 0)
   {
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16TqSys3, s16LocalModSpt);
   }
   if ((EngLim_idxModSptLim_C & 0x8) != 0)
   {
      VEMS_vidGET(EngLim_tqEfcEngProt, s16LocalEngLim_tqEfcEngProt);
      s16LocalModSpt = (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcEngProt,
                                              s16LocalModSpt);
   }
   ENGLIMEFCCORD_vidLim_ModSpt1(s16LocalModSpt);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  ENGLIMEFCCORD_vidLimit_Divers                              */
/* !Description :  D’autre limitations pour les fonctions divers (Clim, xVV et*/
/*                 regulation de régime en aide décollage) sont calculées ici.*/
/* !Number      :  FCT1.10                                                    */
/* !Author      :  Arslen.Memi                                                */
/* !Trace_To    :  VEMS_R_10_03267_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bTypFu;                                               */
/*  input sint16 EngLim_tqEfcEngProt;                                         */
/*  input sint16 EngLim_tqCkEfcStatLim;                                       */
/*  input sint16 EngLim_tqEfcSyst;                                            */
/*  input sint16 EngLim_tqEfcRed;                                             */
/*  input sint16 EngLim_tqEfcSfty;                                            */
/*  input sint16 CoPt_tqEfcMaxProtDftl;                                       */
/*  input sint16 ThMgt_tqEfcLimAntiBoilProt;                                  */
/*  input sint16 EngLim_tqEfcPresUsThrMax;                                    */
/*  input sint16 EngLim_tqEfcLdMaxTrbMax;                                     */
/*  input sint16 EngLim_tqEfcEngCurMax;                                       */
/*  input sint16 EngLim_tqCkEfcFLdLim;                                        */
/*  input sint16 EngLim_tqCkEfcLim;                                           */
/*  output sint16 EngLim_tqCkEfcACCmprLim;                                    */
/*  output sint16 EngLim_tqEfcMaxDynVehSpdCtl;                                */
/*  output sint16 EngLim_tqEfcMaxStatVehSpdCtl;                               */
/*  output sint16 EngLim_tqEfcNRegTakeOffLim;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void ENGLIMEFCCORD_vidLimit_Divers(void)
{
   boolean  bLocalTqSys_bTypFu;
   sint16   s16LocalEngLim_tqEfcPresUsThrMax;
   sint16   s16LocalEngLim_tqCkEfcFLdLim;
   sint16   s16LocalEngLim_tqEfcLdMaxTrbMax;
   sint16   s16LocalEngLim_tqEfcEngCurMax;
   sint16   s16LocalEngLim_tqCkEfcLim;
   sint16   s16LocalEngLim_tqCkEfcACCmprLim;
   sint16   s16LocalEngLim_tqEfcNRegTakeOf;
   sint16   s16LocalEngLim_tqEfcMaxMin;
   sint16   s16LocalEngLim_tqEfcMaxStatMin;
   sint16   s16LocalEngLim_tqEfcEngProt;
   sint16   s16LocalEngLim_tqCkEfcStatLim;
   sint16   s16LocalEngLim_tqEfcSyst;
   sint16   s16LocalEngLim_tqEfcRed;
   sint16   s16LocalEngLim_tqEfcSfty;
   sint16   s16LocalCoPt_tqEfcMaxProtDftl;
   sint16   s16LocalThMgt_tqEfcLimAntiBoilPr;
   sint16   s16LocalEngLim_tqEfcMaxDynVehSpd;


   VEMS_vidGET(TqSys_bTypFu,bLocalTqSys_bTypFu);
   VEMS_vidGET(EngLim_tqEfcEngProt,s16LocalEngLim_tqEfcEngProt);
   VEMS_vidGET(EngLim_tqCkEfcStatLim,s16LocalEngLim_tqCkEfcStatLim);
   VEMS_vidGET(EngLim_tqEfcSyst,s16LocalEngLim_tqEfcSyst);
   VEMS_vidGET(EngLim_tqEfcRed,s16LocalEngLim_tqEfcRed);
   VEMS_vidGET(EngLim_tqEfcSfty,s16LocalEngLim_tqEfcSfty);
   VEMS_vidGET(CoPt_tqEfcMaxProtDftl,s16LocalCoPt_tqEfcMaxProtDftl);
   VEMS_vidGET(ThMgt_tqEfcLimAntiBoilProt,s16LocalThMgt_tqEfcLimAntiBoilPr);

   if (bLocalTqSys_bTypFu != 0)
   {
      VEMS_vidGET(EngLim_tqEfcPresUsThrMax,s16LocalEngLim_tqEfcPresUsThrMax);
      s16LocalEngLim_tqCkEfcACCmprLim = s16LocalEngLim_tqEfcPresUsThrMax;
      VEMS_vidGET(EngLim_tqEfcLdMaxTrbMax,s16LocalEngLim_tqEfcLdMaxTrbMax);
      s16LocalEngLim_tqEfcNRegTakeOf = s16LocalEngLim_tqEfcLdMaxTrbMax;
      VEMS_vidGET(EngLim_tqEfcEngCurMax,s16LocalEngLim_tqEfcEngCurMax);
      s16LocalEngLim_tqEfcMaxMin = s16LocalEngLim_tqEfcEngCurMax;
   }
   else
   {
      VEMS_vidGET(EngLim_tqCkEfcFLdLim,s16LocalEngLim_tqCkEfcFLdLim);
      s16LocalEngLim_tqCkEfcACCmprLim =  s16LocalEngLim_tqCkEfcFLdLim;
      s16LocalEngLim_tqEfcNRegTakeOf =  s16LocalEngLim_tqCkEfcFLdLim;
      VEMS_vidGET(EngLim_tqCkEfcLim,s16LocalEngLim_tqCkEfcLim);
      s16LocalEngLim_tqEfcMaxMin = s16LocalEngLim_tqCkEfcLim;
   }
   s16LocalEngLim_tqCkEfcACCmprLim =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqCkEfcACCmprLim, -32000, 32000);
   VEMS_vidSET(EngLim_tqCkEfcACCmprLim, s16LocalEngLim_tqCkEfcACCmprLim);

   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcEngProt,
                             s16LocalEngLim_tqCkEfcStatLim);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                             s16LocalEngLim_tqEfcSyst);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                             s16LocalEngLim_tqEfcRed);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                             s16LocalEngLim_tqEfcSfty);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                             s16LocalCoPt_tqEfcMaxProtDftl);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                             s16LocalThMgt_tqEfcLimAntiBoilPr);
   s16LocalEngLim_tqEfcMaxMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxMin,
                             s16LocalEngLim_tqEfcMaxStatMin);
   s16LocalEngLim_tqEfcMaxDynVehSpd =
      (sint16)MATHSRV_udtCLAMP( s16LocalEngLim_tqEfcMaxMin , -32000, 32000);
   VEMS_vidSET(EngLim_tqEfcMaxDynVehSpdCtl, s16LocalEngLim_tqEfcMaxDynVehSpd);

   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtMIN(s16LocalEngLim_tqEfcMaxStatMin,
                              s16LocalEngLim_tqEfcNRegTakeOf);
   s16LocalEngLim_tqEfcMaxStatMin =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqEfcMaxStatMin, -32000, 32000);
   VEMS_vidSET(EngLim_tqEfcMaxStatVehSpdCtl, s16LocalEngLim_tqEfcMaxStatMin);

   s16LocalEngLim_tqEfcNRegTakeOf =
      (sint16)MATHSRV_udtCLAMP(s16LocalEngLim_tqEfcNRegTakeOf, -32000, 32000);
   VEMS_vidSET(EngLim_tqEfcNRegTakeOffLim, s16LocalEngLim_tqEfcNRegTakeOf);

}

/*------------------------------- end of file --------------------------------*/