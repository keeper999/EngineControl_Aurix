/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TARIDLSTA                                               */
/* !Description     : TARIDLSTA component.                                    */
/*                                                                            */
/* !Module          : TARIDLSTA                                               */
/* !Description     : Consigne de Ralenti Statique                            */
/*                                                                            */
/* !File            : TARIDLSTA_FCT1.C                                        */
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
/*   1 / TARIDLSTA_vidInitOutput                                              */
/*   2 / TARIDLSTA_vidCalc_Idlle_target                                       */
/*   3 / TARIDLSTA_vidCalc_Idl_trq_req                                        */
/*   4 / TARIDLSTA_vidCalc_Idl_target_max                                     */
/*   5 / TARIDLSTA_vidCalc_info                                               */
/*   6 / TARIDLSTA_vidCalc_Idl_tar_fault                                      */
/*   7 / TARIDLSTA_vidCalc_Idl_tar_normal                                     */
/*   8 / TARIDLSTA_vidCalcTarNorSlewInput                                     */
/*   9 / TARIDLSTA_vidCalc_Idl_tar_engine                                     */
/*   10 / TARIDLSTA_vidCalc_Idl_tar_Dsl                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 08533 / 02                                        */
/* !OtherRefs   : CSMT_CGMT06_2104 / 10.3                                     */
/* !OtherRefs   : VEMS V02 ECU#051848                                         */
/* !OtherRefs   : VEMS V02 ECU#059717                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TARIDLSTA/TARIDLS$*/
/* $Revision::   1.10     $$Author::   mbenfrad       $$Date::   11 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   11 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TARIDLSTA.h"
#include "TARIDLSTA_L.h"
#include "TARIDLSTA_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des variables produites par la   */
/*                 spec.                                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void TARIDLSTA_vidCalcTarNorSlewInput();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqSys_nTarIdlIni_C;                                          */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  input uint16 TARIDLSTA_u16NormSlewInput;                                  */
/*  input uint16 TARIDLSTA_u16NeutSlewInput;                                  */
/*  input uint16 TqCmp_tqACLoss;                                              */
/*  input uint16 TqSys_tqACFilTarIdl_MP;                                      */
/*  input sint16 TqCmp_tqAltLoss;                                             */
/*  input sint16 TqSys_tqAltFilTarIdl_MP;                                     */
/*  input uint16 TqSys_nTarIdlNorm;                                           */
/*  output boolean TqSys_bIdlClcReq;                                          */
/*  output uint16 TqSys_nTarIdl;                                              */
/*  output uint16 TqSys_nTarIdlFil;                                           */
/*  output uint16 TqSys_nTarIdlNeut;                                          */
/*  output uint16 TqSys_nTarIdlAT;                                            */
/*  output uint16 TqSys_nTarIdlDsl;                                           */
/*  output uint16 TqSys_nTarIdlGsl;                                           */
/*  output uint16 TqSys_nTarIdlPrev;                                          */
/*  output boolean TARIDLSTA_bIdlTarExtRisingEdge;                            */
/*  output boolean TARIDLSTA_bPosHysNeutOut;                                  */
/*  output uint8 TqSys_noGearTarIdl;                                          */
/*  output boolean TARIDLSTA_bPosHysLihPedOut;                                */
/*  output boolean TqSys_bAcvTarIdlLihPed_MP;                                 */
/*  output boolean TqSys_bAcvTarIdlSpdLim_MP;                                 */
/*  output uint16 TARIDLSTA_u16LihPedSlewOut;                                 */
/*  output uint16 TARIDLSTA_u16EngSpdLimSlewOut;                              */
/*  output boolean TqSys_stTarIdlNorm_MP;                                     */
/*  output uint16 TqSys_nTarIdlNorm;                                          */
/*  output uint16 TARIDLSTA_u16NeutSlewOut;                                   */
/*  output boolean TqSys_bAcvTarIdlCanPurg_MP;                                */
/*  output uint16 TqSys_nTarIdlCanPurg;                                       */
/*  output boolean TARIDLSTA_bTarIdlACFlipFlopOut;                            */
/*  output boolean TqSys_bAcvTarIdlAC_MP;                                     */
/*  output boolean TARIDLSTA_bNegHysTarIdlAC;                                 */
/*  output uint16 TqSys_nTarIdlAC;                                            */
/*  output uint16 TqSys_tqACFilTarIdl_MP;                                     */
/*  output uint32 TARIDLSTA_u32TqACFilTarIdlMem;                              */
/*  output boolean TARIDLSTA_bTarIdlAltFlipFlopOut;                           */
/*  output boolean TqSys_bAcvTarIdlAltCmpReq_MP;                              */
/*  output boolean TqSys_bAcvSpdCdnTarIdlAlt;                                 */
/*  output uint16 TqSys_nTarIdlAlt;                                           */
/*  output sint16 TqSys_tqAltFilTarIdl_MP;                                    */
/*  output sint32 TARIDLSTA_s32TqAltFilTarIdlMem;                             */
/*  output boolean TARIDLSTA_bEngAsiReqTrvPrev;                               */
/*  output uint16 TqSys_nTarIdlUH;                                            */
/*  output uint16 TqSys_ctTarIdlBatt_MP;                                      */
/*  output boolean TqSys_stTarIdlBatt_MP;                                     */
/*  output boolean TqSys_bAcvTarIdlBatt_MP;                                   */
/*  output uint16 TqSys_nTarIdlBatt;                                          */
/*  output boolean TARIDLSTA_bTarIdlWaHtFlipFlopOut;                          */
/*  output boolean TqSys_bAcvTarIdlWaHt_MP;                                   */
/*  output uint16 TqSys_nTarIdlWaHt;                                          */
/*  output boolean TARIDLSTA_bTurnOffDlyStgPmp;                               */
/*  output boolean TqSys_bAcvTarIdlStgPmp_MP;                                 */
/*  output uint16 TqSys_nTarIdlStgPmp;                                        */
/*  output boolean TARIDLSTA_bPosHysGBxOut;                                   */
/*  output boolean TqSys_bAcvTarIdlATBas_MP;                                  */
/*  output uint16 TqSys_nTarIdlATBas;                                         */
/*  output boolean TqSys_bAcvTarIdlATInc_MP;                                  */
/*  output uint16 TqSys_nTarIdlATInc;                                         */
/*  output boolean TARIDLSTA_bTurnOffDlyRisingEdge;                           */
/*  output boolean TqSys_bAcvTarIdlATEgd_MP;                                  */
/*  output uint16 TqSys_nTarIdlATEgd;                                         */
/*  output boolean TARIDLSTA_bATCunFlipFlopOut;                               */
/*  output uint16 TqSys_nTarIdlSfty;                                          */
/*  output boolean TARIDLSTA_bEnableRateLimiter;                              */
/*  output boolean TqSys_bAcvTarIdlVacPmp_MP;                                 */
/*  output uint16 TqSys_nTarIdlVacPmp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidInitOutput(void)
{
   uint16 u16LocalTarIdlIni;
   uint16 u16LocalTqCmp_tqACLoss;
   sint16 s16LocalTqCmp_tqAltLoss;


   /*Output initialization*/
   u16LocalTarIdlIni = (uint16)MATHSRV_udtMIN(TqSys_nTarIdlIni_C, 8000);
   u16LocalTarIdlIni = (uint16)(u16LocalTarIdlIni * 4);

   VEMS_vidSET(TqSys_bIdlClcReq, 1);
   VEMS_vidSET(TqSys_nTarIdl, u16LocalTarIdlIni);
   VEMS_vidSET(TqSys_nTarIdlFil, u16LocalTarIdlIni);
   VEMS_vidSET(TqSys_nTarIdlNeut, u16LocalTarIdlIni);

   /*Intenal variables initialization*/
   VEMS_vidSET(TqSys_nTarIdlAT, 0);
   TqSys_nTarIdlDsl = 0;
   TqSys_nTarIdlGsl = 0;

   /*F03_Calc_idle_target_ext*/
   TqSys_nTarIdlPrev = u16LocalTarIdlIni;
   TARIDLSTA_bIdlTarExtRisingEdge = 0;

   /*F02_01_Calc_info*/
   TARIDLSTA_bPosHysNeutOut = 0;
   TqSys_noGearTarIdl = 0;

   /*F02_02_Calc_Idle_target_fault*/
   TARIDLSTA_bPosHysLihPedOut = 0;
   TqSys_bAcvTarIdlLihPed_MP = 0;
   TqSys_bAcvTarIdlSpdLim_MP = 0;
   TARIDLSTA_u16LihPedSlewOut = TqSys_nTarIdlPrev;
   TARIDLSTA_u16EngSpdLimSlewOut = TqSys_nTarIdlPrev;

   /*F02_03_Calc_Idle_target_normal*/
   TqSys_stTarIdlNorm_MP = 0;
   TARIDLSTA_vidCalcTarNorSlewInput();
   TqSys_nTarIdlNorm =
      (uint16)MATHSRV_udtMIN(TARIDLSTA_u16NormSlewInput, 32000);
   TARIDLSTA_u16NeutSlewOut =
      (uint16)MATHSRV_udtMIN(TARIDLSTA_u16NeutSlewInput, 32000);

   /*F02_03_02_01_Calc_Idle_target_Canister*/
   TqSys_bAcvTarIdlCanPurg_MP = 0;
   TqSys_nTarIdlCanPurg = TqSys_nTarIdlPrev;

   /*F02_04_02_Calc_Idle_target_ac*/
   TARIDLSTA_bTarIdlACFlipFlopOut = 0;
   TqSys_bAcvTarIdlAC_MP = 0;
   TARIDLSTA_bNegHysTarIdlAC = 0;
   TqSys_nTarIdlAC = TqSys_nTarIdlPrev;

   VEMS_vidGET(TqCmp_tqACLoss, u16LocalTqCmp_tqACLoss);
   TqSys_tqACFilTarIdl_MP =
      (uint16)MATHSRV_udtMIN(u16LocalTqCmp_tqACLoss, 8000);
   TARIDLSTA_u32TqACFilTarIdlMem =(uint32)(TqSys_tqACFilTarIdl_MP * 65536);

   /*F02_04_03_Calc_Idle_target_alt_sup*/
   TARIDLSTA_bTarIdlAltFlipFlopOut = 0;
   TqSys_bAcvTarIdlAltCmpReq_MP = 0;
   TqSys_bAcvSpdCdnTarIdlAlt = 0;
   TqSys_nTarIdlAlt = TqSys_nTarIdlPrev;

   VEMS_vidGET(TqCmp_tqAltLoss, s16LocalTqCmp_tqAltLoss);
   TqSys_tqAltFilTarIdl_MP =
      (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqAltLoss, -32000, 32000);
   TARIDLSTA_s32TqAltFilTarIdlMem = (sint32)(TqSys_tqAltFilTarIdl_MP * 65536);

   /*F02_04_04_Calc_Idle_target_UH*/
   TARIDLSTA_bEngAsiReqTrvPrev = 0;
   TqSys_nTarIdlUH = TqSys_nTarIdlPrev;

   /*F02_04_05_Calc_Idle_target_low_bat*/
   TqSys_ctTarIdlBatt_MP = 0;
   TqSys_stTarIdlBatt_MP = 0;
   TqSys_bAcvTarIdlBatt_MP = 0;
   TqSys_nTarIdlBatt = TqSys_nTarIdlPrev;

   /*F02_04_06_Calc_Idle_target_thp*/
   TARIDLSTA_bTarIdlWaHtFlipFlopOut = 0;
   TqSys_bAcvTarIdlWaHt_MP = 0;
   TqSys_nTarIdlWaHt = TqSys_nTarIdlPrev;

   /*F02_04_07_Calc_Idle_target_ss*/
   TARIDLSTA_bTurnOffDlyStgPmp = 0;
   TqSys_bAcvTarIdlStgPmp_MP = 0;
   TqSys_nTarIdlStgPmp = TqSys_nTarIdlPrev;

   /*F02_05_02_Calc_Idle_target_AT_base*/
   TARIDLSTA_bPosHysGBxOut = 0;
   TqSys_bAcvTarIdlATBas_MP = 0;
   TqSys_nTarIdlATBas = TqSys_nTarIdlPrev;

   /*F02_05_03_Calc_Idle_target_AT_increased */
   TqSys_bAcvTarIdlATInc_MP = 0;
   TqSys_nTarIdlATInc = TqSys_nTarIdlPrev;

   /*F02_05_04_Freeze_Idle_target_AT_engaged*/
   TARIDLSTA_bTurnOffDlyRisingEdge = 0;
   TqSys_bAcvTarIdlATEgd_MP = 0;
   TqSys_nTarIdlATEgd = TqSys_nTarIdlNorm;

   /*F02_05_05_Calc_Idle_target_AT_Cunsumtion*/
   TARIDLSTA_bATCunFlipFlopOut = 0;

   /*F02_07_Calc_Idle_target*/
   VEMS_vidSET(TqSys_nTarIdlSfty, u16LocalTarIdlIni);

   /*F02_04_08_Calc_Idle_target_vaccum_pump */
   TARIDLSTA_bEnableRateLimiter = 0;
   TqSys_bAcvTarIdlVacPmp_MP = 0;
   TqSys_nTarIdlVacPmp = TqSys_nTarIdlPrev;

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idlle_target                             */
/* !Description :  La fonction de consigne de régime de ralenti se décompose  */
/*                 en 3 sous-blocs : Calcul de l’activation de la régulation  */
/*                 de ralenti, Calcul de la consigne de régime de ralenti, de */
/*                 by-pass de la consigne de régime de ralenti pour des       */
/*                 besoins extérieurs.                                        */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalc_Idl_trq_req();                         */
/*  extf argret void TARIDLSTA_vidCalc_Idl_target_max();                      */
/*  extf argret void TARIDLSTA_vidCalc_idl_target_ext();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idlle_target(void)
{
   /*F01_Calc_Idle_trq_calc_req*/
   TARIDLSTA_vidCalc_Idl_trq_req();

   /*F02_Calc_Idle_target_max*/
   TARIDLSTA_vidCalc_Idl_target_max();

   /*F03_Calc_idle_target_ext*/
   TARIDLSTA_vidCalc_idl_target_ext();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_trq_req                              */
