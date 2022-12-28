/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSSPBENCHMOD                                         */
/* !Description     : TQSYSSPBENCHMOD component.                              */
/*                                                                            */
/* !Module          : TQSYSSPBENCHMOD                                         */
/* !Description     : TORQUE SETPOINT CALCULATION IN BENCH MODE               */
/*                                                                            */
/* !File            : TQSYSSPBENCHMOD_fct.c                                   */
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
/*   1 / TQSYSSPBENCHMOD_vidInit_TqSpBenchMod                                 */
/*   2 / TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam                             */
/*   3 / TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod                            */
/*   4 / TQSYSSPBENCHMOD_vidComput_TqAirSpBenchMod                            */
/*   5 / TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod                            */
/*   6 / TQSYSSPBENCHMOD_vidComput_TqIgnSpBenchMod                            */
/*                                                                            */
/* !Reference   : V02 NT 09 08176 / 1                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error*/
#include "TQSYSSPBENCHMOD.h"
#include "TQSYSSPBENCHMOD_L.h"
#include "TQSYSSPBENCHMOD_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidInit_TqSpBenchMod                       */
/* !Description :  Outputs initializations                                    */
/* !Number      :  FCT.1.1                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqSys_tqIdcAirBenchModIniSp_C;                               */
/*  input sint16 TqSys_tqIdcIgnBenchModIniSp_C;                               */
/*  output sint16 TqSys_tqIdcAirSpBenchMod;                                   */
/*  output sint16 TqSys_tqIdcIgnSpBenchMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidInit_TqSpBenchMod(void)
{
   sint16 s16Local_TqSys_tqIdcAirSpBenchMod;
   sint16 s16Local_TqSys_tqIdcIgnSpBenchMod;

   s16Local_TqSys_tqIdcAirSpBenchMod =
      (sint16)MATHSRV_udtCLAMP(TqSys_tqIdcAirBenchModIniSp_C,-32000,32000);
   s16Local_TqSys_tqIdcIgnSpBenchMod =
      (sint16)MATHSRV_udtCLAMP(TqSys_tqIdcIgnBenchModIniSp_C,-32000,32000);

   VEMS_vidSET(TqSys_tqIdcAirSpBenchMod,s16Local_TqSys_tqIdcAirSpBenchMod);
   VEMS_vidSET(TqSys_tqIdcIgnSpBenchMod,s16Local_TqSys_tqIdcIgnSpBenchMod);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam                   */
/* !Number      :  FCT.1.2                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bTqSpBenchModEna_C;                                   */
/*  input boolean TqSys_bSelTqSpManModTyp_C;                                  */
/*  output boolean TqSys_bTqSpBenchModEna;                                    */
/*  output boolean TqSys_bTqSpBenchModEna_C;                                  */
/*  output boolean TqSys_bSelTqSpManModTyp;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidSet_TqSpBenchModParam(void)
{
   VEMS_vidSET(TqSys_bTqSpBenchModEna, TqSys_bTqSpBenchModEna_C);
   TqSys_bSelTqSpManModTyp = TqSys_bSelTqSpManModTyp_C;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod                  */
/* !Number      :  FCT.1.3                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQSYSSPBENCHMOD_vidComput_TqAirSpBenchMod();             */
/*  input boolean TqSys_bTqSpBenchModEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidManage_TqAirSpBenchMod(void)
{
   boolean bLocal_TqSys_bTqSpBenchModEna;

   VEMS_vidGET(TqSys_bTqSpBenchModEna,bLocal_TqSys_bTqSpBenchModEna);

   if (bLocal_TqSys_bTqSpBenchModEna != 0)
   {
      TQSYSSPBENCHMOD_vidComput_TqAirSpBenchMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidComput_TqAirSpBenchMod                  */
/* !Number      :  FCT.1.4                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bSelTqSpManModTyp;                                    */
/*  input sint16 TqSys_tqIdcAirManModSp_C;                                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint16 TqSys_nEngX_A[16];                                           */
/*  input uint8 TqSys_posnAccPY_A[16];                                        */
/*  input uint16 TqSys_tqAirSp_nEngX_posnAccPY_M[16][16];                     */
/*  input sint16 TqSys_tqIdcAirSpBenchMod;                                    */
/*  input uint16 TqSys_tqIdcAirMaxRate_C;                                     */
/*  input uint16 TqSys_tqIdcAirMinRate_C;                                     */
/*  output sint16 TqSys_tqIdcAirSpBenchMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidComput_TqAirSpBenchMod(void)
{
   uint16 u16Local_Regime_moteur;
   uint8  u8Local_Dv_position_pedale_relative;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16Local_TqSys_raw_tqIdcAirSpBenchMod;
   uint16 u16Local_TqSys_tqIdcAirSpBenchMod;
   sint16 s16Local_TqSys_tqIdcAirSpBenchMod;

   if (TqSys_bSelTqSpManModTyp != 0)
   {
      /* TqSys_tqIdcAirManModSp_C was converted to unsigned by
                 adding 32000 */
      u16Local_TqSys_raw_tqIdcAirSpBenchMod =
         (uint16)MATHSRV_udtMAX((sint32)(TqSys_tqIdcAirManModSp_C + 32000),0);
   }
   else
   {
      VEMS_vidGET(Regime_moteur,u16Local_Regime_moteur);
      VEMS_vidGET(Dv_position_pedale_relative,
                     u8Local_Dv_position_pedale_relative);

      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngX_A,
                                                   u16Local_Regime_moteur,
                                                   16);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(TqSys_posnAccPY_A,
                                           u8Local_Dv_position_pedale_relative,
                                           16);
      u16Local_TqSys_raw_tqIdcAirSpBenchMod =
         MATHSRV_u16Interp2d(&TqSys_tqAirSp_nEngX_posnAccPY_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             16);
   }

   VEMS_vidGET(TqSys_tqIdcAirSpBenchMod, s16Local_TqSys_tqIdcAirSpBenchMod);
   /* s16Local_TqSys_tqIdcAirSpBenchMod was
   converted to unsigned by adding 32000 */
   u16Local_TqSys_tqIdcAirSpBenchMod =
      (uint16)(s16Local_TqSys_tqIdcAirSpBenchMod + 32000);
   u16Local_TqSys_tqIdcAirSpBenchMod =
      MATHSRV_u16SlewFilter(u16Local_TqSys_tqIdcAirSpBenchMod,
                            u16Local_TqSys_raw_tqIdcAirSpBenchMod,
                            TqSys_tqIdcAirMaxRate_C,
                            TqSys_tqIdcAirMinRate_C);
   /* u16Local_TqSys_tqIdcAirSpBenchMod was converted to
   signed by subtracting 32000 */
   s16Local_TqSys_tqIdcAirSpBenchMod =
      (sint16)MATHSRV_udtMIN((sint32)(u16Local_TqSys_tqIdcAirSpBenchMod
                                     - 32000),32000);

   VEMS_vidSET(TqSys_tqIdcAirSpBenchMod, s16Local_TqSys_tqIdcAirSpBenchMod);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod                  */
