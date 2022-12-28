/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : AIRTQEFF                                                */
/* !Description     : AIRTQEFF component                                      */
/*                                                                            */
/* !Module          : AIRTQEFF                                                */
/* !Description     : Calcul du rendement pour la transformation couple /     */
/*                    masse d_air                                             */
/*                                                                            */
/* !File            : AIRTQEFF_FCT1.C                                         */
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
/*   1 / AIRTQEFF_vidInitOutput                                               */
/*   2 / AIRTQEFF_vidInit_rendement                                           */
/*   3 / AIRTQEFF_vidInit_rendement_cycle                                     */
/*   4 / AIRTQEFF_vidInit_afr_efficicency                                     */
/*   5 / AIRTQEFF_vidinit_egr_efficicency                                     */
/*   6 / AIRTQEFF_vidCalc_rendement                                           */
/*   7 / AIRTQEFF_vidCalc_rendement_cyc                                       */
/*   8 / AIRTQEFF_vidCalc_rendement_Afr                                       */
/*   9 / AIRTQEFF_vidCalc_rendement_EGR                                       */
/*                                                                            */
/* !Reference   : V02 NT 10 07791 / 02                                        */
/* !OtherRefs   : CSMT_CGMT09_0475_2 / 1.1                                    */
/* !OtherRefs   : VEMS V02 ECU#051747                                         */
/* !OtherRefs   : VEMS V02 ECU#058235                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/AIR/AIRTQEFF/AIRTQEFF_FCT1$*/
/* $Revision::   1.6.1.1  $$Author::   mbenfrad       $$Date::   05 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   05 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "AIRTQEFF.h"
#include "AIRTQEFF_L.h"
#include "AIRTQEFF_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des sorties des blocs dynamiques */
/*                 au reset                                                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  B. JARRAYA                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 FARSp_rMixtCylSp;                                            */
/*  input uint16 Inj_rlamEng_A[9];                                            */
/*  input uint16 AirSys_effAfr_T[9];                                          */
/*  input uint16 IgSys_rlamClc;                                               */
/*  input uint16 FARSp_rMixtFullLdSpRaw;                                      */
/*  input uint16 EGRSys_rEGRReq;                                              */
/*  input uint16 AirSys_rEGR_A[9];                                            */
/*  input uint8 AirSys_effEGR_T[9];                                           */
/*  output uint16 AirSys_prm_effAfrClc[3];                                    */
/*  output uint8 AirSys_effEGRClc;                                            */
/*  output uint16 AirSys_tqIdcHPCal1;                                         */
/*  output uint16 AirSys_tqIdcHPCal2;                                         */
/*  output uint16 AirSys_tqIdcHPCal3;                                         */
/*  output uint16 AirSys_tqIdcHPCal4;                                         */
/*  output uint16 AirSys_tqIdcHPCal5;                                         */
/*  output uint16 AirSys_tqIdcHPCal6;                                         */
/*  output uint16 AirSys_tqIdcHPCal7;                                         */
/*  output uint16 AirSys_tqIdcHPCal8;                                         */
/*  output uint16 AirSys_tqIdcHPCal9;                                         */
/*  output uint16 AirSys_tqIdcHPCal10;                                        */
/*  output uint16 AirSys_tqIdcHPCal11;                                        */
/*  output uint16 AirSys_tqIdcHPCal12;                                        */
/*  output uint16 AirSys_tqIdcHPCal13;                                        */
/*  output uint16 AirSys_tqIdcHPCal14;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidInitOutput(void)
{
   uint16 u16LocalEGRSys_rEGRReq;
   uint16 u16LocalFARSp_rMixtCylSp;
   uint16 u16LocalInput;
   uint16 u16localCalcPara;
   uint16 u16LocalIgSys_rlamClc;
   uint16 u16LocalFARSp_rMixtFullLdSpRaw;
   uint16 u16LocalInterp1d;


   /*Initialisation of the first element of the afr efficiency
      RateLimiter output*/
   VEMS_vidGET(FARSp_rMixtCylSp, u16LocalFARSp_rMixtCylSp);
   if (u16LocalFARSp_rMixtCylSp <= 60128)
   {
      u16LocalInput = (uint16)((u16LocalFARSp_rMixtCylSp * 400) / 367);
   }
   else
   {
      u16LocalInput = 65535;
   }

   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalInput,
                                                   9);
   u16LocalInterp1d = MATHSRV_u16Interp1d(AirSys_effAfr_T, u16localCalcPara);
   AirSys_prm_effAfrClc[0] = u16LocalInterp1d;

   /*Initialisation of the second element of the afr efficiency
      RateLimiter output*/
   VEMS_vidGET(IgSys_rlamClc, u16LocalIgSys_rlamClc);
   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalIgSys_rlamClc,
                                                   9);
   u16LocalInterp1d = MATHSRV_u16Interp1d(AirSys_effAfr_T, u16localCalcPara);
   AirSys_prm_effAfrClc[1] = u16LocalInterp1d;

   /*Initialisation of the third element of the afr efficiency
    RateLimiter output*/
   VEMS_vidGET(FARSp_rMixtFullLdSpRaw, u16LocalFARSp_rMixtFullLdSpRaw);
   if (u16LocalFARSp_rMixtFullLdSpRaw <= 60128)
   {
      u16LocalInput = (uint16)((u16LocalFARSp_rMixtFullLdSpRaw * 400) / 367);
   }
   else
   {
      u16LocalInput = 65535;
   }
   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(Inj_rlamEng_A,
                                                   u16LocalInput,
                                                   9);
   u16LocalInterp1d = MATHSRV_u16Interp1d(AirSys_effAfr_T, u16localCalcPara);
   AirSys_prm_effAfrClc[2] = u16LocalInterp1d;

   /*Initialisation of the egr efficiency RateLimiter output*/
   VEMS_vidGET(EGRSys_rEGRReq, u16LocalEGRSys_rEGRReq);
   u16localCalcPara = MATHSRV_u16CalcParaIncAryU16(AirSys_rEGR_A,
                                                   u16LocalEGRSys_rEGRReq,
                                                   9);
   AirSys_effEGRClc = MATHSRV_u8Interp1d(AirSys_effEGR_T, u16localCalcPara);

   /*Initialisation of the used before set internal variables*/
   AirSys_tqIdcHPCal1 = 0;
   AirSys_tqIdcHPCal2 = 0;
   AirSys_tqIdcHPCal3 = 0;
   AirSys_tqIdcHPCal4 = 0;
   AirSys_tqIdcHPCal5 = 0;
   AirSys_tqIdcHPCal6 = 0;
   AirSys_tqIdcHPCal7 = 0;
   AirSys_tqIdcHPCal8 = 0;
   AirSys_tqIdcHPCal9 = 0;
   AirSys_tqIdcHPCal10 = 0;
   AirSys_tqIdcHPCal11 = 0;
   AirSys_tqIdcHPCal12 = 0;
   AirSys_tqIdcHPCal13 = 0;
   AirSys_tqIdcHPCal14 = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidInit_rendement                                 */
