/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IGARB                                                   */
/* !Description     : IGARB component.                                        */
/*                                                                            */
/* !Module          : IGARB                                                   */
/* !Description     : ARBITRAGE DES AVANCES À APPLIQUER                       */
/*                                                                            */
/* !File            : IGARB_FCT1.C                                            */
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
/*   1 / IGARB_vidInitOutput                                                  */
/*   2 / IgArb_vidIgArbInit                                                   */
/*   3 / IgArb_vidIgnitionClcBenchMod                                         */
/*   4 / IgArb_vidIgnitionTimingBenchMode                                     */
/*   5 / IgArb_vidDwellEnergyBenchMode                                        */
/*   6 / IgArb_vidIgnitionArbitration                                         */
/*   7 / IgArb_vidMngBenchMod                                                 */
/*                                                                            */
/* !Reference   : V02 NT 09 07775 / 02                                        */
/* !OtherRefs   : VEMS V02 ECU#064402                                         */
/* !OtherRefs   : VEMS V02 ECU#064641                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
  temp.mde producing this kind of error                                      */
#include "IgArb.h"
#include "IgArb_L.h"
#include "IgArb_IM.h"
#include "VEMS.H"
#include "SWFAIL.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IGARB_vidInitOutput                                        */
/* !Description :  output initialization.                                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean IGARB_bAcvBenchModCmpnIgPrev;                              */
/*  output uint8 IgSys_CtrCylCmpn;                                            */
/*  output uint8 IgCmd_agIgSp;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IGARB_vidInitOutput(void)
{
   IGARB_bAcvBenchModCmpnIgPrev = 0;
   IgSys_CtrCylCmpn = 0;
   VEMS_vidSET(IgCmd_agIgSp, 0);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidIgArbInit                                         */
/* !Description :  Init function                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 IgSys_agIgSpNxtBenchModIni_C;                                 */
/*  input uint8 IgSys_agIgSpBenchModIni_C;                                    */
/*  input uint16 IgSys_iESpBenchModIni_C;                                     */
/*  input uint16 IgSys_tiDwellSpBenchModIni_C;                                */
/*  input uint8 IgArb_agIgTestCyl1_C;                                         */
/*  input uint8 IgArb_agIgTestCyl2_C;                                         */
/*  input uint8 IgArb_agIgTestCyl3_C;                                         */
/*  output uint8 IgSys_agIgSpNxtBenchMod;                                     */
/*  output uint8 IgSys_agIgSpBenchMod;                                        */
/*  output uint16 IgSys_iESpBenchMod;                                         */
/*  output uint16 IgSys_iESpBenchModIni_C;                                    */
/*  output uint16 IgSys_tiDwellSpBenchMod;                                    */
/*  output uint16 IgSys_tiDwellSpBenchModIni_C;                               */
/*  output uint8 IgSys_agigTestCyl[3];                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidIgArbInit(void)
{
   /*Internal Variables*/
   IgSys_agIgSpNxtBenchMod = IgSys_agIgSpNxtBenchModIni_C;
   IgSys_agIgSpBenchMod    = IgSys_agIgSpBenchModIni_C;
   /*Outputs*/
   VEMS_vidSET(IgSys_iESpBenchMod, IgSys_iESpBenchModIni_C);
   VEMS_vidSET(IgSys_tiDwellSpBenchMod, IgSys_tiDwellSpBenchModIni_C);
   IgSys_agigTestCyl[0] = IgArb_agIgTestCyl1_C;
   IgSys_agigTestCyl[1] = IgArb_agIgTestCyl2_C;
   IgSys_agigTestCyl[2] = IgArb_agIgTestCyl3_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidIgnitionClcBenchMod                               */
/* !Description :  Enable of ignition calculation in bench mode               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IgArb_vidIgnitionTimingBenchMode();                      */
/*  extf argret void IgArb_vidDwellEnergyBenchMode();                         */
/*  input boolean IgSys_bIgBenchModEna;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidIgnitionClcBenchMod(void)
{
   boolean bLocalIgSys_bIgBenchModEna;


   VEMS_vidGET(IgSys_bIgBenchModEna, bLocalIgSys_bIgBenchModEna);

   if (bLocalIgSys_bIgBenchModEna != 0)
   {
      IgArb_vidIgnitionTimingBenchMode();
      IgArb_vidDwellEnergyBenchMode();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidIgnitionTimingBenchMode                           */
/* !Description :  Ignition timing in bench mode                              */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 IgSys_agIgSp_nEngY_A[24];                                    */
/*  input uint8 IgSys_noAglgSpSelBenchMod_C;                                  */
/*  input uint16 Ssm_filt_throttle_position;                                  */
/*  input uint16 IgSys_agIgSp_posnThrX_A[16];                                 */
/*  input uint8 IgSys_agIgSp_posnThr_nEng_M[16][24];                          */
/*  input sint16 TqSys_tqIdcReq;                                              */
/*  input uint16 IgSys_agIgSp_tqIdcReqX_A[16];                                */
/*  input uint8 IgSys_agIgSp_tqIdcReq_nEng_M[16][24];                         */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 IgSys_agIgSp_pMnfX_A[16];                                    */
/*  input uint8 IgSys_agIgSp_pMnf_nEng_M[16][24];                             */
/*  input uint8 IgSys_agIgValSpBenchMod_C;                                    */
/*  input boolean IgSys_bKnkCorAdvEna_C;                                      */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 Eng_noCmprNxtCyl;                                             */
/*  input uint8 Cliquetis_cor_avance[4];                                      */
/*  output uint8 IgSys_agIgSpBenchMod;                                        */
/*  output uint8 IgSys_agIgSpNxtBenchMod;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidIgnitionTimingBenchMode(void)
{
   boolean bLocalAgIgSpFlagUpdate;
   uint8   u8Local_Multiport_Output;
   uint8   u8LocalEng_noCmprCyl;
   uint8   u8LocalCliquetis_cor_avance[CLIQUETIS_COR_AVANCE_COLS];
   uint8   u8LocalEng_noCmprNxtCyl;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalSsm_filt_throtl_position;
   uint16  u16LocalIo_map_mnfold_press_msrd;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalTqSys_tqIdcReq;
   sint16  s16LocalTqSys_tqIdcReq;
   sint16  s16LocalIgSys_agIgSpBenchMod;
   sint16  s16LocalIgSys_agIgSpNxtBenchMod;
   sint32  s32LocalTqSys_tqIdcReq;

   bLocalAgIgSpFlagUpdate = 0;

   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_agIgSp_nEngY_A,
                                                u16LocalRegime_moteur,
                                                24);

   switch(IgSys_noAglgSpSelBenchMod_C)
   {
      case 1:
      VEMS_vidGET(Ssm_filt_throttle_position,
                  u16LocalSsm_filt_throtl_position);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_agIgSp_posnThrX_A,
                                      u16LocalSsm_filt_throtl_position,
                                      16);

      u8Local_Multiport_Output =
         MATHSRV_u8Interp2d(&IgSys_agIgSp_posnThr_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 2:
      VEMS_vidGET(TqSys_tqIdcReq, s16LocalTqSys_tqIdcReq);

      s32LocalTqSys_tqIdcReq = (sint32)(s16LocalTqSys_tqIdcReq + 32000);
      u16LocalTqSys_tqIdcReq =
         (uint16)MATHSRV_udtMAX(s32LocalTqSys_tqIdcReq, 0);
      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_agIgSp_tqIdcReqX_A,
                                      u16LocalTqSys_tqIdcReq,
                                      16);

      u8Local_Multiport_Output =
         MATHSRV_u8Interp2d(&IgSys_agIgSp_tqIdcReq_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 3:
      VEMS_vidGET(Io_map_manifold_press_measured,
                  u16LocalIo_map_mnfold_press_msrd);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_agIgSp_pMnfX_A,
                                      u16LocalIo_map_mnfold_press_msrd,
                                      16);

      u8Local_Multiport_Output =
         MATHSRV_u8Interp2d(&IgSys_agIgSp_pMnf_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 4:
      u8Local_Multiport_Output = IgSys_agIgValSpBenchMod_C;
      break;

      default:
      bLocalAgIgSpFlagUpdate = 1;
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   if(bLocalAgIgSpFlagUpdate == 0)
   {
      if (IgSys_bKnkCorAdvEna_C != 0)
      {
         IgSys_agIgSpBenchMod = u8Local_Multiport_Output;
         IgSys_agIgSpNxtBenchMod = u8Local_Multiport_Output;
         /*QAC Warning Msg(2:3353): u8Local_Multiport_Output is protected by
           flag bLocalAgIgSpFlagUpdate in case if it has not been set         */
      }
      else
      {
         VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
         VEMS_vidGET(Eng_noCmprNxtCyl, u8LocalEng_noCmprNxtCyl);

         u8LocalEng_noCmprCyl=(uint8)MATHSRV_udtCLAMP(u8LocalEng_noCmprCyl,1,4);
         u8LocalEng_noCmprNxtCyl=
            (uint8)MATHSRV_udtCLAMP(u8LocalEng_noCmprNxtCyl,1,4);

         VEMS_vidGET1DArray(Cliquetis_cor_avance,
                            4,
                            u8LocalCliquetis_cor_avance);

         s16LocalIgSys_agIgSpBenchMod = (sint16)(u8Local_Multiport_Output
            - u8LocalCliquetis_cor_avance[u8LocalEng_noCmprCyl-1]);
         s16LocalIgSys_agIgSpNxtBenchMod = (sint16)(u8Local_Multiport_Output
            - u8LocalCliquetis_cor_avance[u8LocalEng_noCmprNxtCyl-1]);

         IgSys_agIgSpBenchMod =
            (uint8)MATHSRV_udtMAX(s16LocalIgSys_agIgSpBenchMod,0);
         IgSys_agIgSpNxtBenchMod =
            (uint8)MATHSRV_udtMAX(s16LocalIgSys_agIgSpNxtBenchMod,0);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidDwellEnergyBenchMode                              */
/* !Description :  Ignition energy in bench mode                              */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 IgSys_iESp_nEngY_A[24];                                      */
/*  input uint8 IgSys_noIESpSelBenchMod_C;                                    */
/*  input uint16 Ssm_filt_throttle_position;                                  */
/*  input uint16 IgSys_iESp_posnThrX_A[16];                                   */
/*  input uint16 IgSys_iESp_posnThr_nEng_M[16][24];                           */
/*  input sint16 TqSys_tqIdcReq;                                              */
/*  input uint16 IgSys_iESp_tqIdcReqX_A[16];                                  */
/*  input uint16 IgSys_iESp_tqIdcReq_nEng_M[16][24];                          */
/*  input uint16 Io_map_manifold_press_measured;                              */
/*  input uint16 IgSys_iESp_pMnfX_A[16];                                      */
/*  input uint16 IgSys_iESp_pMnfX_nEng_M[16][24];                             */
/*  input uint16 IgSys_iEValSpBenchMod_C;                                     */
/*  input uint16 IgSys_tiDwellSp_nEngY_A[24];                                 */
/*  input uint8 IgSys_noTiDwellSpSelBenchMod_C;                               */
/*  input uint16 IgSys_tiDwellSp_posnThrX_A[16];                              */
/*  input uint16 IgSys_tiDwellSp_posnThr_nEng_M[16][24];                      */
/*  input uint16 IgSys_tiDwellSp_tqIdcReqX_A[16];                             */
/*  input uint16 IgSys_tiDwellSp_tqIdcReq_nEng_M[16][24];                     */
/*  input uint16 IgSys_tiDwellSp_pMnfX_A[16];                                 */
/*  input uint16 IgSys_tiDwellSp_pMnfX_nEng_M[16][24];                        */
/*  input uint16 IgSys_tiDwellValSpBenchMod_C;                                */
/*  output uint16 IgSys_iESpBenchMod;                                         */
/*  output uint16 IgSys_tiDwellSpBenchMod;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidDwellEnergyBenchMode(void)
{
   boolean bLocalIESpFlagUpdate;
   boolean bLocalIDwellFlagUpdate;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalSsm_filt_throtl_position;
   uint16  u16LocalIo_map_mnfold_press_msrd;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalIgSys_iESpBenchMod;
   uint16  u16LocalIgSys_tiDwellSpBenchMod;
   uint16  u16LocalTqSys_tqIdcReq;
   sint16  s16LocalTqSys_tqIdcReq;
   sint32  s32LocalTqSys_tqIdcReq;


   bLocalIESpFlagUpdate = 0;
   bLocalIDwellFlagUpdate = 0;

   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_iESp_nEngY_A,
                                                u16LocalRegime_moteur,
                                                24);

   switch(IgSys_noIESpSelBenchMod_C)
   {
      case 1:
      VEMS_vidGET(Ssm_filt_throttle_position,
                  u16LocalSsm_filt_throtl_position);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_iESp_posnThrX_A,
                                      u16LocalSsm_filt_throtl_position,
                                      16);

      u16LocalIgSys_iESpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_iESp_posnThr_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 2:
      VEMS_vidGET(TqSys_tqIdcReq, s16LocalTqSys_tqIdcReq);
      s32LocalTqSys_tqIdcReq = (sint32)(s16LocalTqSys_tqIdcReq + 32000);
      u16LocalTqSys_tqIdcReq =
         (uint16)MATHSRV_udtMAX(s32LocalTqSys_tqIdcReq, 0);
      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_iESp_tqIdcReqX_A,
                                      u16LocalTqSys_tqIdcReq,
                                      16);

      u16LocalIgSys_iESpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_iESp_tqIdcReq_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 3:
      VEMS_vidGET(Io_map_manifold_press_measured,
                  u16LocalIo_map_mnfold_press_msrd);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_iESp_pMnfX_A,
                                      u16LocalIo_map_mnfold_press_msrd,
                                      16);

      u16LocalIgSys_iESpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_iESp_pMnfX_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 4:
      u16LocalIgSys_iESpBenchMod = IgSys_iEValSpBenchMod_C;
      break;

      default:
      bLocalIESpFlagUpdate = 1;
      SWFAIL_vidSoftwareErrorHook();
      break;
   }

   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(IgSys_tiDwellSp_nEngY_A,
                                                u16LocalRegime_moteur,
                                                24);

   switch(IgSys_noTiDwellSpSelBenchMod_C)
   {
      case 1:
      VEMS_vidGET(Ssm_filt_throttle_position,
                  u16LocalSsm_filt_throtl_position);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_tiDwellSp_posnThrX_A,
                                      u16LocalSsm_filt_throtl_position,
                                      16);

      u16LocalIgSys_tiDwellSpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_tiDwellSp_posnThr_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 2:
      VEMS_vidGET(TqSys_tqIdcReq, s16LocalTqSys_tqIdcReq);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_tiDwellSp_tqIdcReqX_A,
                                      (uint16)(s16LocalTqSys_tqIdcReq + 32000),
                                      16);

      u16LocalIgSys_tiDwellSpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_tiDwellSp_tqIdcReq_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 3:
      VEMS_vidGET(Io_map_manifold_press_measured,
                  u16LocalIo_map_mnfold_press_msrd);

      u16LocalParaX =
         MATHSRV_u16CalcParaIncAryU16(IgSys_tiDwellSp_pMnfX_A,
                                      u16LocalIo_map_mnfold_press_msrd,
                                      16);

      u16LocalIgSys_tiDwellSpBenchMod =
         MATHSRV_u16Interp2d(&IgSys_tiDwellSp_pMnfX_nEng_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             24);
      break;

      case 4:
      u16LocalIgSys_tiDwellSpBenchMod = IgSys_tiDwellValSpBenchMod_C;
      break;

      default:
      bLocalIDwellFlagUpdate = 1;
      SWFAIL_vidSoftwareErrorHook();
      break;
   }
   if(bLocalIESpFlagUpdate == 0)
   {
      VEMS_vidSET(IgSys_iESpBenchMod, u16LocalIgSys_iESpBenchMod);
      /*QAC Warning Msg(2:3353): u16LocalIgSys_iESpBenchMod is protected by
           flag bLocalIESpFlagUpdate in case if it has not been set           */
   }

   if(bLocalIDwellFlagUpdate == 0)
   {
      VEMS_vidSET(IgSys_tiDwellSpBenchMod, u16LocalIgSys_tiDwellSpBenchMod);
      /*QAC Warning Msg(2:3353): u16LocalIgSys_tiDwellSpBenchMod is protected by
           flag bLocalIDwellFlagUpdate in case if it has not been set         */
   }
}
/*QAC Warning Msg(2:4700): Complexity Accepted                                */

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidIgnitionArbitration                               */
/* !Description :  En mode nominal (IgSys_bIgBenchModEna_C = 0) on recopie les*/
/*                 consignes d’avance à l’allumage provenant de la  chaîne    */
/*                 d’avance.                                                  */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean IgSys_bIgBenchModEna;                                       */
/*  input uint8 IgSys_agIgSpNxtBenchMod;                                      */
/*  input uint8 IgSys_agIgSpBenchMod;                                         */
/*  input uint8 IgSys_agIgSpNxt;                                              */
/*  input uint8 IgSys_agIgSp;                                                 */
/*  input boolean IgSys_bAcvBenchModCmpnIg_C;                                 */
/*  input boolean IGARB_bAcvBenchModCmpnIgPrev;                               */
/*  input uint8 IgSys_NrCmpnCyl_C;                                            */
/*  input uint8 IgSys_CtrCylCmpn;                                             */
/*  input uint8 Eng_noCmprCyl;                                                */
/*  input uint8 IgSys_agigTestCyl[3];                                         */
/*  output uint8 IgCmd_agIgSpNxt;                                             */
/*  output uint8 IgSys_CtrCylCmpn;                                            */
/*  output uint8 IgCmd_agIgSp;                                                */
/*  output boolean IGARB_bAcvBenchModCmpnIgPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidIgnitionArbitration(void)
{
   boolean  bLocalIgSys_bIgBenchModEna;
   boolean  bLocalFlagIgCmdagIgSp;
   uint8    u8LocalIgSys_agIgSp;
   uint8    u8LocalIgSys_agIgSpNxt;
   uint8    u8LocalIgCmdagIgSp;
   uint8    u8LocalIgSys_agigTestCyl;
   uint8    u8LocalIgCmd_agIgSp;
   uint8    u8LocalIgCmd_agIgSpNxt;
   uint8    u8LocalEng_noCmprCyl;
   sint16   s16LocalIgCmd_agIgSp;
   sint16   s16LocalIgSys_CtrCylCmpn;


   bLocalFlagIgCmdagIgSp = 0;
   VEMS_vidGET(IgSys_bIgBenchModEna, bLocalIgSys_bIgBenchModEna);
   if(bLocalIgSys_bIgBenchModEna != 0)
   {
      u8LocalIgCmd_agIgSpNxt = IgSys_agIgSpNxtBenchMod;
      u8LocalIgCmdagIgSp = IgSys_agIgSpBenchMod;
   }
   else
   {
      VEMS_vidGET(IgSys_agIgSpNxt, u8LocalIgSys_agIgSpNxt);
      u8LocalIgCmd_agIgSpNxt = u8LocalIgSys_agIgSpNxt;
      VEMS_vidGET(IgSys_agIgSp, u8LocalIgSys_agIgSp);
      u8LocalIgCmdagIgSp = u8LocalIgSys_agIgSp;
   }
   VEMS_vidSET(IgCmd_agIgSpNxt, u8LocalIgCmd_agIgSpNxt);
   if (  (IgSys_bAcvBenchModCmpnIg_C != 0)
      && (IGARB_bAcvBenchModCmpnIgPrev == 0))
   {
      IgSys_CtrCylCmpn = IgSys_NrCmpnCyl_C;
   }
   else
   {
      s16LocalIgSys_CtrCylCmpn = (sint16)(IgSys_CtrCylCmpn - 1);
      IgSys_CtrCylCmpn = (uint8)MATHSRV_udtMAX(s16LocalIgSys_CtrCylCmpn, 0);
   }
   if (IgSys_CtrCylCmpn > 0)
   {

      VEMS_vidGET(Eng_noCmprCyl, u8LocalEng_noCmprCyl);
      switch(u8LocalEng_noCmprCyl)
      {
        case 1:
        case 2:
        case 3:
        u8LocalIgSys_agigTestCyl = IgSys_agigTestCyl[u8LocalEng_noCmprCyl - 1];
        break;

        default:
        bLocalFlagIgCmdagIgSp = 1;
        SWFAIL_vidSoftwareErrorHook();
        break;
      }

      if (bLocalFlagIgCmdagIgSp == 0)
      {
         /*QAC Warning Msg(2:3353) : u8LocalIgSys_agigTestCyl is protected by
         flag bLocalFlagIgCmdagIgSp in case if it has not been set*/
         s16LocalIgCmd_agIgSp = (sint16)( ( u8LocalIgSys_agigTestCyl
                                          + u8LocalIgCmdagIgSp)
                                        - 96);
      u8LocalIgCmd_agIgSp =
         (uint8)MATHSRV_udtCLAMP(s16LocalIgCmd_agIgSp, 0, 255);
      VEMS_vidSET(IgCmd_agIgSp, u8LocalIgCmd_agIgSp);
      }
   }
   else
   {
      VEMS_vidSET(IgCmd_agIgSp, u8LocalIgCmdagIgSp);
   }
   IGARB_bAcvBenchModCmpnIgPrev = IgSys_bAcvBenchModCmpnIg_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IgArb_vidMngBenchMod                                       */
/* !Description :  export of authorization of bench mode                      */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IgSys_bIgBenchModEna_C;                                     */
/*  output boolean IgSys_bIgBenchModEna;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IgArb_vidMngBenchMod(void)
{
   boolean bLocalIgSys_bIgBenchModEna;
   if (IgSys_bIgBenchModEna_C != 0)
   {
      bLocalIgSys_bIgBenchModEna = 1;
   }
   else
   {
      bLocalIgSys_bIgBenchModEna = 0;
   }

   VEMS_vidSET(IgSys_bIgBenchModEna, bLocalIgSys_bIgBenchModEna);
}
/******************************************************************************/