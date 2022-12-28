/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : PDSTHRCHK                                               */
/* !Description     : PDSTHRCHK Component.                                    */
/*                                                                            */
/* !Module          : PDSTHRCHK                                               */
/* !Description     : Safety TMS : Sécuriser Pression Admission.              */
/*                                                                            */
/* !File            : PDSTHRCHK_FCT1.C                                        */
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
/*   1 / PDSTHRCHK_vidInitOutput                                              */
/*   2 / PDSTHRCHK_vidEstimPresAdmission                                      */
/*   3 / PDSTHRCHK_vidEstimOffAppSec                                          */
/*   4 / PDSTHRCHK_vidSecurPressSensor                                        */
/*   5 / PDSTHRCHK_vidCompSecurisation                                        */
/*                                                                            */
/* !Reference   : PTS_DOC_5050542 / 02                                        */
/* !OtherRefs   : CSCT_CGMT09_2405 / 1.4                                      */
/* !OtherRefs   : VEMS V02 ECU#065902                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TMS/PDSTHRCHK/PDSTHRCHK_FC$*/
/* $Revision::   1.5      $$Author::   mbenfrad       $$Date::   02 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   02 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "PDSTHRCHK.h"
#include "PDSTHRCHK_L.h"
#include "PDSTHRCHK_IM.h"
#include "VEMS.h"

#define TMS_START_SEC_CODE
#include "MemMap.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidInitOutput                                    */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_rOpTrbActReqTrbAct;                                  */
/*  input uint16 SftyMgt_rOpTrbActReqFil_MP;                                  */
/*  input uint16 SftyMgt_posnThr;                                             */
/*  input uint16 PDSTHRCHK_u16OutputFilter2;                                  */
/*  output boolean SftyMgt_bDgoPresDsThr;                                     */
/*  output uint16 SftyMgt_rOpTrbActReqFil_MP;                                 */
/*  output uint32 PDSTHRCHK_u32FiltredTrbActReqMem;                           */
/*  output boolean PDSTHRCHK_bFiltredExtMesSI;                                */
/*  output uint16 PDSTHRCHK_u16SftyMgtAcReqFilPrev;                           */
/*  output uint16 PDSTHRCHK_u16OutputFilter2;                                 */
/*  output uint32 PDSTHRCHK_u32FiltredposnThrMem;                             */
/*  output uint16 PDSTHRCHK_u16tiDlyPresDsThrOn;                              */
/*  output uint16 PDSTHRCHK_u16tiDlyAirExtDft;                                */
/*  output uint16 PDSTHRCHK_u16tiDlyGrdAirExtDft;                             */
/*  output boolean SftyMgt_bDgoPresDsThr_MP;                                  */
/*  output boolean SftyMgt_bDgoAirExt_MP;                                     */
/*  output boolean SftyMgt_bDgoGrdAirExt_MP;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidInitOutput(void)
{
   uint16 u16LocalSftyMgtrOpTrbActRqTrbAct;
   uint16 u16LocalSftyMgt_posnThr;


   /*Output_Initialisation*/
   VEMS_vidSET(SftyMgt_bDgoPresDsThr, 0);
   /*filter_Initialisation*/
   VEMS_vidGET(SftyMgt_rOpTrbActReqTrbAct, u16LocalSftyMgtrOpTrbActRqTrbAct);
   SftyMgt_rOpTrbActReqFil_MP = u16LocalSftyMgtrOpTrbActRqTrbAct;
   PDSTHRCHK_u32FiltredTrbActReqMem =
      (uint32)(SftyMgt_rOpTrbActReqFil_MP * 65536);
   PDSTHRCHK_bFiltredExtMesSI = 0;
   PDSTHRCHK_u16SftyMgtAcReqFilPrev = 0;

   VEMS_vidGET(SftyMgt_posnThr, u16LocalSftyMgt_posnThr);
   PDSTHRCHK_u16OutputFilter2 =
      (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_posnThr, 1000);
   PDSTHRCHK_u32FiltredposnThrMem =
      (uint32)(PDSTHRCHK_u16OutputFilter2 * 65536);

   /*Turn_On_Delay_Simple_Initialisation*/
   PDSTHRCHK_u16tiDlyPresDsThrOn = 0;
   PDSTHRCHK_u16tiDlyAirExtDft = 0;
   PDSTHRCHK_u16tiDlyGrdAirExtDft = 0;
   SftyMgt_bDgoPresDsThr_MP = 0;
   SftyMgt_bDgoAirExt_MP = 0;
   SftyMgt_bDgoGrdAirExt_MP = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidEstimPresAdmission                            */