/* !Description :  La fonction est constituée de 3 blocs où sont calculés les */
/*                 valeurs initiales des différents rendements                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidInit_rendement_cycle();                      */
/*  extf argret void AIRTQEFF_vidInit_afr_efficicency();                      */
/*  extf argret void AIRTQEFF_vidinit_egr_efficicency();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidInit_rendement(void)
{
   AIRTQEFF_vidInit_rendement_cycle();
   AIRTQEFF_vidInit_afr_efficicency();
   AIRTQEFF_vidinit_egr_efficicency();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidInit_rendement_cycle                           */
/* !Description :  Ce bloc permet de calculer la valeur initiale du rendement */
/*                 de cycle                                                   */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 AirSys_effCycIni_C;                                          */
/*  output uint16 AirSys_effCyc;                                              */
/*  output uint16 AirSys_effCycIni_C;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidInit_rendement_cycle(void)
{
   VEMS_vidSET(AirSys_effCyc, AirSys_effCycIni_C);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidInit_afr_efficicency                           */
/* !Description :  Ce bloc permet de calculer la valeur initiale du rendement */
/*                 de richesse                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 AirSys_effAfr;                                              */
/*  output uint32 AirSys_rClcLamEfc;                                          */
/*  output uint32 AirSys_rFullLdLamEfc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidInit_afr_efficicency(void)
{
   VEMS_vidSET(AirSys_effAfr, 32768);
   VEMS_vidSET(AirSys_rClcLamEfc, 32768);
   VEMS_vidSET(AirSys_rFullLdLamEfc, 32768);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidinit_egr_efficicency                           */
/* !Description :  Ce bloc permet de calculer la valeur initiale du rendement */
/*                 d’EGR                                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 AirSys_effEGR;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidinit_egr_efficicency(void)
{
   VEMS_vidSET(AirSys_effEGR, 128);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_rendement                                 */
/* !Description :  La fonction est constituée de 3 blocs où sont calculées les*/
/*                 valeurs des différents rendements                          */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidCalc_rendement_cyc();                        */
/*  extf argret void AIRTQEFF_vidCalc_rendement_Afr();                        */
/*  extf argret void AIRTQEFF_vidCalc_rendement_EGR();                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_rendement(void)
{
   AIRTQEFF_vidCalc_rendement_cyc();
   AIRTQEFF_vidCalc_rendement_Afr();
   AIRTQEFF_vidCalc_rendement_EGR();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_rendement_cyc                             */
/* !Description :  La fonction est constituée de 6 blocs permettant de        */
/*                 calculer le rendement de cycle                             */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidUnvectorize_Mode();                          */
/*  extf argret void AIRTQEFF_vidMode_Mask();                                 */
/*  extf argret void AIRTQEFF_vidCalibrations();                              */
/*  extf argret void AIRTQEFF_vidSelect_Modes();                              */
/*  extf argret void AIRTQEFF_vidInterpolation();                             */
/*  extf argret void AIRTQEFF_vidCoordination_1();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_rendement_cyc(void)
{
   AIRTQEFF_vidUnvectorize_Mode();
   AIRTQEFF_vidMode_Mask();
   AIRTQEFF_vidCalibrations();
   AIRTQEFF_vidSelect_Modes();
   AIRTQEFF_vidInterpolation();
   AIRTQEFF_vidCoordination_1();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_rendement_Afr                             */
/* !Description :  Ce bloc permet de calculer la valeur du rendement de       */
/*                 richesse                                                   */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_031.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidCalc_afr_efficiency();                       */
/*  extf argret void AIRTQEFF_vidCoordination_2();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_rendement_Afr(void)
{
   AIRTQEFF_vidCalc_afr_efficiency();
   AIRTQEFF_vidCoordination_2();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  AIRTQEFF_vidCalc_rendement_EGR                             */
/* !Description :  Ce bloc permet de calculer la valeur initiale du rendement */
/*                 d’EGR                                                      */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  B. JARRAYA                                                 */
/* !Trace_To    :  VEMS_R_10_07791_034.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void AIRTQEFF_vidCalc_egr_efficiency();                       */
/*  extf argret void AIRTQEFF_vidCoordination_3();                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void AIRTQEFF_vidCalc_rendement_EGR(void)
{
   AIRTQEFF_vidCalc_egr_efficiency();
   AIRTQEFF_vidCoordination_3();
}
/*---------------------------------end of file--------------------------------*/