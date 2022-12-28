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
/* !File            : TARIDLSTA_FCT2.C                                        */
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
/*   1 / TARIDLSTA_vidCalc_Idl_tar_Gsl                                        */
/*   2 / TARIDLSTA_vidIdl_tar_Canister                                        */
/*   3 / TARIDLSTA_vidCalc_Idl_tar_Toil                                       */
/*   4 / TARIDLSTA_vidCalc_Idl_tar_consum                                     */
/*   5 / TARIDLSTA_vidCalc_Idl_tar_spd_ex                                     */
/*   6 / TARIDLSTA_vidCalc_Idl_tar_ac                                         */
/*   7 / TARIDLSTA_vidCalc_Idl_tar_alt                                        */
/*   8 / TARIDLSTA_vidCalc_Idl_tar_UH                                         */
/*   9 / TARIDLSTA_vidCalc_Idl_tar_lo_bat                                     */
/*   10 / TARIDLSTA_vidCalc_Idl_tar_thp                                       */
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
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   11 Jul 2013 $*/
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
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_Gsl                              */
/* !Description :  La consigne de régime de ralenti essence se décompose en 1 */
/*                 sous-bloc : Une consigne de régime de ralenti pour la purge*/
/*                 canister.                                                  */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidIdl_tar_Canister();                         */
/*  input uint16 TqSys_nTarIdlCanPurg;                                        */
/*  output uint16 TqSys_nTarIdlGsl;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_Gsl(void)
{
   /*F02_03_02_01_Calc_Idle_target_Canister*/
   TARIDLSTA_vidIdl_tar_Canister();

   TqSys_nTarIdlGsl = (uint16)MATHSRV_udtMIN(TqSys_nTarIdlCanPurg, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidIdl_tar_Canister                              */
/* !Description :  La fonction de consigne de régime de ralenti purge canister*/
/*                 est fonction du facteur filtré d’adaptation pour purge     */
/*                 canister. Cette consigne est inhibée ou activée par        */
/*                 CanPurg_bTarIdlCanPurg et inhibé lorsque le rapport de     */
/*                 boite est supérieur à 0.                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CanPurg_bTarIdlCanPurg;                                     */
/*  input boolean TqSys_bAcvTarIdlCanPurg_MP;                                 */
/*  input uint8 TqSys_noGearTarIdl;                                           */
/*  input uint8 CanPurg_facTarIdlCanPurg;                                     */
/*  input uint16 TqSys_facTarIdlCanPurg_A[8];                                 */
/*  input uint16 TqSys_nTarIdlCanPurg_T[8];                                   */
/*  input uint16 TqSys_nIncTarIdlCanPurg_C;                                   */
/*  input sint16 TqSys_nDecTarIdlCanPurg_C;                                   */
/*  input uint16 TqSys_nTarIdlCanPurg;                                        */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TqSys_bAcvTarIdlCanPurg_MP;                                */
/*  output uint16 TqSys_nTarIdlCanPurg;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidIdl_tar_Canister(void)
{
   boolean bLocalCanPurg_bTarIdlCanPurg;
   boolean bLocalAcvTarIdlCanPurgPrev;
   uint8   u8LocalCanPurg_facTarIdlCanPurg;
   uint16  u16LocalParaY;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   uint32  u32LocalVar;
   sint16  s16LocalSlewDec;


   VEMS_vidGET(CanPurg_bTarIdlCanPurg, bLocalCanPurg_bTarIdlCanPurg);
   bLocalAcvTarIdlCanPurgPrev = TqSys_bAcvTarIdlCanPurg_MP;

   if (  (bLocalCanPurg_bTarIdlCanPurg == 0)
      && (TqSys_noGearTarIdl == 0))
   {
      TqSys_bAcvTarIdlCanPurg_MP = 1;
      VEMS_vidGET(CanPurg_facTarIdlCanPurg, u8LocalCanPurg_facTarIdlCanPurg);
      u16LocalParaY =
         MATHSRV_u16CalcParaIncAryU16(TqSys_facTarIdlCanPurg_A,
                                     (uint16)u8LocalCanPurg_facTarIdlCanPurg,
                                     8);
      u16LocalSlewInput = MATHSRV_u16Interp1d(&TqSys_nTarIdlCanPurg_T[0],
                                              u16LocalParaY);
      u32LocalVar = u16LocalSlewInput * 4;
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u32LocalVar, 65535);
   }
   else
   {
      TqSys_bAcvTarIdlCanPurg_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlCanPurgPrev != 0)
      || (TqSys_bAcvTarIdlCanPurg_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlCanPurg_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlCanPurg_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlCanPurg,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlCanPurg = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_Toil                             */
/* !Description :  Ce bloc calcule une consigne de régime de ralenti en       */
/*                 fonction de la température d’huile moteur.                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input uint8 TqSys_tOilTarIdl_A[8];                                        */
/*  input uint16 TqSys_nTarIdlTOil_T[8];                                      */
/*  output uint16 TqSys_nTarIdlTOil;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_Toil(void)
{
   uint8  u8LocalExt_tOilMes;
   uint16 u16LocalParaY;
   uint16 u16LocalInterp;
   sint16 s16LocalExt_tOilMes;


   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   s16LocalExt_tOilMes = (sint16)((s16LocalExt_tOilMes / 10) + 50);
   u8LocalExt_tOilMes = (uint8)MATHSRV_udtCLAMP(s16LocalExt_tOilMes, 0, 250);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(TqSys_tOilTarIdl_A,
                                               u8LocalExt_tOilMes,
                                               8);
   u16LocalInterp = MATHSRV_u16Interp1d(&TqSys_nTarIdlTOil_T[0], u16LocalParaY);

   u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8000);
   TqSys_nTarIdlTOil = (uint16)(u16LocalInterp * 4);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_consum                           */
/* !Description :  Les différents consommateurs qui peuvent modifier la       */
/*                 consigne : L’air conditionné, Les thermoplongeurs pour     */
/*                 chauff habitacle, Le soutien de l’alternateur, La direction*/
/*                 assistée, La tension de batterie, Le soutien pour UH, Le   */
/*                 chauff de l’habitacle.                                     */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_spd_ex();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_ac();                          */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_alt();                         */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_UH();                          */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_lo_bat();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_thp();                         */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_ss();                          */
/*  extf argret void TARIDLSTA_vidClc_Idl_tar_vac_pmp();                      */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 ThMgt_nTarIdlHeatReq;                                        */
/*  input uint16 TqSys_nTarIdlUH;                                             */
/*  input uint16 TqSys_nTarIdlAC;                                             */
/*  input uint16 TqSys_nTarIdlBatt;                                           */
/*  input uint16 TqSys_nTarIdlAlt;                                            */
/*  input uint16 TqSys_nTarIdlWaHt;                                           */
/*  input uint16 TqSys_nTarIdlStgPmp;                                         */
/*  input uint16 TqSys_nTarIdlVacPmp;                                         */
/*  output uint16 TqSys_nTarIdlCus;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_consum(void)
{
   uint16 u16LocalVar;
   uint16 u16LocalThMgt_nTarIdlHeatReq;


   /*F02_04_01_Calc_Idle_target_speed_exceed*/
   TARIDLSTA_vidCalc_Idl_tar_spd_ex();

   /*F02_04_02_Calc_Idle_target_ac*/
   TARIDLSTA_vidCalc_Idl_tar_ac();

   /*F02_04_03_Calc_Idle_target_alt_sup*/
   TARIDLSTA_vidCalc_Idl_tar_alt();

   /*F02_04_04_Calc_Idle_target_UH*/
   TARIDLSTA_vidCalc_Idl_tar_UH();

   /*F02_04_05_Calc_Idle_target_low_bat*/
   TARIDLSTA_vidCalc_Idl_tar_lo_bat();

   /*F02_04_06_Calc_Idle_target_thp*/
   TARIDLSTA_vidCalc_Idl_tar_thp();

   /*F02_04_07_Calc_Idle_target_ss*/
   TARIDLSTA_vidCalc_Idl_tar_ss();

   /*F02_04_08_Calc_Idle_target_vaccum_pump*/
   TARIDLSTA_vidClc_Idl_tar_vac_pmp();

   VEMS_vidGET(ThMgt_nTarIdlHeatReq, u16LocalThMgt_nTarIdlHeatReq);
   u16LocalVar =
      (uint16)MATHSRV_udtMAX(TqSys_nTarIdlUH, u16LocalThMgt_nTarIdlHeatReq);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlAC);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlBatt);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlAlt);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlWaHt);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlStgPmp);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlVacPmp);
   TqSys_nTarIdlCus = (uint16)MATHSRV_udtMIN(u16LocalVar, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_spd_ex                           */
/* !Description :  Ce bloc définit une condition qui permet de supprimer la   */
/*                 modification du régime de ralenti cible demandée par les   */
/*                 consommateurs.                                             */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_013.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean TqSys_bIdlClcReq;                                           */
/*  input uint8 TqSys_spdVehLimIdl_C;                                         */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint32 EOM_tiEngRun;                                                */
/*  input uint16 TqSys_tiStrtDlyTarIdlCus_C;                                  */
/*  output boolean TqSys_bTarIdlSpd;                                          */
/*  output boolean TqSys_bAuthTarIdlCus;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_spd_ex(void)
{
   boolean bLocalDft_spdVeh;
   boolean bLocalTqSys_bIdlClcReq;
   uint8   u8LocalCoPTSt_stEng;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalSpdVehLimIdl;
   uint32  u32LocalEOM_tiEngRun;


   bLocalDft_spdVeh = GDGAR_bGetFRM(FRM_FRM_DFT_SPDVEH);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(TqSys_bIdlClcReq, bLocalTqSys_bIdlClcReq);
   u16LocalSpdVehLimIdl = (uint16)(TqSys_spdVehLimIdl_C * 64);

   if (  (bLocalTqSys_bIdlClcReq == 0)
      && (  (u16LocalVeh_spdVeh > u16LocalSpdVehLimIdl)
         || (bLocalDft_spdVeh != 0)))
   {
      TqSys_bTarIdlSpd = 1;
   }
   else
   {
      TqSys_bTarIdlSpd = 0;
   }

   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(EOM_tiEngRun, u32LocalEOM_tiEngRun);

   u32LocalEOM_tiEngRun = MATHSRV_udtMIN(u32LocalEOM_tiEngRun, 656);
   u32LocalEOM_tiEngRun = u32LocalEOM_tiEngRun * 100;

   if (  (u8LocalCoPTSt_stEng == 5)
      && (u32LocalEOM_tiEngRun > TqSys_tiStrtDlyTarIdlCus_C))
   {
      TqSys_bAuthTarIdlCus = 1;
   }
   else
   {
      TqSys_bAuthTarIdlCus = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_ac                               */
/* !Description :  Fonction qui permet de calculer TqSys_nTarIdlAC: le régime */
/*                 de ralenti cible requis par la climatisation (AC).         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqCmp_tqACLoss;                                              */
/*  input uint8 TqSys_facFilTqACTarIdl_C;                                     */
/*  input uint16 TqSys_tqACFilTarIdl_MP;                                      */
/*  input uint32 TARIDLSTA_u32TqACFilTarIdlMem;                               */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqSys_spdVehHiTarIdlAC_C;                                     */
/*  input uint8 TqSys_spdVehLoTarIdlAC_C;                                     */
/*  input boolean TqSys_bAuthTarIdlCus;                                       */
/*  input boolean TARIDLSTA_bNegHysTarIdlAC;                                  */
/*  input boolean AC_bACClu;                                                  */
/*  input boolean TqSys_bTarIdlSpd;                                           */
/*  input boolean TqSys_bAcvTarIdlAC_MP;                                      */
/*  input boolean TqSys_bAcvTarIdlSpdAC_C;                                    */
/*  input boolean TARIDLSTA_bTarIdlACFlipFlopOut;                             */
/*  input boolean TqSys_bCfNTarIdlAC_C;                                       */
/*  input uint8 Ext_stACTypCf;                                                */
/*  input uint16 Clm_nTarIdl;                                                 */
/*  input uint16 TqSys_nExtMinTarIdlAC_C;                                     */
/*  input uint16 TqSys_nExtMaxTarIdlAC_C;                                     */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint8 TqSys_tAirTarIdlAC_A[8];                                      */
/*  input uint8 TqSys_noGearTarIdl;                                           */
/*  input uint16 TqSys_nTarIdlAC_M[8][9];                                     */
/*  input boolean TqSys_bAcvTarIdlTqAC;                                       */
/*  input uint16 TqSys_tqACFilTarIdl_A[8];                                    */
/*  input uint16 TqSys_nTarIdlACTq_T[8];                                      */
/*  input uint16 TqSys_nIncTarIdlAC_C;                                        */
/*  input sint16 TqSys_nDecTarIdlAC_C;                                        */
/*  input uint16 TqSys_nTarIdlAC;                                             */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output uint16 TqSys_tqACFilTarIdl_MP;                                     */
/*  output uint32 TARIDLSTA_u32TqACFilTarIdlMem;                              */
/*  output boolean TARIDLSTA_bNegHysTarIdlAC;                                 */
/*  output boolean TqSys_bAcvTarIdlTqAC;                                      */
/*  output boolean TARIDLSTA_bTarIdlACFlipFlopOut;                            */
/*  output boolean TqSys_bAcvTarIdlAC_MP;                                     */
/*  output uint16 TqSys_nTarIdlAC;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_ac(void)
{
   boolean bLocalAC_bACClu;
   boolean bLocalAcvTarIdlACPrev;
   uint8   u8LocalExt_stACTypCf;
   uint8   u8LocalExt_tAir;
   uint16  u16LocalFilterGain;
   uint16  u16LocalTqCmp_tqACLoss;
   uint16  u16LocalFilterOutput;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalPosHysLow;
   uint16  u16LocalPosHysHigh;
   uint16  u16LocalSlewInput;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   uint16  u16LocalInterp;
   uint32  u32LocalSatMax;
   uint32  u32LocalSatMin;
   sint16  s16LocalExt_tAir;
   sint16  s16LocalSlewDec;


   /*Low Pass Filter*/
   VEMS_vidGET(TqCmp_tqACLoss, u16LocalTqCmp_tqACLoss);
   if (TqSys_facFilTqACTarIdl_C >= 100)
   {
      TqSys_tqACFilTarIdl_MP =
         (uint16)MATHSRV_udtMIN(u16LocalTqCmp_tqACLoss, 8000);
      TARIDLSTA_u32TqACFilTarIdlMem = (uint32)(TqSys_tqACFilTarIdl_MP * 65536);
   }
   else
   {
      u16LocalFilterGain =
         (uint16)((uint32)(TqSys_facFilTqACTarIdl_C * 16384) / 25);
      u16LocalFilterOutput =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                        &TARIDLSTA_u32TqACFilTarIdlMem,
                                        u16LocalTqCmp_tqACLoss);
      TqSys_tqACFilTarIdl_MP =
         (uint16)MATHSRV_udtMIN(u16LocalFilterOutput, 8000);
   }

   /*NegHys*/
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalPosHysHigh = (uint16)(TqSys_spdVehHiTarIdlAC_C * 64);

   if (u16LocalVeh_spdVeh >= u16LocalPosHysHigh)
   {
      TARIDLSTA_bNegHysTarIdlAC = 0;
   }
   else
   {
      u16LocalPosHysLow = (uint16)(TqSys_spdVehLoTarIdlAC_C * 64);
      if (u16LocalVeh_spdVeh <= u16LocalPosHysLow)
      {
         TARIDLSTA_bNegHysTarIdlAC = 1;
      }
   }

   if (  (TqSys_bAuthTarIdlCus != 0)
      && (TARIDLSTA_bNegHysTarIdlAC != 0))
   {
      TqSys_bAcvTarIdlTqAC = 1;
   }
   else
   {
      TqSys_bAcvTarIdlTqAC = 0;
   }

   /*Bascule RS*/
   VEMS_vidGET(AC_bACClu, bLocalAC_bACClu);
   if (TqSys_bTarIdlSpd != 0)
   {
      TARIDLSTA_bTarIdlACFlipFlopOut = 0;
   }
   else
   {
      if (bLocalAC_bACClu != 0)
      {
         TARIDLSTA_bTarIdlACFlipFlopOut = 1;
      }
   }

   bLocalAcvTarIdlACPrev = TqSys_bAcvTarIdlAC_MP;
   if (TqSys_bAcvTarIdlSpdAC_C != 0)
   {
      TqSys_bAcvTarIdlAC_MP = TARIDLSTA_bTarIdlACFlipFlopOut;
   }
   else
   {
      TqSys_bAcvTarIdlAC_MP = bLocalAC_bACClu;
   }

   /*Rate Limiter*/
   if (TqSys_bAcvTarIdlAC_MP != 0)
   {
      if (TqSys_bCfNTarIdlAC_C != 0)
      {
         VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);
         if (u8LocalExt_stACTypCf != 0)
         {
            VEMS_vidGET(Clm_nTarIdl, u16LocalSlewInput);
         }
         else
         {
            u16LocalSlewInput = 0;
         }

         u32LocalSatMin = TqSys_nExtMinTarIdlAC_C * 4;
         u32LocalSatMax = TqSys_nExtMaxTarIdlAC_C * 4;
         u16LocalSlewInput = (uint16)MATHSRV_udtCLAMP(u16LocalSlewInput,
                                                      u32LocalSatMin,
                                                      u32LocalSatMax);
      }
      else
      {
         VEMS_vidGET(Ext_tAir, s16LocalExt_tAir);
         s16LocalExt_tAir = (sint16)MATHSRV_udtMAX(s16LocalExt_tAir, -50);
         u8LocalExt_tAir = (uint8)(s16LocalExt_tAir + 50);
         u16LocalParaX = MATHSRV_u16CalcParaIncAryU8(TqSys_tAirTarIdlAC_A,
                                                     u8LocalExt_tAir,
                                                     8);
         u16LocalParaY = (uint16)MATHSRV_udtMIN(TqSys_noGearTarIdl, 8);
         u16LocalParaY = (uint16)(u16LocalParaY * 256);

         u16LocalSlewInput = MATHSRV_u16Interp2d(&TqSys_nTarIdlAC_M[0][0],
                                                 u16LocalParaX,
                                                 u16LocalParaY,
                                                 9);
         if (TqSys_bAcvTarIdlTqAC != 0)
         {
            u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqSys_tqACFilTarIdl_A,
                                                        TqSys_tqACFilTarIdl_MP,
                                                        8);
            u16LocalInterp = MATHSRV_u16Interp1d(TqSys_nTarIdlACTq_T,
                                                 u16LocalParaY);
            u16LocalSlewInput =
               (uint16)MATHSRV_udtMAX(u16LocalSlewInput, u16LocalInterp);
         }
         u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 32000);
         u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
      }
   }
   else
   {
      u16LocalSlewInput = 0;
   }

   if (  (TqSys_bAcvTarIdlAC_MP == 0)
      || (bLocalAcvTarIdlACPrev != 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlAC_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlAC_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlAC,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlAC = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_alt                              */
/* !Description :  TqSys_nTarIdlAlt est un régime de ralenti demandé qui est  */
/*                 utilisé quand la demande externe AltCtl_bCmpReq est vraie. */
/*                 Cette demande peut être annulée si : TqSys_bTarIdlSpd est  */
/*                 vrai et que la demande spécifique de ralenti  Alt_bCmpReq  */
/*                 est fausse.                                                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input sint16 TqCmp_tqAltLoss;                                             */
/*  input uint8 TqSys_facFilTqAltTarIdl_C;                                    */
/*  input sint16 TqSys_tqAltFilTarIdl_MP;                                     */
/*  input sint32 TARIDLSTA_s32TqAltFilTarIdlMem;                              */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 TqSys_spdVehHiTarIdlAlt_C;                                    */
/*  input uint8 TqSys_spdVehLoTarIdlAlt_C;                                    */
/*  input boolean TqSys_bAuthTarIdlCus;                                       */
/*  input boolean TqSys_bAcvSpdCdnTarIdlAlt;                                  */
/*  input boolean AltCtl_bCmpReq;                                             */
/*  input uint8 TqSys_noGearTarIdl;                                           */
/*  input boolean TqSys_bTarIdlSpd;                                           */
/*  input boolean TqSys_bAcvTarIdlAltCmpReq_MP;                               */
/*  input boolean TqSys_bAcvTarIdlSpdAlt_C;                                   */
/*  input boolean TARIDLSTA_bTarIdlAltFlipFlopOut;                            */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint8 TqSys_facCorTAltTarIdl_C;                                     */
/*  input sint16 TqSys_tAltTarIdl_MP;                                         */
/*  input uint8 TqSys_tAltTarIdl_A[8];                                        */
/*  input uint16 TqSys_nTarIdlAltCmp_T[8];                                    */
/*  input boolean TqSys_bAcvTarIdlTqAlt;                                      */
/*  input uint16 TqSys_tqAltFilTarIdl_A[8];                                   */
/*  input uint16 TqSys_nTarIdlAltTq_T[8];                                     */
/*  input uint16 TqSys_nIncTarIdlAlt_C;                                       */
/*  input sint16 TqSys_nDecTarIdlAlt_C;                                       */
/*  input uint16 TqSys_nTarIdlAlt;                                            */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output sint16 TqSys_tqAltFilTarIdl_MP;                                    */
/*  output sint32 TARIDLSTA_s32TqAltFilTarIdlMem;                             */
/*  output boolean TqSys_bAcvSpdCdnTarIdlAlt;                                 */
/*  output boolean TqSys_bAcvTarIdlTqAlt;                                     */
/*  output boolean TARIDLSTA_bTarIdlAltFlipFlopOut;                           */
/*  output boolean TqSys_bAcvTarIdlAltCmpReq_MP;                              */
/*  output sint16 TqSys_tAltTarIdl_MP;                                        */
/*  output uint16 TqSys_nTarIdlAlt;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_alt(void)
{
   boolean bLocalAltCtl_bCmpReq;
   boolean bLocalCond;
   boolean blocalDeacNTarIdlAltCmp;
   boolean bLocalTarIdlAltCmpReqPrev;
   uint8   u8LocalRate;
   uint8   u8LocalParaInput;
   uint16  u16LocalFilterGain;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalPosHysLow;
   uint16  u16LocalPosHysHigh;
   uint16  u16LocalSlewInput;
   uint16  u16LocalParaInput;
   uint16  u16LocalParaY;
   uint16  u16LocalInterp;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalTqCmp_tqAltLoss;
   sint16  s16LocalFilterOutput;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalSlewDec;
   sint16  s16LocalExt_tCoMes;
   sint32  s32LocalBaryCntr;


   /*Low Pass Filter*/
   VEMS_vidGET(TqCmp_tqAltLoss, s16LocalTqCmp_tqAltLoss);
   if (TqSys_facFilTqAltTarIdl_C >= 100)
   {
      TqSys_tqAltFilTarIdl_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqCmp_tqAltLoss, -32000, 32000);
      TARIDLSTA_s32TqAltFilTarIdlMem =
         (sint32)(TqSys_tqAltFilTarIdl_MP * 65536);
   }
   else
   {
      u16LocalFilterGain = (uint16)((TqSys_facFilTqAltTarIdl_C * 16384) / 25);
      s16LocalFilterOutput =
         MATHSRV_s16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &TARIDLSTA_s32TqAltFilTarIdlMem,
                                         s16LocalTqCmp_tqAltLoss);
      TqSys_tqAltFilTarIdl_MP =
         (sint16)MATHSRV_udtCLAMP(s16LocalFilterOutput, -32000, 32000);
   }

   /*NegHys*/
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   u16LocalPosHysHigh = (uint16)(TqSys_spdVehHiTarIdlAlt_C * 64);

   if (u16LocalVeh_spdVeh >= u16LocalPosHysHigh)
   {
      TqSys_bAcvSpdCdnTarIdlAlt = 0;
   }
   else
   {
      u16LocalPosHysLow = (uint16)(TqSys_spdVehLoTarIdlAlt_C * 64);
      if (u16LocalVeh_spdVeh <= u16LocalPosHysLow)
      {
         TqSys_bAcvSpdCdnTarIdlAlt = 1;
      }
   }

   if (  (TqSys_bAuthTarIdlCus != 0)
      && (TqSys_bAcvSpdCdnTarIdlAlt != 0))
   {
      TqSys_bAcvTarIdlTqAlt = 1;
   }
   else
   {
      TqSys_bAcvTarIdlTqAlt = 0;
   }

   VEMS_vidGET(AltCtl_bCmpReq, bLocalAltCtl_bCmpReq);
   if (  (TqSys_noGearTarIdl == 0)
      && (bLocalAltCtl_bCmpReq != 0)
      && (TqSys_bAcvSpdCdnTarIdlAlt != 0))
   {
      bLocalCond = 1;
   }
   else
   {
      bLocalCond = 0;
   }

   /*Bascule RS*/
   if (TqSys_bTarIdlSpd != 0)
   {
      TARIDLSTA_bTarIdlAltFlipFlopOut = 0;
   }
   else
   {
      if (bLocalCond != 0)
      {
         TARIDLSTA_bTarIdlAltFlipFlopOut = 1;
      }
   }

   bLocalTarIdlAltCmpReqPrev = TqSys_bAcvTarIdlAltCmpReq_MP;
   if (TqSys_bAcvTarIdlSpdAlt_C != 0)
   {
      TqSys_bAcvTarIdlAltCmpReq_MP = TARIDLSTA_bTarIdlAltFlipFlopOut;
   }
   else
   {
      TqSys_bAcvTarIdlAltCmpReq_MP = bLocalCond;
   }

   /*BaryCentre*/
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);

   u8LocalRate = (uint8)MATHSRV_udtMIN(TqSys_facCorTAltTarIdl_C, 200);
   s32LocalBaryCntr = (sint32)(s16LocalExt_tCoMes - s8LocalExt_tAir);
   s32LocalBaryCntr =
      ((s32LocalBaryCntr  * u8LocalRate) / 200) + s8LocalExt_tAir;

   TqSys_tAltTarIdl_MP = (sint16)MATHSRV_udtCLAMP(s32LocalBaryCntr, -40, 200);

   /*Rate Limiter*/
   blocalDeacNTarIdlAltCmp = GDGAR_bGetFRM(FRM_FRM_DEACNTARIDLALTCMP);
   if (blocalDeacNTarIdlAltCmp == 0)
   {
      if (TqSys_bAcvTarIdlAltCmpReq_MP != 0)
      {
         u8LocalParaInput = (uint8)(TqSys_tAltTarIdl_MP + 50);
         u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(TqSys_tAltTarIdl_A,
                                                     u8LocalParaInput,
                                                     8);
         u16LocalSlewInput = MATHSRV_u16Interp1d(&TqSys_nTarIdlAltCmp_T[0],
                                                 u16LocalParaY);
      }
      else
      {
         u16LocalSlewInput = 0;
      }

      if (TqSys_bAcvTarIdlTqAlt != 0)
      {
         u16LocalParaInput =
            (uint16)MATHSRV_udtCLAMP(TqSys_tqAltFilTarIdl_MP, 0, 8000);
         u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqSys_tqAltFilTarIdl_A,
                                                      u16LocalParaInput,
                                                      8);

         u16LocalInterp = MATHSRV_u16Interp1d(&TqSys_nTarIdlAltTq_T[0],
                                                 u16LocalParaY);
         u16LocalSlewInput =
               (uint16)MATHSRV_udtMAX(u16LocalSlewInput, u16LocalInterp);
      }
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      u16LocalSlewInput = 0;
   }

   if (  (TqSys_bAcvTarIdlAltCmpReq_MP == 0)
      || (bLocalTarIdlAltCmpReqPrev != 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlAlt_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlAlt_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlAlt,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlAlt = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_UH                               */
/* !Description :  Fonction de calcul de TqSys_nTarIdl_bUHCtl  : régime de    */
/*                 ralenti demandé qui est utilisé quand la demande externe   */
/*                 CoPtUH_bEngAsiReq est vrai.                                */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_016.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint8 TqSys_facTIdlAsiAlt_C;                                        */
/*  input boolean TqSys_bEngAsiReqTrv;                                        */
/*  input sint16 TARIDLSTA_s16BaryCentreOut;                                  */
/*  input uint8 TqSys_tCoTarIdlUH_A[8];                                       */
/*  input uint16 TqSys_nTarIdlUH_T[8];                                        */
/*  input boolean TARIDLSTA_bEngAsiReqTrvPrev;                                */
/*  input uint16 TqSys_nIncTarIdlUH_C;                                        */
/*  input sint16 TqSys_nDecTarIdlUH_C;                                        */
/*  input uint16 TqSys_nTarIdlUH;                                             */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output sint16 TARIDLSTA_s16BaryCentreOut;                                 */
/*  output uint16 TqSys_nTarIdlUH;                                            */
/*  output boolean TARIDLSTA_bEngAsiReqTrvPrev;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_UH(void)
{
   boolean bLocalTqSys_bEngAsiReqTrv;
   uint8   u8LocalRate;
   uint8   u8LocalParaInput;
   uint16  u16LocalParaY;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalExt_tCoMes;
   sint16  s16LocalSlewDec;
   sint32  s32LocalBaryCntr;


   /*BaryCentre*/
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);

   u8LocalRate = (uint8)MATHSRV_udtMIN(TqSys_facTIdlAsiAlt_C, 100);
   s32LocalBaryCntr = (sint32)(s16LocalExt_tCoMes - s8LocalExt_tAir);
   s32LocalBaryCntr =
      ((s32LocalBaryCntr * u8LocalRate) / 100) + s8LocalExt_tAir;

   TARIDLSTA_s16BaryCentreOut =
      (sint16)MATHSRV_udtCLAMP(s32LocalBaryCntr, -50, 200);

   /*Rate Limiter*/
   VEMS_vidGET(TqSys_bEngAsiReqTrv, bLocalTqSys_bEngAsiReqTrv);
   if (bLocalTqSys_bEngAsiReqTrv != 0)
   {
      u8LocalParaInput = (uint8)(TARIDLSTA_s16BaryCentreOut + 50);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(TqSys_tCoTarIdlUH_A,
                                                  u8LocalParaInput,
                                                  8);

      u16LocalSlewInput = MATHSRV_u16Interp1d(&TqSys_nTarIdlUH_T[0],
                                              u16LocalParaY);
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      u16LocalSlewInput = 0;
   }

   if (  (bLocalTqSys_bEngAsiReqTrv == 0)
      || (TARIDLSTA_bEngAsiReqTrvPrev != 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlUH_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlUH_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlUH,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlUH = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
   TARIDLSTA_bEngAsiReqTrvPrev = bLocalTqSys_bEngAsiReqTrv;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_lo_bat                           */
/* !Description :  Fonction qui calcule TqSys_nTarIdlBatt: régime de ralenti  */
/*                 demandé qui s’active si la tension de batterie est basse.  */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean TqSys_bAuthTarIdlCus;                                       */
/*  input sint16 Ext_uBattMes;                                                */
/*  input uint8 TqSys_uThdTarIdlBatt_C;                                       */
/*  input sint8 TqSys_uErrMinTarIdlBatt_C;                                    */
/*  input uint8 TqSys_facCorTarIdlBatt_C;                                     */
/*  input uint16 TqSys_ctTarIdlBatt_MP;                                       */
/*  input uint8 TqSys_ctMaxTarIdlBatt_C;                                      */
/*  input uint8 TqSys_ctLoTarIdlBatt_C;                                       */
/*  input uint8 TqSys_ctHiTarIdlBatt_C;                                       */
/*  input boolean TqSys_bAcvTarIdlSpdBatt_C;                                  */
/*  input boolean TqSys_bTarIdlSpd;                                           */
/*  input boolean TqSys_bAcvTarIdlBatt_MP;                                    */
/*  input boolean TqSys_stTarIdlBatt_MP;                                      */
/*  input uint16 TqSys_nTarIdlBatt_C;                                         */
/*  input uint16 TqSys_nIncTarIdlBatt_C;                                      */
/*  input sint16 TqSys_nDecTarIdlBatt_C;                                      */
/*  input uint16 TqSys_nTarIdlBatt;                                           */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output uint16 TqSys_ctTarIdlBatt_MP;                                      */
/*  output boolean TqSys_stTarIdlBatt_MP;                                     */
/*  output boolean TqSys_bAcvTarIdlBatt_MP;                                   */
/*  output uint16 TqSys_nTarIdlBatt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_lo_bat(void)
{
   boolean bLocalAcvTarIdlBattPrev;
   boolean bLocalFlag;
   uint16  u16LocaltMaxTarIdlBatt;
   uint16  u16LocalPosHysHigh;
   uint16  u16LocalPosHysLow;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalExt_uBattMes;
   sint16  s16LocalSlewDec;
   sint32  s32LocalTarIdlBatt;


   /*Production of TqSys_ctTarIdlBatt_MP*/
   if (TqSys_bAuthTarIdlCus != 0)
   {
      VEMS_vidGET(Ext_uBattMes, s16LocalExt_uBattMes);
      s32LocalTarIdlBatt =
         (sint32)(TqSys_uThdTarIdlBatt_C - (s16LocalExt_uBattMes / 25));
      s32LocalTarIdlBatt =
         MATHSRV_udtMAX(s32LocalTarIdlBatt, TqSys_uErrMinTarIdlBatt_C);

      s32LocalTarIdlBatt = ( ( s32LocalTarIdlBatt
                             * TqSys_facCorTarIdlBatt_C)
                           / 5)
                         + TqSys_ctTarIdlBatt_MP;

      u16LocaltMaxTarIdlBatt = (uint16)(TqSys_ctMaxTarIdlBatt_C * 16);

      TqSys_ctTarIdlBatt_MP = (uint16)MATHSRV_udtCLAMP(s32LocalTarIdlBatt,
                                                       0,
                                                       u16LocaltMaxTarIdlBatt);
   }
   else
   {
      TqSys_ctTarIdlBatt_MP = 0;
   }

   /*PosHys*/
   u16LocalPosHysLow = (uint16)(TqSys_ctLoTarIdlBatt_C * 16);
   if (TqSys_ctTarIdlBatt_MP <= u16LocalPosHysLow)
   {
      TqSys_stTarIdlBatt_MP = 0;
   }
   else
   {
      u16LocalPosHysHigh = (uint16)(TqSys_ctHiTarIdlBatt_C * 16);
      if (TqSys_ctTarIdlBatt_MP >= u16LocalPosHysHigh)
      {
         TqSys_stTarIdlBatt_MP = 1;
      }
   }

   /*Rate Limiter*/
   if (TqSys_bAcvTarIdlSpdBatt_C != 0)
   {
      if (TqSys_bTarIdlSpd != 0)
      {
         bLocalFlag = 0;
      }
      else
      {
         bLocalFlag = 1;
      }
   }
   else
   {
      bLocalFlag = 1;
   }

   bLocalAcvTarIdlBattPrev = TqSys_bAcvTarIdlBatt_MP;
   if (  (TqSys_stTarIdlBatt_MP != 0)
      && (bLocalFlag != 0))
   {
      TqSys_bAcvTarIdlBatt_MP = 1;
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(TqSys_nTarIdlBatt_C, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      TqSys_bAcvTarIdlBatt_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlBattPrev != 0)
      || (TqSys_bAcvTarIdlBatt_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlBatt_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlBatt_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlBatt,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlBatt = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_thp                              */
/* !Description :  Fonction du calcule de TqSys_nTarIdlWaHt: régime de ralenti*/
/*                 demandé si au moins un des thermoplongeurs est actif (pour */
/*                 le chauffage de l’habitacle).                              */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_018.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean WaHt_bWaHt1Out;                                             */
/*  input boolean WaHt_bWaHt2Out;                                             */
/*  input boolean TqSys_bTarIdlSpd;                                           */
/*  input boolean TqSys_bAcvTarIdlWaHt_MP;                                    */
/*  input boolean TqSys_bAcvTarIdlSpdWaHt_C;                                  */
/*  input boolean TARIDLSTA_bTarIdlWaHtFlipFlopOut;                           */
/*  input uint16 TqSys_nTarIdlWaHt_C;                                         */
/*  input uint16 TqSys_nIncTarIdlWaHt_C;                                      */
/*  input sint16 TqSys_nDecTarIdlWaHt_C;                                      */
/*  input uint16 TqSys_nTarIdlWaHt;                                           */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TARIDLSTA_bTarIdlWaHtFlipFlopOut;                          */
/*  output boolean TqSys_bAcvTarIdlWaHt_MP;                                   */
/*  output uint16 TqSys_nTarIdlWaHt;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_thp(void)
{
   boolean bLocalWaHt_bWaHt1Out;
   boolean bLocalWaHt_bWaHt2Out;
   boolean bLocalFlag;
   boolean bLocalAcvTarIdlWaHtPrev;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalSlewDec;


   VEMS_vidGET(WaHt_bWaHt1Out, bLocalWaHt_bWaHt1Out);
   VEMS_vidGET(WaHt_bWaHt2Out, bLocalWaHt_bWaHt2Out);
   if (  (bLocalWaHt_bWaHt1Out != 0)
      || (bLocalWaHt_bWaHt2Out != 0))
   {
      bLocalFlag = 1;
   }
   else
   {
      bLocalFlag = 0;
   }

   /*bascule RS*/
   if (TqSys_bTarIdlSpd != 0)
   {
      TARIDLSTA_bTarIdlWaHtFlipFlopOut = 0;
   }
   else
   {
      if (bLocalFlag != 0)
      {
         TARIDLSTA_bTarIdlWaHtFlipFlopOut = 1;
      }
   }

   bLocalAcvTarIdlWaHtPrev = TqSys_bAcvTarIdlWaHt_MP;
   if (TqSys_bAcvTarIdlSpdWaHt_C != 0)
   {
      TqSys_bAcvTarIdlWaHt_MP = TARIDLSTA_bTarIdlWaHtFlipFlopOut;
   }
   else
   {
      TqSys_bAcvTarIdlWaHt_MP = bLocalFlag;
   }

   /*Rate Limiter*/
   if (TqSys_bAcvTarIdlWaHt_MP != 0)
   {
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(TqSys_nTarIdlWaHt_C, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlWaHtPrev != 0)
      || (TqSys_bAcvTarIdlWaHt_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlWaHt_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlWaHt_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlWaHt,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlWaHt = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*-------------------------------- End of file -------------------------------*/