/* !Description :  Le flag de sortie de ce bloc peut être utilisé pour arrêter*/
/*                 le contrôleur de ralenti à haut régime, mais c’est         */
/*                 optionnel. 2 seuils de régime sont utilisés pour éviter des*/
/*                 oscillations à la limite entre la zone de ralenti et la    */
/*                 zone hors ralenti.                                         */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqSys_nOfsHiIdlClc_C;                                        */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  input uint16 TqSys_nOfsLoIdlClc_C;                                        */
/*  output boolean TqSys_bIdlClcReq;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_trq_req(void)
{
   uint16 u16LocalEng_nCkFil;
   uint32 u32LocalNegHysHigh;
   uint32 u32LocalNegHysLow;


   /*NegHys*/
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u32LocalNegHysHigh =
      (uint32)((4 * TqSys_nOfsHiIdlClc_C) + TqSys_nTarIdlPrev);

   if (u16LocalEng_nCkFil >= u32LocalNegHysHigh)
   {
      VEMS_vidSET(TqSys_bIdlClcReq, 0);
   }
   else
   {
      u32LocalNegHysLow =
         (uint32)((4 * TqSys_nOfsLoIdlClc_C) + TqSys_nTarIdlPrev);
      if (u16LocalEng_nCkFil <= u32LocalNegHysLow)
      {
         VEMS_vidSET(TqSys_bIdlClcReq, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_target_max                           */
/* !Description :  Dans ce bloc, on calcule les différents régimes cible de   */
/*                 ralenti en fonction : des erreurs systèmes, des            */
/*                 consommateurs, de la température d’eau moteur, du rapport  */
/*                 de boite, de la pression atmosphérique, des requêtes       */
/*                 externes.                                                  */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalc_info();                                */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_fault();                       */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_normal();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_engine();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_consum();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_AT();                          */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar();                             */
/*  input uint8 Ext_stGBxCf;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_target_max(void)
{
   uint8 u8LocalExt_stGBxCf;


   /*F02_01_Calc_info*/
   TARIDLSTA_vidCalc_info();

   /*F02_02_Calc_Idle_target_fault*/
   TARIDLSTA_vidCalc_Idl_tar_fault();

   /*F02_03_Calc_Idle_target_normal*/
   TARIDLSTA_vidCalc_Idl_tar_normal();

   /*F02_04_Calc_Idle_target_engine*/
   TARIDLSTA_vidCalc_Idl_tar_engine();

   /*F02_05_Calc_Idle_target_consumer_targets*/
   TARIDLSTA_vidCalc_Idl_tar_consum();

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   if (u8LocalExt_stGBxCf == 1)
   {
      /*F02_06_Calc_Idle_target_AT*/
      TARIDLSTA_vidCalc_Idl_tar_AT();
   }

   /*F02_07_Calc_Idle_target*/
   TARIDLSTA_vidCalc_Idl_tar();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_info                                     */
/* !Description :  Ce bloc calcule le rapport de boite en ajoutant le cas     */
/*                 neutre roulant pour la BVM, et en prenant en compte les    */
/*                 états boîte pour les BVA/BVMP. Ce bloc calcule aussi la    */
/*                 valeur de l’appui frein interne à la fonction.             */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqSys_spdThdNeutLo_C;                                         */
/*  input uint8 TqSys_spdThdNeutHi_C;                                         */
/*  input boolean CoBrk_bAcvBrk;                                              */
/*  input boolean TARIDLSTA_bPosHysNeutOut;                                   */
/*  input uint8 TqSys_noGearTarIdlDft_C;                                      */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean CoPt_bTqTx;                                                 */
/*  input uint8 CoPt_stCpl;                                                   */
/*  output boolean TARIDLSTA_bPosHysNeutOut;                                  */
/*  output boolean TqSys_bAcvBrkTarIdl;                                       */
/*  output uint8 TqSys_noGearTarIdl;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_info(void)
{
   boolean bLocalCoBrk_bAcvBrk;
   boolean blocalAcvGearTarIdlDft;
   boolean bLocalCoPt_bTqTx;
   boolean bLocalCoPt_stCpl;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalPosHysHigh;
   uint16  u16LocalPosHysLow;


   /*PosHys*/
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalPosHysLow = (uint16)(TqSys_spdThdNeutLo_C * 64);

   if (u16LocalVeh_spdVeh <= u16LocalPosHysLow)
   {
      TARIDLSTA_bPosHysNeutOut = 0;
   }
   else
   {
      u16LocalPosHysHigh = (uint16)(TqSys_spdThdNeutHi_C * 64);
      if (u16LocalVeh_spdVeh >= u16LocalPosHysHigh)
      {
         TARIDLSTA_bPosHysNeutOut = 1;
      }
   }

   /*Production of TqSys_bAcvBrkTarIdl*/
   VEMS_vidGET(CoBrk_bAcvBrk, bLocalCoBrk_bAcvBrk);
   if (  (bLocalCoBrk_bAcvBrk != 0)
      && (TARIDLSTA_bPosHysNeutOut != 0))
   {
      TqSys_bAcvBrkTarIdl = 1;
   }
   else
   {
      TqSys_bAcvBrkTarIdl = 0;
   }

   /*Production of TqSys_noGearTarIdl*/
   blocalAcvGearTarIdlDft = GDGAR_bGetFRM(FRM_FRM_ACVGEARTARIDLDFT);
   if (blocalAcvGearTarIdlDft != 0)
   {
      TqSys_noGearTarIdl = (uint8)MATHSRV_udtMIN(TqSys_noGearTarIdlDft_C, 8);
   }
   else
   {
      VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
      VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);

      if (u8LocalExt_stGBxCf == 0)
      {
         if (  (u8LocalCoPt_noEgdGearCord == 0)
            && (TARIDLSTA_bPosHysNeutOut != 0))
         {
            TqSys_noGearTarIdl = 8;
         }
         else
         {
            TqSys_noGearTarIdl =
               (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 8);
         }
      }
      else
      {
         VEMS_vidGET(CoPt_bTqTx, bLocalCoPt_bTqTx);
         if (bLocalCoPt_bTqTx != 0)
         {
            VEMS_vidGET(CoPt_stCpl, bLocalCoPt_stCpl);
            switch(bLocalCoPt_stCpl)
            {
               case 0:
               case 1:
                  TqSys_noGearTarIdl = 0;
                  break;

               case 2:
               case 3:
                  TqSys_noGearTarIdl =
                     (uint8)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 8);
                  break;

               default:
                  SWFAIL_vidSoftwareErrorHook();
                  break;
            }
         }
         else
         {
            TqSys_noGearTarIdl = 0;
         }
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_fault                            */
/* !Description :  Ce bloc calcule la consigne de régime de ralenti en cas de */
/*                 mode dégradé.                                              */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqSys_spdThdLoLihPed_C;                                       */
/*  input uint8 TqSys_spdThdHiLihPed_C;                                       */
/*  input boolean TqSys_bAcvTarIdlLihPed_MP;                                  */
/*  input boolean CoBrk_bAcvBrk;                                              */
/*  input boolean TARIDLSTA_bPosHysLihPedOut;                                 */
/*  input uint16 TqSys_nTarIdlLihPedRunBrk_C;                                 */
/*  input uint16 TqSys_nTarIdlLihPedRun_C;                                    */
/*  input uint16 TqSys_nTarIdlLihPedStopBrk_C;                                */
/*  input uint16 TqSys_nTarIdlLihPedStop_C;                                   */
/*  input uint16 TqSys_nIncTarIdlLihPed_C;                                    */
/*  input sint16 TqSys_nDecTarIdlLihPed_C;                                    */
/*  input uint16 TARIDLSTA_u16LihPedSlewOut;                                  */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  input boolean TqSys_bAcvTarIdlSpdLim_MP;                                  */
/*  input uint16 TqSys_nTarIdlEngSpdLim_C;                                    */
/*  input uint16 TqSys_nIncTarIdlEngSpdLim_C;                                 */
/*  input sint16 TqSys_nDecTarIdlEngSpdLim_C;                                 */
/*  input uint16 TARIDLSTA_u16EngSpdLimSlewOut;                               */
/*  output boolean TARIDLSTA_bPosHysLihPedOut;                                */
/*  output boolean TqSys_bAcvTarIdlLihPed_MP;                                 */
/*  output uint16 TARIDLSTA_u16LihPedSlewOut;                                 */
/*  output boolean TqSys_bAcvTarIdlSpdLim_MP;                                 */
/*  output uint16 TARIDLSTA_u16EngSpdLimSlewOut;                              */
/*  output uint16 TqSys_nTarIdlDft;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_fault(void)
{
   boolean bLocalAcvIrvLihPed;
   boolean bLocalAcvRvLihPed;
   boolean bLocalAcvRvVstLihPed;
   boolean bLocalCoBrk_bAcvBrk;
   boolean bLocalAcvTarIdlLihPedPrev;
   boolean bLocalEngSpdLimHiIntv;
   boolean bLocalEngSpdLimLoIntv;
   boolean bLocalAcvTarIdlSpdLimPrev;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalPosHysHigh;
   uint16  u16LocalPosHysLow;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalSlewDec;


   /*PosHys*/
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalPosHysLow = (uint16)(TqSys_spdThdLoLihPed_C * 64);

   if (u16LocalVeh_spdVeh <= u16LocalPosHysLow)
   {
      TARIDLSTA_bPosHysLihPedOut = 0;
   }
   else
   {
      u16LocalPosHysHigh = (uint16)(TqSys_spdThdHiLihPed_C * 64);
      if (u16LocalVeh_spdVeh >= u16LocalPosHysHigh)
      {
         TARIDLSTA_bPosHysLihPedOut = 1;
      }
   }

   /*Rate Limiter1*/
   bLocalAcvIrvLihPed = GDGAR_bGetFRM(FRM_FRM_ACVIRVLIHPED);
   bLocalAcvRvLihPed = GDGAR_bGetFRM(FRM_FRM_ACVRVLIHPED);
   bLocalAcvRvVstLihPed = GDGAR_bGetFRM(FRM_FRM_ACVRVVSTLIHPED);

   bLocalAcvTarIdlLihPedPrev = TqSys_bAcvTarIdlLihPed_MP;
   if (  (bLocalAcvIrvLihPed != 0)
      || (bLocalAcvRvLihPed != 0)
      || (bLocalAcvRvVstLihPed != 0))
   {
      TqSys_bAcvTarIdlLihPed_MP = 1;
      VEMS_vidGET(CoBrk_bAcvBrk, bLocalCoBrk_bAcvBrk);
      if (TARIDLSTA_bPosHysLihPedOut != 0)
      {
         if (bLocalCoBrk_bAcvBrk != 0)
         {
            u16LocalSlewInput = TqSys_nTarIdlLihPedRunBrk_C;
         }
         else
         {
            u16LocalSlewInput = TqSys_nTarIdlLihPedRun_C;
         }
      }
      else
      {
         if (bLocalCoBrk_bAcvBrk != 0)
         {
            u16LocalSlewInput = TqSys_nTarIdlLihPedStopBrk_C;
         }
         else
         {
            u16LocalSlewInput = TqSys_nTarIdlLihPedStop_C;
         }
      }
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      TqSys_bAcvTarIdlLihPed_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlLihPedPrev != 0)
      || (TqSys_bAcvTarIdlLihPed_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlLihPed_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlLihPed_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TARIDLSTA_u16LihPedSlewOut,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TARIDLSTA_u16LihPedSlewOut =
      (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);

   /*Rate Limiter2*/
   bLocalEngSpdLimHiIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMHIINTV);
   bLocalEngSpdLimLoIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMLOINTV);

   bLocalAcvTarIdlSpdLimPrev = TqSys_bAcvTarIdlSpdLim_MP;
   if (  (bLocalEngSpdLimHiIntv != 0)
      || (bLocalEngSpdLimLoIntv != 0))
   {
      TqSys_bAcvTarIdlSpdLim_MP = 1;
      u16LocalSlewInput =
         (uint16)MATHSRV_udtMIN(TqSys_nTarIdlEngSpdLim_C, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      TqSys_bAcvTarIdlSpdLim_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlSpdLimPrev != 0)
      || (TqSys_bAcvTarIdlSpdLim_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlEngSpdLim_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlEngSpdLim_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TARIDLSTA_u16EngSpdLimSlewOut,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TARIDLSTA_u16EngSpdLimSlewOut =
      (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);

   TqSys_nTarIdlDft = (uint16)MATHSRV_udtMAX(TARIDLSTA_u16LihPedSlewOut,
                                             TARIDLSTA_u16EngSpdLimSlewOut);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_normal                           */
/* !Description :  La consigne de régime de ralenti de base est calculée à    */
/*                 partir des informations rapport de boite de vitesse et     */
/*                 température moteur.                                        */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalcTarNorSlewInput();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nIncTarIdlNorm_C;                                      */
/*  input sint16 TqSys_nDecTarIdlNorm_C;                                      */
/*  input uint16 TqSys_nTarIdlNorm;                                           */
/*  input uint16 TARIDLSTA_u16NormSlewInput;                                  */
/*  input uint16 TARIDLSTA_u16NeutSlewOut;                                    */
/*  input uint16 TARIDLSTA_u16NeutSlewInput;                                  */
/*  input boolean TqSys_bCVC_C;                                               */
/*  output uint16 TqSys_nTarIdlNorm;                                          */
/*  output uint16 TARIDLSTA_u16NeutSlewOut;                                   */
/*  output uint16 TqSys_nTarIdlNeut;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_normal(void)
{
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalSlewDec;


   TARIDLSTA_vidCalcTarNorSlewInput();
   u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlNorm_C + 12) / 25);
   s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlNorm_C, 0);
   u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

   u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlNorm,
                                             TARIDLSTA_u16NormSlewInput,
                                             u16LocalSlewInc,
                                             u16LocalSlewDec);
   TqSys_nTarIdlNorm = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);

   u16LocalSlewOutput = MATHSRV_u16SlewFilter(TARIDLSTA_u16NeutSlewOut,
                                              TARIDLSTA_u16NeutSlewInput,
                                              u16LocalSlewInc,
                                              u16LocalSlewDec);
   TARIDLSTA_u16NeutSlewOut = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);

   if (TqSys_bCVC_C != 0)
   {
      VEMS_vidSET(TqSys_nTarIdlNeut, TARIDLSTA_u16NeutSlewOut);
   }
   else
   {
      VEMS_vidSET(TqSys_nTarIdlNeut, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalcTarNorSlewInput                           */
/* !Description :  Calcul des entrées du bloc RateLimiter (Norm et Neut)      */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_006.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input sint16 TqSys_tEngDftTarIdl_C;                                       */
/*  input boolean TqSys_bCfTEngTarIdlNorm_C;                                  */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input boolean TqSys_bAcvBrkTarIdl;                                        */
/*  input boolean CoPt_bAcvIdlCrawl;                                          */
/*  input boolean TqSys_stTarIdlNorm_MP;                                      */
/*  input sint16 TqSys_tEngTarIdl_MP;                                         */
/*  input uint8 TqSys_tEngTarIdl_A[8];                                        */
/*  input uint8 TqSys_noGearTarIdl;                                           */
/*  input uint16 TqSys_nTarIdlNorm1_M[8][9];                                  */
/*  input uint16 TqSys_nTarIdlNorm2_M[8][9];                                  */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input uint16 TqSys_tiStopTarIdl_A[8];                                     */
/*  input uint32 EOM_tiEngRun;                                                */
/*  input uint16 TqSys_tiEngRunTarIdl_A[8];                                   */
/*  input uint8 TqSys_facCorTarIdlStrt_T[8];                                  */
/*  input uint16 TqSys_nOfsTarIdlStrt_M[8][8];                                */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint16 TqSys_pAirTarIdl_A[8];                                       */
/*  input uint16 TqSys_nOfsTarIdlPAir_T[8];                                   */
/*  output sint16 TqSys_tEngTarIdl_MP;                                        */
/*  output boolean TqSys_stTarIdlNorm_MP;                                     */
/*  output uint16 TARIDLSTA_u16NormSlewInput;                                 */
/*  output uint16 TARIDLSTA_u16NeutSlewInput;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalcTarNorSlewInput(void)
{
   boolean bLocalAcvTEngDftTarIdl;
   uint8   u8LocalExt_stGBxCf;
   uint8   u8LocalParaInput;
   uint8   u8LocalInterp1;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalParaY1;
   uint16  u16LocalParaY2;
   uint16  u16LocalInterp11;
   uint16  u16LocalInterp12;
   uint16  u16LocalInterp2;
   uint16  u16LocalInterp3;
   uint16  u16LocalEOM_tiEngRun;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalEOM_tiEngStop;
   uint32  u32LocalNormSlewInput;
   uint32  u32LocalNeutSlewInput;
   sint16  s16LocalEngTarIdl;
   sint16  s16LocalExt_tOilMes;
   sint16  s16LocalExt_tCoMes;
   uint32  u32LocalEOM_tiEngStop;
   uint32  u32LocalEOM_tiEngRun;


   bLocalAcvTEngDftTarIdl = GDGAR_bGetFRM(FRM_FRM_ACVTENGDFTTARIDL);
   if (bLocalAcvTEngDftTarIdl != 0)
   {
      s16LocalEngTarIdl = TqSys_tEngDftTarIdl_C;
   }
   else
   {
      if (TqSys_bCfTEngTarIdlNorm_C != 0)
      {
         VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
         s16LocalEngTarIdl = (sint16)(s16LocalExt_tOilMes / 10);
      }
      else
      {
         VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
         s16LocalEngTarIdl = s16LocalExt_tCoMes;
      }
   }
   TqSys_tEngTarIdl_MP = (sint16)MATHSRV_udtCLAMP(s16LocalEngTarIdl, -50, 200);

   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   switch(u8LocalExt_stGBxCf)
   {
      case 0:
         TqSys_stTarIdlNorm_MP = TqSys_bAcvBrkTarIdl;
         break;

      case 1:
         TqSys_stTarIdlNorm_MP = 0;
         break;

      case 2:
         VEMS_vidGET(CoPt_bAcvIdlCrawl, TqSys_stTarIdlNorm_MP);
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }

   u8LocalParaInput = (uint8)(TqSys_tEngTarIdl_MP + 50);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(TqSys_tEngTarIdl_A,
                                               u8LocalParaInput,
                                               8);
   u16LocalParaY = (uint16)MATHSRV_udtMIN(TqSys_noGearTarIdl, 8);
   u16LocalParaY = (uint16)(u16LocalParaY * 256);

   if (TqSys_stTarIdlNorm_MP == 0)
   {
      u16LocalInterp11 = MATHSRV_u16Interp2d(&TqSys_nTarIdlNorm1_M[0][0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             9);

      u16LocalInterp12 = MATHSRV_u16Interp2d(&TqSys_nTarIdlNorm1_M[0][0],
                                             u16LocalParaX,
                                             0,
                                             9);
   }
   else
   {
      u16LocalInterp11 = MATHSRV_u16Interp2d(&TqSys_nTarIdlNorm2_M[0][0],
                                             u16LocalParaX,
                                             u16LocalParaY,
                                             9);

      u16LocalInterp12 = MATHSRV_u16Interp2d(&TqSys_nTarIdlNorm2_M[0][0],
                                             u16LocalParaX,
                                             0,
                                             9);
   }

   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   s16LocalExt_tCoMes = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tCoMes, -50, 200);
   u8LocalParaInput = (uint8)(s16LocalExt_tCoMes + 50);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(TqSys_tEngTarIdl_A,
                                               u8LocalParaInput,
                                               8);

   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   u16LocalEOM_tiEngStop = (uint16)MATHSRV_udtMIN(u32LocalEOM_tiEngStop, 65535);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqSys_tiStopTarIdl_A,
                                                u16LocalEOM_tiEngStop,
                                                8);
   VEMS_vidGET(EOM_tiEngRun, u32LocalEOM_tiEngRun);
   u16LocalEOM_tiEngRun = (uint16)MATHSRV_udtMIN(u32LocalEOM_tiEngRun, 65535);
   u16LocalParaY1 = MATHSRV_u16CalcParaIncAryU16(TqSys_tiEngRunTarIdl_A,
                                                 u16LocalEOM_tiEngRun,
                                                8);
   u8LocalInterp1 = MATHSRV_u8Interp1d(TqSys_facCorTarIdlStrt_T,
                                       u16LocalParaY1);

   u16LocalInterp2 = MATHSRV_u16Interp2d(&TqSys_nOfsTarIdlStrt_M[0][0],
                                         u16LocalParaX,
                                         u16LocalParaY,
                                         8);

   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU16(TqSys_pAirTarIdl_A,
                                                u16LocalExt_pAirExtMes,
                                                8);
   u16LocalInterp3 = MATHSRV_u16Interp1d(TqSys_nOfsTarIdlPAir_T,
                                         u16LocalParaY2);


   u32LocalNormSlewInput = (uint32)( (u16LocalInterp11 * 4)
                                   + ( ( (u8LocalInterp1 * u16LocalInterp2)
                                       + 16)
                                     / 32)
                                   + (u16LocalInterp3 * 4));

   TARIDLSTA_u16NormSlewInput =
      (uint16)MATHSRV_udtMIN(u32LocalNormSlewInput, 32000);
   u32LocalNeutSlewInput = (uint32)( (u16LocalInterp12 * 4)
                                   + ( ( (u8LocalInterp1 * u16LocalInterp2)
                                       + 16)
                                     / 32)
                                   + (u16LocalInterp3 * 4));
    TARIDLSTA_u16NeutSlewInput =
      (uint16)MATHSRV_udtMIN(u32LocalNeutSlewInput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_engine                           */
/* !Description :  Ce bloc calcule la consigne de ralenti pour les différents */
/*                 besoins du moteur. Il prend en compte le type de carburant,*/
/*                 les modes de combustion, ainsi que la température d’huile  */
/*                 moteur.                                                    */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_Gsl();                         */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_Dsl();                         */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_Toil();                        */
/*  input boolean TqSys_bTypFu;                                               */
/*  input uint16 TqSys_nTarIdlGsl;                                            */
/*  input uint16 TqSys_nTarIdlDsl;                                            */
/*  input uint16 TqSys_nTarIdlCmbMod;                                         */
/*  input uint16 TqSys_nTarIdlTOil;                                           */
/*  output uint16 TqSys_nTarIdlEng;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_engine(void)
{
   boolean bLocalTqSys_bTypFu;
   uint16  u16LocalTarIdlEng;
   uint16  u16LocalTqSys_nTarIdlCmbMod;


   VEMS_vidGET(TqSys_bTypFu, bLocalTqSys_bTypFu);
   if (bLocalTqSys_bTypFu != 0)
   {
      /*F02_03_02_Calc_Idle_target_Gsl*/
      TARIDLSTA_vidCalc_Idl_tar_Gsl();
      u16LocalTarIdlEng = TqSys_nTarIdlGsl;
   }
   else
   {
      /*F02_03_01_Calc_Idle_target_Dsl*/
      TARIDLSTA_vidCalc_Idl_tar_Dsl();
      u16LocalTarIdlEng = TqSys_nTarIdlDsl;
   }

   VEMS_vidGET(TqSys_nTarIdlCmbMod, u16LocalTqSys_nTarIdlCmbMod);
   u16LocalTarIdlEng =
      (uint16)MATHSRV_udtMAX(u16LocalTarIdlEng, u16LocalTqSys_nTarIdlCmbMod);

   /*F02_03_03_Calc_Idle_target_Toil*/
   TARIDLSTA_vidCalc_Idl_tar_Toil();

   u16LocalTarIdlEng =
      (uint16)MATHSRV_udtMAX(u16LocalTarIdlEng, TqSys_nTarIdlTOil);

   TqSys_nTarIdlEng = (uint16)MATHSRV_udtMIN(u16LocalTarIdlEng, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_Dsl                              */
/* !Description :  La consigne de régime de ralenti spécifique diesel n’est   */
/*                 actuellement pas utilisée.                                 */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint16 TqSys_nTarIdlDsl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_Dsl(void)
{
   TqSys_nTarIdlDsl = 0;
}

/*-------------------------------- End of file -------------------------------*/