/* !Number      :  FCT.1.5                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQSYSSPBENCHMOD_vidComput_TqIgnSpBenchMod();             */
/*  input boolean TqSys_bTqSpBenchModEna;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidManage_TqIgnSpBenchMod(void)
{
   boolean bLocal_TqSys_bTqSpBenchModEna;

   VEMS_vidGET(TqSys_bTqSpBenchModEna,bLocal_TqSys_bTqSpBenchModEna);

   if (bLocal_TqSys_bTqSpBenchModEna != 0)
   {
      TQSYSSPBENCHMOD_vidComput_TqIgnSpBenchMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSSPBENCHMOD_vidComput_TqIgnSpBenchMod                  */
/* !Number      :  FCT.1.6                                                    */
/* !Author      :  HHAF                                                       */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bSelTqSpManModTyp;                                    */
/*  input sint16 TqSys_tqIdcIgnManModSp_C;                                    */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Dv_position_pedale_relative;                                  */
/*  input uint16 TqSys_nEngX_A[16];                                           */
/*  input uint8 TqSys_posnAccPY_A[16];                                        */
/*  input uint16 TqSys_tqIgnSp_nEngX_posnAccPY_M[16][16];                     */
/*  input sint16 TqSys_tqIdcIgnSpBenchMod;                                    */
/*  input uint16 TqSys_tqIdcIgnMaxRate_C;                                     */
/*  input uint16 TqSys_tqIdcIgnMinRate_C;                                     */
/*  output sint16 TqSys_tqIdcIgnSpBenchMod;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSSPBENCHMOD_vidComput_TqIgnSpBenchMod(void)
{
   uint16 u16Local_Regime_moteur;
   uint8  u8Local_Dv_position_pedale_relative;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16Local_raw_TqSys_tqIdcIgnSpBenchMod;
   uint16 u16Local_TqSys_tqIdcIgnSpBenchMod;
   sint16 s16Local_TqSys_tqIdcIgnSpBenchMod;

   if (TqSys_bSelTqSpManModTyp != 0)
   {
      /* TqSys_tqIdcIgnManModSp_C was converted to unsigned by
                    adding 32000 */
      u16Local_raw_TqSys_tqIdcIgnSpBenchMod =
         (uint16)MATHSRV_udtMAX((sint32)(TqSys_tqIdcIgnManModSp_C + 32000),0);
   }
   else
   {
      VEMS_vidGET(Regime_moteur,u16Local_Regime_moteur);
      VEMS_vidGET(Dv_position_pedale_relative,
                     u8Local_Dv_position_pedale_relative);

      u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(TqSys_nEngX_A,
                                                   u16Local_Regime_moteur,
                                                   16);
      u16LocalParaY =
         MATHSRV_u16CalcParaIncAryU8(TqSys_posnAccPY_A,
                                     u8Local_Dv_position_pedale_relative,
                                     16);
      u16Local_raw_TqSys_tqIdcIgnSpBenchMod =
         MATHSRV_u16Interp2d(&TqSys_tqIgnSp_nEngX_posnAccPY_M[0][0],
                             u16LocalParaX,
                             u16LocalParaY,
                             16);
   }

   VEMS_vidGET(TqSys_tqIdcIgnSpBenchMod,s16Local_TqSys_tqIdcIgnSpBenchMod);
   /* s16Local_TqSys_tqIdcIgnSpBenchMod was converted to
   unsigned by adding 32000 */
   u16Local_TqSys_tqIdcIgnSpBenchMod =
               (uint16) (s16Local_TqSys_tqIdcIgnSpBenchMod +32000);
   u16Local_TqSys_tqIdcIgnSpBenchMod =
      MATHSRV_u16SlewFilter(u16Local_TqSys_tqIdcIgnSpBenchMod,
                            u16Local_raw_TqSys_tqIdcIgnSpBenchMod,
                            TqSys_tqIdcIgnMaxRate_C,
                            TqSys_tqIdcIgnMinRate_C);
   /* u16Local_TqSys_tqIdcIgnSpBenchMod was converted
   to signed by subtracting 32000 */
   s16Local_TqSys_tqIdcIgnSpBenchMod =
      (sint16)MATHSRV_udtMIN((sint32)(u16Local_TqSys_tqIdcIgnSpBenchMod
                                      - 32000),32000);

   VEMS_vidSET(TqSys_tqIdcIgnSpBenchMod, s16Local_TqSys_tqIdcIgnSpBenchMod);
}