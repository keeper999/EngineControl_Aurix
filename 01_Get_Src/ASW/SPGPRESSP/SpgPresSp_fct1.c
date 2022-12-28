/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : SpgPresSp                                               */
/* !Description     : SpgPresSp component.                                    */
/*                                                                            */
/* !Module          : SpgPresSp                                               */
/* !Description     : BOOST PRESSURE SETPOINT CALCULATION                     */
/*                                                                            */
/* !File            : SPGPRESSP_FCT1.C                                        */
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
/*   1 / SpgPresSp_vidSpgPresSpIni                                            */
/*   2 / SpgPresSp_vidMng_CalcSpgPresSpBenchMod                               */
/*   3 / SpgPresSp_vidCmuSpgPresSp                                            */
/*   4 / SpgPresSp_vidCalcSpgPresSpBenchMod                                   */
/*                                                                            */
/* !Reference   : V02 NT 09 08194 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/AIRPRES/SPGPRESSP/SPGPRESSP_FCT1$*/
/* $Revision::   1.3      $$Author::   alaouni        $$Date::   19 Apr 2012 $*/
/* $Author::   alaouni                                $$Date::   19 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "SpgPresSp.h"
#include "SpgPresSp_L.h"
#include "SpgPresSp_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresSp_vidSpgPresSpIni                                  */
/* !Description :  The bench mode boost pressure setpoint is initialized at   */
/*                 reset with a calibration value.                            */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 SpgPresSp_pBenchModIniSp_C;                                  */
/*  input boolean SpgPresSp_bBenchModEna_C;                                   */
/*  input boolean SpgPresSp_bBenchModEna;                                     */
/*  input uint16 SpgPresSp_pBenchModSp;                                       */
/*  input uint16 SpgPresSp_pDftValSp_C;                                       */
/*  output uint16 SpgPresSp_pBenchModSp;                                      */
/*  output boolean SpgPresSp_bBenchModEna;                                    */
/*  output uint16 AirPres_pSpgPresSp;                                         */
/*  output uint16 AirPres_pSpgPresRawSp;                                      */
/*  output uint16 SpgPresSp_pDftValSp_C;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresSp_vidSpgPresSpIni(void)
{
   SpgPresSp_pBenchModSp  = SpgPresSp_pBenchModIniSp_C;
   SpgPresSp_bBenchModEna = SpgPresSp_bBenchModEna_C;

   /* outputs AirPres_pSpgPresSp and AirPres_pSpgPresRawSp must be
                                                 initialized in init function */
   if( SpgPresSp_bBenchModEna != 0)
   {
      VEMS_vidSET( AirPres_pSpgPresSp, SpgPresSp_pBenchModSp );
      VEMS_vidSET( AirPres_pSpgPresRawSp, SpgPresSp_pBenchModSp );
   }
   else
   {
      VEMS_vidSET( AirPres_pSpgPresSp, SpgPresSp_pDftValSp_C );
      VEMS_vidSET( AirPres_pSpgPresRawSp, SpgPresSp_pDftValSp_C );
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresSp_vidMng_CalcSpgPresSpBenchMod                     */
/* !Description :  Enable the computation of the bench mode boost pressure    */
/*                 setpoint only when the boost pressure bench mode enable is */
/*                 true.                                                      */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SpgPresSp_vidCalcSpgPresSpBenchMod();                    */
/*  input boolean SpgPresSp_bBenchModEna_C;                                   */
/*  output boolean SpgPresSp_bBenchModEna;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresSp_vidMng_CalcSpgPresSpBenchMod(void)
{
   SpgPresSp_bBenchModEna = SpgPresSp_bBenchModEna_C;

   if( SpgPresSp_bBenchModEna_C != 0 )
   {
      SpgPresSp_vidCalcSpgPresSpBenchMod();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresSp_vidCmuSpgPresSp                                  */
/* !Description :  The boost pressure setpoint is put at a calibration value  */
/*                 when the boost pressure bench mode enable is wrong.        */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean SpgPresSp_bBenchModEna;                                     */
/*  input uint16 SpgPresSp_pBenchModSp;                                       */
/*  input uint16 SpgPresSp_pDftValSp_C;                                       */
/*  input uint16 AirPres_pSpgPresSp;                                          */
/*  input uint16 SpgPresSp_Max_pres_slew_C;                                   */
/*  input uint16 SpgPresSp_Min_pres_slew_C;                                   */
/*  output uint16 AirPres_pSpgPresRawSp;                                      */
/*  output uint16 AirPres_pSpgPresSp;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresSp_vidCmuSpgPresSp(void)
{

   uint16 u16LocalAirPres_pSpgPresSp;
   uint16 u16LocalAirPres_pSpgPresRawSp;

   if( SpgPresSp_bBenchModEna != 0 )
   {
      u16LocalAirPres_pSpgPresRawSp = SpgPresSp_pBenchModSp;
   }
   else
   {
      u16LocalAirPres_pSpgPresRawSp = SpgPresSp_pDftValSp_C;
   }

   VEMS_vidSET( AirPres_pSpgPresRawSp, u16LocalAirPres_pSpgPresRawSp );

   VEMS_vidGET( AirPres_pSpgPresSp, u16LocalAirPres_pSpgPresSp );

   u16LocalAirPres_pSpgPresSp =
      MATHSRV_u16SlewFilter (u16LocalAirPres_pSpgPresSp,
                             u16LocalAirPres_pSpgPresRawSp,
                             SpgPresSp_Max_pres_slew_C,
                             SpgPresSp_Min_pres_slew_C);

   VEMS_vidSET( AirPres_pSpgPresSp, u16LocalAirPres_pSpgPresSp );

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  SpgPresSp_vidCalcSpgPresSpBenchMod                         */
/* !Description :  In bench mode, the boost pressure setpoint is computed     */
/*                 using a map depending on the engine speed and the final    */
/*                 torque (average indicated torque) setpoint for the air     */
/*                 path. The rate of change of the boost pressure setpoint is */
/*                 controlled.                                                */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  sakrani.nouha                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 AirPres_pSpgSp_tqIdcAir_A[16];                               */
/*  input uint16 AirPres_pSpgSp_nEng_A[16];                                   */
/*  input uint16 AirPres_pSpgSp_tqIdcAir_nEng_M[16][16];                      */
/*  output uint16 SpgPresSp_pBenchModSp;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void SpgPresSp_vidCalcSpgPresSpBenchMod(void)
{
   uint16 u16Local_RegimeMoteur;
   uint16 u16Local_TqSys_tqIdcAirReq;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   sint16 s16Local_TqSys_tqIdcAirReq;


   VEMS_vidGET(TqSys_tqIdcAirReq, s16Local_TqSys_tqIdcAirReq);
   VEMS_vidGET(Regime_moteur, u16Local_RegimeMoteur);

   s16Local_TqSys_tqIdcAirReq =
      (sint16)MATHSRV_udtCLAMP(s16Local_TqSys_tqIdcAirReq, -32000, 32000);
   u16Local_TqSys_tqIdcAirReq = (uint16)(s16Local_TqSys_tqIdcAirReq + 32000);
   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(AirPres_pSpgSp_tqIdcAir_A,
                                                u16Local_TqSys_tqIdcAirReq,
                                                16);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(AirPres_pSpgSp_nEng_A,
                                                u16Local_RegimeMoteur,
                                                16 );
   SpgPresSp_pBenchModSp =
      MATHSRV_u16Interp2d(&AirPres_pSpgSp_tqIdcAir_nEng_M[0][0],
                          u16LocalParaX,
                          u16LocalParaY,
                          16);
}

/*---------------------------------End Of File--------------------------------*/