/* !Description :  Estimation de la pression admission en fonction du régime  */
/*                 moteur et du pourcentage d’ouverture du papillon.          */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_002.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_posnThr;                                             */
/*  input uint16 SftyMgt_tiPosnThrFil_C;                                      */
/*  input uint32 PDSTHRCHK_u32FiltredposnThrMem;                              */
/*  input uint16 SftyMgt_rOpTrbActReqTrbAct;                                  */
/*  input uint16 PDSTHRCHK_u16SftyMgtAcReqFilPrev;                            */
/*  input uint16 SftyMgt_rOpTrbActReqGrd_MP;                                  */
/*  input uint16 SftyMgt_rOpTrbActReqGrdThd_C;                                */
/*  input uint16 SftyMgt_tiOpTrbActFilUp_C;                                   */
/*  input uint16 SftyMgt_tiOpTrbActFilDown_C;                                 */
/*  input uint16 SftyMgt_rOpTrbActReqFil_MP;                                  */
/*  input uint32 PDSTHRCHK_u32FiltredTrbActReqMem;                            */
/*  input uint16 SftyMgt_pAirExtMesCorUsThrM;                                 */
/*  input uint16 SftyMgt_pAirExt_A[10];                                       */
/*  input uint8 SftyMgt_facAirExtCor_T[10];                                   */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input uint16 SftyMgt_nCkFilSftyPresX_A[8];                                */
/*  input uint16 PDSTHRCHK_u16OutputFilter2;                                  */
/*  input uint16 SftyMgt_posnThrSftyPresY_A[8];                               */
/*  input uint16 SftyMgt_pDsThrEstimBas1_M[8][8];                             */
/*  input uint16 SftyMgt_pDsThrEstimBas2_M[8][8];                             */
/*  input uint16 SftyMgt_nCkFilTrbActX_A[8];                                  */
/*  input uint16 SftyMgt_rOpTrbActFilY_A[8];                                  */
/*  input uint16 SftyMgt_pTrbActCorBas1_M[8][8];                              */
/*  input uint16 SftyMgt_pTrbActCorBas2_M[8][8];                              */
/*  input uint16 SftyMgt_pTrbActCor_MP;                                       */
/*  input uint16 SftyMgt_pPosnThr_MP;                                         */
/*  output uint32 PDSTHRCHK_u32FiltredposnThrMem;                             */
/*  output uint16 PDSTHRCHK_u16OutputFilter2;                                 */
/*  output uint16 SftyMgt_rOpTrbActReqGrd_MP;                                 */
/*  output uint16 SftyMgt_rOpTrbActReqFil_MP;                                 */
/*  output uint32 PDSTHRCHK_u32FiltredTrbActReqMem;                           */
/*  output uint16 PDSTHRCHK_u16SftyMgtAcReqFilPrev;                           */
/*  output uint16 SftyMgt_pPosnThr_MP;                                        */
/*  output uint16 SftyMgt_pTrbActCor_MP;                                      */
/*  output uint16 SftyMgt_pDsThrEstim;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidEstimPresAdmission(void)
{
   uint8  u8Localcalcinterp;
   uint16 u16LocalSftyMgtrOpTrbActRqTrbAct;
   uint16 u16LocalFilterGain;
   uint16 u16LocalFiltredValue;
   uint16 u16LocalSftyMgt_nCkFil;
   uint16 u16LocalSftyMgt_posnThr;
   uint16 u16LocalSfyMgtpArExMsCrUsThrM;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16Local_calc_interp_1;
   uint16 u16Local_calc_interp_2;
   uint16 u16Local_calc_interp_3;
   uint16 u16Local_calc_interp_4;
   uint16 u16LocalinputFiltrValue;
   uint32 u32LocalFilterGain;
   uint32 u32LocalpDsThrEstim;
   sint32 s32LocalSftyMgt_soustrac_comp;
   sint32 s32LocalSftyMgt_pTrbActCor;
   sint32 s32LocalSftyMgt_pPosnThr_MP;


   /* Filter_T2 */
   VEMS_vidGET(SftyMgt_posnThr, u16LocalSftyMgt_posnThr);
   if (SftyMgt_tiPosnThrFil_C == 0)
   {
      u16LocalFiltredValue =
         (uint16)MATHSRV_udtMIN(u16LocalSftyMgt_posnThr, 1000);
      PDSTHRCHK_u32FiltredposnThrMem =
         (uint32)(u16LocalFiltredValue * 65536);
   }
   else
   {
      u16LocalFilterGain = (uint16)( SftyMgt_tiSdlPresDsThr_SC
                                   + ( SftyMgt_tiPosnThrFil_C
                                     * 10));
      u16LocalFilterGain = (uint16)( ( SftyMgt_tiSdlPresDsThr_SC
                                     * 65536)
                                   / u16LocalFilterGain);
      u16LocalFiltredValue =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &PDSTHRCHK_u32FiltredposnThrMem,
                                         u16LocalSftyMgt_posnThr);
   }
   PDSTHRCHK_u16OutputFilter2 =
      (uint16)MATHSRV_udtMIN(u16LocalFiltredValue, 1000);

   /*calcul_intput_filter_T1*/
   VEMS_vidGET(SftyMgt_rOpTrbActReqTrbAct, u16LocalSftyMgtrOpTrbActRqTrbAct);
   s32LocalSftyMgt_soustrac_comp = (sint32)( u16LocalSftyMgtrOpTrbActRqTrbAct
                                           - PDSTHRCHK_u16SftyMgtAcReqFilPrev);
   SftyMgt_rOpTrbActReqGrd_MP =
      (uint16)MATHSRV_udtMAX(s32LocalSftyMgt_soustrac_comp,0);
   if (SftyMgt_rOpTrbActReqGrd_MP >= SftyMgt_rOpTrbActReqGrdThd_C)
   {
      u16LocalinputFiltrValue = SftyMgt_tiOpTrbActFilUp_C;
   }
   else
   {
      u16LocalinputFiltrValue = SftyMgt_tiOpTrbActFilDown_C;
   }

   /* Filter_T1 */
   if (u16LocalinputFiltrValue == 0)
   {
      SftyMgt_rOpTrbActReqFil_MP = u16LocalSftyMgtrOpTrbActRqTrbAct;
      PDSTHRCHK_u32FiltredTrbActReqMem =
         (uint32)(SftyMgt_rOpTrbActReqFil_MP * 65536);
   }
   else
   {
      u32LocalFilterGain = (uint32)( SftyMgt_tiSdlPresDsThr_SC
                                   + ( u16LocalinputFiltrValue
                                     * 10));
      u16LocalFilterGain = (uint16)( ( SftyMgt_tiSdlPresDsThr_SC
                                     * 65536)
                                   / u32LocalFilterGain);
      SftyMgt_rOpTrbActReqFil_MP =
         MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                         &PDSTHRCHK_u32FiltredTrbActReqMem,
                                         u16LocalSftyMgtrOpTrbActRqTrbAct);
   }
   PDSTHRCHK_u16SftyMgtAcReqFilPrev = SftyMgt_rOpTrbActReqFil_MP;

   VEMS_vidGET(SftyMgt_pAirExtMesCorUsThrM, u16LocalSfyMgtpArExMsCrUsThrM);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_pAirExt_A,
                                                u16LocalSfyMgtpArExMsCrUsThrM,
                                                10);
   u8Localcalcinterp = MATHSRV_u8Interp1d(SftyMgt_facAirExtCor_T,
                                          u16LocalParaX);

   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgt_nCkFil);
   /*Production of SftyMgt_pPosnThr_MP*/
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFilSftyPresX_A,
                                                u16LocalSftyMgt_nCkFil,
                                                8);
   u16LocalParaY = (uint16)(PDSTHRCHK_u16OutputFilter2 * 10);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_posnThrSftyPresY_A,
                                                u16LocalParaY,
                                                8);
   u16Local_calc_interp_1 =
      MATHSRV_u16Interp2d(&SftyMgt_pDsThrEstimBas1_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          8);
   u16Local_calc_interp_2 =
      MATHSRV_u16Interp2d(&SftyMgt_pDsThrEstimBas2_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          8);
   s32LocalSftyMgt_pPosnThr_MP = (  (  (  ( u16Local_calc_interp_1
                                          - u16Local_calc_interp_2)
                                       * u8Localcalcinterp)
                                    + (u16Local_calc_interp_2 * 10))
                                 / 10);
   SftyMgt_pPosnThr_MP =
      (uint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_pPosnThr_MP, 0, 65535);

   /*Production of SftyMgt_pTrbActCor_MP */
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFilTrbActX_A,
                                                u16LocalSftyMgt_nCkFil,
                                                8);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(SftyMgt_rOpTrbActFilY_A,
                                                SftyMgt_rOpTrbActReqFil_MP,
                                                8);
   u16Local_calc_interp_3 = MATHSRV_u16Interp2d(&SftyMgt_pTrbActCorBas1_M[0][0],
                                                u16LocalParaX,
                                                u16LocalParaY,
                                                8);
   u16Local_calc_interp_4 = MATHSRV_u16Interp2d(&SftyMgt_pTrbActCorBas2_M[0][0],
                                                u16LocalParaX,
                                                u16LocalParaY,
                                                8);

   s32LocalSftyMgt_pTrbActCor = (  (  (  ( u16Local_calc_interp_3
                                         - u16Local_calc_interp_4)
                                      * u8Localcalcinterp)
                                   + (u16Local_calc_interp_4 * 10))
                                / 10);
   SftyMgt_pTrbActCor_MP =
      (uint16)MATHSRV_udtCLAMP(s32LocalSftyMgt_pTrbActCor, 0, 65535);

   /*Procution of SftyMgt_pDsThrEstim*/
   u32LocalpDsThrEstim = SftyMgt_pTrbActCor_MP + SftyMgt_pPosnThr_MP;
   SftyMgt_pDsThrEstim = (uint16)MATHSRV_udtMIN(u32LocalpDsThrEstim, 65535);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidEstimOffAppSec                                */
/* !Description :  Estimation de l’offset de comparaison en fonction du régime*/
/*                 moteur et du pourcentage d’ouverture du papillon.          */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_003.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_nCkFil;                                              */
/*  input uint16 SftyMgt_posnThr;                                             */
/*  input uint16 SftyMgt_nCkFilSftyPresX_A[8];                                */
/*  input uint16 SftyMgt_posnThrSftyPresY_A[8];                               */
/*  input uint16 SftyMgt_pDsThrOfs_M[8][8];                                   */
/*  input boolean SftyMgt_bEnaPresOffsSfty;                                   */
/*  input uint16 SftyMgt_nPresOffsSfty_A[8];                                  */
/*  input uint16 SftyMgt_pOffsSfty_T[8];                                      */
/*  output uint16 SftyMgt_pDsThrOfs;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidEstimOffAppSec(void)
{
   boolean bLocalSftyMgt_bEnaPresOffsSfty;
   uint16  u16LocalSftyMgt_nCkFil;
   uint16  u16LocalSftyMgt_posnThr;
   uint16  u16LocalParaX_1;
   uint16  u16LocalParaY_1;
   uint16  u16Local_calc_interp_1;
   uint16  u16LocalParaX_2;
   uint16  u16Local_calc_interp_2;
   uint32  u32LocalSftyMgt_posnThr;
   uint32  u32LocalSftyMgt_pDsThrOfs;


   VEMS_vidGET(SftyMgt_nCkFil, u16LocalSftyMgt_nCkFil);
   VEMS_vidGET(SftyMgt_posnThr, u16LocalSftyMgt_posnThr);

   u16LocalParaX_1 = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nCkFilSftyPresX_A,
                                                  u16LocalSftyMgt_nCkFil,
                                                  8);
   u32LocalSftyMgt_posnThr = (uint32)(u16LocalSftyMgt_posnThr * 10);
   u16LocalSftyMgt_posnThr =
      (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_posnThr, 65535);
   u16LocalParaY_1 = MATHSRV_u16CalcParaIncAryU16(SftyMgt_posnThrSftyPresY_A,
                                                  u16LocalSftyMgt_posnThr,
                                                  8);
   u16Local_calc_interp_1 = MATHSRV_u16Interp2d(&SftyMgt_pDsThrOfs_M[0][0],
                                                u16LocalParaX_1,
                                                u16LocalParaY_1,
                                                8);

   VEMS_vidGET(SftyMgt_bEnaPresOffsSfty, bLocalSftyMgt_bEnaPresOffsSfty);
   if (bLocalSftyMgt_bEnaPresOffsSfty != 0)
   {
      u16LocalParaX_2 = MATHSRV_u16CalcParaIncAryU16(SftyMgt_nPresOffsSfty_A,
                                                     u16LocalSftyMgt_nCkFil,
                                                     8);
      u16Local_calc_interp_2 = MATHSRV_u16Interp1d(SftyMgt_pOffsSfty_T,
                                                   u16LocalParaX_2);
   }
   else
   {
      u16Local_calc_interp_2 = 0;
   }
   u32LocalSftyMgt_pDsThrOfs =
      (uint32)(u16Local_calc_interp_1 + u16Local_calc_interp_2);
   SftyMgt_pDsThrOfs = (uint16)MATHSRV_udtMIN(u32LocalSftyMgt_pDsThrOfs, 65535);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidSecurPressSensor                              */
/* !Description :  Sécurisation des capteurs de pression par gradient et      */
/*                 comparaison                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 SftyMgt_pAirExtMesSI;                                        */
/*  input boolean PDSTHRCHK_bFiltredExtMesSI;                                 */
/*  input uint16 SftyMgt_pAirExtMesSIFil_MP;                                  */
/*  input uint16 SftyMgt_pAirExtMesCorUsThrM;                                 */
/*  input uint16 SftyMgt_pAirExtDftThd_C;                                     */
/*  input uint8 SftyMgt_tiAirExtFil_C;                                        */
/*  input uint32 PDSTHRCHK_u32FiltredExtMesSIMem;                             */
/*  input uint16 SftyMgt_pGrdAirExtDftThd_C;                                  */
/*  input boolean SftyMgt_bEnaPresOffsSfty;                                   */
/*  input boolean SftyMgt_bDftThdGrdAirExt_MP;                                */
/*  input boolean SftyMgt_bDftThdAirExt_MP;                                   */
/*  output uint16 SftyMgt_pAirExtMesSIFil_MP;                                 */
/*  output uint32 PDSTHRCHK_u32FiltredExtMesSIMem;                            */
/*  output boolean PDSTHRCHK_bFiltredExtMesSI;                                */
/*  output boolean SftyMgt_bDftThdAirExt_MP;                                  */
/*  output boolean SftyMgt_bDftThdGrdAirExt_MP;                               */
/*  output boolean SftyMgt_bDftGrdAirExt;                                     */
/*  output boolean SftyMgt_bDftAirExt;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidSecurPressSensor(void)
{
   boolean bLocalSftyMgt_bEnaPresOffsSfty;
   uint16  u16LocalSftyMgt_pAirExtMesSI;
   uint16  u16LocalSftyMgtpAirExtMsCrUsThrM;
   uint16  u16Local_soustract_Abs_1;
   uint16  u16LocalFilterGain;
   uint16  u16LocalFiltredValue;
   uint16  u16Local_soustract_Abs_2;
   sint32  s32Local_soustract_Abs_1;
   sint32  s32Local_soustract_Abs_2;


   VEMS_vidGET(SftyMgt_pAirExtMesSI, u16LocalSftyMgt_pAirExtMesSI);
   if (PDSTHRCHK_bFiltredExtMesSI == 0)
   {
      SftyMgt_pAirExtMesSIFil_MP = u16LocalSftyMgt_pAirExtMesSI;
      PDSTHRCHK_u32FiltredExtMesSIMem =
         (uint32)(SftyMgt_pAirExtMesSIFil_MP * 65536);
      PDSTHRCHK_bFiltredExtMesSI = 1;
   }
   else
   {
      /*Production_of_SftyMgt_pAirExtMesSIFil_MP*/
      u16LocalFilterGain = (uint16)( SftyMgt_tiSdlPresDsThr_SC
                                   + ( SftyMgt_tiAirExtFil_C
                                     * 10));
      if (SftyMgt_tiAirExtFil_C == 0)
      {
         u16LocalFiltredValue = u16LocalSftyMgt_pAirExtMesSI;
         PDSTHRCHK_u32FiltredExtMesSIMem =
            (uint32)(u16LocalFiltredValue * 65536);
      }
      else
      {
         u16LocalFilterGain = (uint16)( ( SftyMgt_tiSdlPresDsThr_SC
                                        * 65536)
                                      / u16LocalFilterGain);
         u16LocalFiltredValue =
            MATHSRV_u16FirstOrderFilterGu16(u16LocalFilterGain,
                                            &PDSTHRCHK_u32FiltredExtMesSIMem,
                                            u16LocalSftyMgt_pAirExtMesSI);
      }
      SftyMgt_pAirExtMesSIFil_MP = u16LocalFiltredValue;
   }
   /*Production_of_SftyMgt_bDftThdAirExt_MP*/
   VEMS_vidGET(SftyMgt_pAirExtMesCorUsThrM, u16LocalSftyMgtpAirExtMsCrUsThrM);
   s32Local_soustract_Abs_1 = (sint32)( u16LocalSftyMgt_pAirExtMesSI
                                       - u16LocalSftyMgtpAirExtMsCrUsThrM);
   u16Local_soustract_Abs_1 = (uint16)MATHSRV_udtABS(s32Local_soustract_Abs_1);
   if (u16Local_soustract_Abs_1 > SftyMgt_pAirExtDftThd_C)
   {
      SftyMgt_bDftThdAirExt_MP = 1;
   }
   else
   {
      SftyMgt_bDftThdAirExt_MP = 0;
   }

   /*Production_of_SftyMgt_bDftThdGrdAirExt_MP*/
   s32Local_soustract_Abs_2 =
      (sint32)(u16LocalSftyMgt_pAirExtMesSI - SftyMgt_pAirExtMesSIFil_MP);
   u16Local_soustract_Abs_2 =
      (uint16)MATHSRV_udtABS(s32Local_soustract_Abs_2);
   if (u16Local_soustract_Abs_2 > SftyMgt_pGrdAirExtDftThd_C)
   {
      SftyMgt_bDftThdGrdAirExt_MP = 1;
   }
   else
   {
      SftyMgt_bDftThdGrdAirExt_MP = 0;
   }
   /*Production_of_SftyMgt_bDftGrdAirExt et SftyMgt_bDftAirExt*/
   VEMS_vidGET(SftyMgt_bEnaPresOffsSfty, bLocalSftyMgt_bEnaPresOffsSfty);
   if (bLocalSftyMgt_bEnaPresOffsSfty != 0)
   {
      SftyMgt_bDftGrdAirExt = 0;
      SftyMgt_bDftAirExt = 0;
   }
   else
   {
      if (SftyMgt_bDftThdGrdAirExt_MP != 0)
      {
         SftyMgt_bDftGrdAirExt = 1;
      }
      else
      {
         SftyMgt_bDftGrdAirExt = 0;
      }
      if (SftyMgt_bDftThdAirExt_MP != 0)
      {
         SftyMgt_bDftAirExt = 1;
      }
      else
      {
         SftyMgt_bDftAirExt = 0;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  PDSTHRCHK_vidCompSecurisation                              */
/* !Description :  Comparaison entre la pression utilisée en entrée de        */
/*                 l’estimateur et la pression  estimée                       */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  DEMNI MOHAMED                                              */
/* !Trace_To    :  VEMS_R_10_01239_004.04                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SftyMgt_pDsThrCor;                                           */
/*  input uint16 SftyMgt_pDsThrOfs;                                           */
/*  input uint16 SftyMgt_pDsThrEstim;                                         */
/*  input uint8 SftyMgt_tiDlyPresDsThrOn_C;                                   */
/*  input boolean SftyMgt_bDftPresDsThr_MP;                                   */
/*  input uint16 PDSTHRCHK_u16tiDlyPresDsThrOn;                               */
/*  input uint8 SftyMgt_tiDlyAirExtDft_C;                                     */
/*  input boolean SftyMgt_bDftAirExt;                                         */
/*  input uint16 PDSTHRCHK_u16tiDlyAirExtDft;                                 */
/*  input uint8 SftyMgt_tiDlyGrdAirExtDft_C;                                  */
/*  input boolean SftyMgt_bDftGrdAirExt;                                      */
/*  input uint16 PDSTHRCHK_u16tiDlyGrdAirExtDft;                              */
/*  input boolean SftyMgt_bInhDftPresDsThr_C;                                 */
/*  input boolean SftyMgt_bDgoPresDsThr_MP;                                   */
/*  input boolean SftyMgt_bInhDftAirExt_C;                                    */
/*  input boolean SftyMgt_bDgoAirExt_MP;                                      */
/*  input boolean SftyMgt_bInhDftGrdAirExt_C;                                 */
/*  input boolean SftyMgt_bDgoGrdAirExt_MP;                                   */
/*  output boolean SftyMgt_bDftPresDsThr_MP;                                  */
/*  output uint16 PDSTHRCHK_u16tiDlyPresDsThrOn;                              */
/*  output boolean SftyMgt_bDgoPresDsThr_MP;                                  */
/*  output uint16 PDSTHRCHK_u16tiDlyAirExtDft;                                */
/*  output boolean SftyMgt_bDgoAirExt_MP;                                     */
/*  output uint16 PDSTHRCHK_u16tiDlyGrdAirExtDft;                             */
/*  output boolean SftyMgt_bDgoGrdAirExt_MP;                                  */
/*  output boolean SftyMgt_bDgoPresDsThr;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void PDSTHRCHK_vidCompSecurisation(void)
{
   boolean bLocal_Switch_1;
   boolean bLocal_Switch_2;
   boolean bLocal_Switch_3;
   boolean bLocalSftyMgt_bDgoPresDsThr;
   uint16  u16LocalSftyMgt_pDsThrCor;
   uint16  u16LocalSftyMgttiDlyPresDsThrOn;
   uint16  u16LocalMinTurnOnDelaySimple_1;
   uint16  u16LocalSftyMgttiDlyAirExtDft;
   uint16  u16LocalMinTurnOnDelaySimple_2;
   uint16  u16LocalSftyMgttiDlyGrdAirExtDft;
   uint16  u16LocalMinTurnOnDelaySimple_3;
   uint32  u32Local_add_Comp;


   /*Production_of_SftyMgt_bDftPresDsThr_MP*/
   VEMS_vidGET(SftyMgt_pDsThrCor, u16LocalSftyMgt_pDsThrCor);
   u32Local_add_Comp = (uint32)(SftyMgt_pDsThrOfs + SftyMgt_pDsThrEstim);
   if (u32Local_add_Comp < u16LocalSftyMgt_pDsThrCor)
   {
      SftyMgt_bDftPresDsThr_MP = 1;
   }
   else
   {
      SftyMgt_bDftPresDsThr_MP = 0;
   }

   /*Production_of_SftyMgt_bDgoPresDsThr_MP*/
   u16LocalSftyMgttiDlyPresDsThrOn = (uint16)(SftyMgt_tiDlyPresDsThrOn_C + 1);
   if (SftyMgt_bDftPresDsThr_MP == 0)
   {
      PDSTHRCHK_u16tiDlyPresDsThrOn = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple_1 =
         (uint16)MATHSRV_udtMIN(PDSTHRCHK_u16tiDlyPresDsThrOn,
                               u16LocalSftyMgttiDlyPresDsThrOn);
      PDSTHRCHK_u16tiDlyPresDsThrOn =
         (uint16)(u16LocalMinTurnOnDelaySimple_1 + 1);
   }
   if (PDSTHRCHK_u16tiDlyPresDsThrOn >= u16LocalSftyMgttiDlyPresDsThrOn)
   {
      SftyMgt_bDgoPresDsThr_MP = 1;
   }
   else
   {
      SftyMgt_bDgoPresDsThr_MP = 0;
   }
   /*Production_of_SftyMgt_bDgoAirExt_MP*/
   u16LocalSftyMgttiDlyAirExtDft = (uint16)(SftyMgt_tiDlyAirExtDft_C + 1);
   if (SftyMgt_bDftAirExt == 0)
   {
      PDSTHRCHK_u16tiDlyAirExtDft = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple_2 =
         (uint16)MATHSRV_udtMIN(PDSTHRCHK_u16tiDlyAirExtDft,
                               u16LocalSftyMgttiDlyAirExtDft);
      PDSTHRCHK_u16tiDlyAirExtDft =
         (uint16)(u16LocalMinTurnOnDelaySimple_2 + 1);
   }
   if (PDSTHRCHK_u16tiDlyAirExtDft >= u16LocalSftyMgttiDlyAirExtDft)
   {
      SftyMgt_bDgoAirExt_MP = 1;
   }
   else
   {
      SftyMgt_bDgoAirExt_MP = 0;
   }
   /*Production_of_SftyMgt_bDgoGrdAirExt_MP*/
   u16LocalSftyMgttiDlyGrdAirExtDft = (uint16)(SftyMgt_tiDlyGrdAirExtDft_C + 1);
   if (SftyMgt_bDftGrdAirExt == 0)
   {
      PDSTHRCHK_u16tiDlyGrdAirExtDft = 0;
   }
   else
   {
      u16LocalMinTurnOnDelaySimple_3 =
         (uint16)MATHSRV_udtMIN(PDSTHRCHK_u16tiDlyGrdAirExtDft,
                               u16LocalSftyMgttiDlyGrdAirExtDft);
      PDSTHRCHK_u16tiDlyGrdAirExtDft =
         (uint16)(u16LocalMinTurnOnDelaySimple_3 + 1);

   }
   if (PDSTHRCHK_u16tiDlyGrdAirExtDft >= u16LocalSftyMgttiDlyGrdAirExtDft)
   {
      SftyMgt_bDgoGrdAirExt_MP = 1;
   }
   else
   {
      SftyMgt_bDgoGrdAirExt_MP = 0;
   }
   /*Production_of_SftyMgt_bDgoPresDsThr*/
   if (SftyMgt_bInhDftPresDsThr_C != 0)
   {
      bLocal_Switch_1 = 0;
   }
   else
   {
      bLocal_Switch_1 = SftyMgt_bDgoPresDsThr_MP;
   }
   if (SftyMgt_bInhDftAirExt_C != 0)
   {
      bLocal_Switch_2 = 0;
   }
   else
   {
      bLocal_Switch_2 = SftyMgt_bDgoAirExt_MP;
   }
   if (SftyMgt_bInhDftGrdAirExt_C != 0)
   {
      bLocal_Switch_3 = 0;
   }
   else
   {
      bLocal_Switch_3 = SftyMgt_bDgoGrdAirExt_MP;
   }
   if (  (bLocal_Switch_1 != 0)
      || (bLocal_Switch_2 != 0)
      || (bLocal_Switch_3 != 0))
   {
      bLocalSftyMgt_bDgoPresDsThr = 1;
   }
   else
   {
      bLocalSftyMgt_bDgoPresDsThr = 0;
   }
   VEMS_vidSET(SftyMgt_bDgoPresDsThr, bLocalSftyMgt_bDgoPresDsThr);
}
#define TMS_STOP_SEC_CODE
#include "MemMap.h"
/*------------------------------- end of file --------------------------------*/