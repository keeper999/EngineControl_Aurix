/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRBENCHMODE                                            */
/* !Description     : THRBENCHMODE component.                                 */
/*                                                                            */
/* !Module          : THRBENCHMODE                                            */
/* !Description     : CALCUL DE LA CONSIGNE DE POSITION PAPILLON MOTORISE EN  */
/*                    MODE BANC MOTEUR                                        */
/*                                                                            */
/* !File            : THRBENCHMODE_FCT1.C                                     */
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
/*   1 / THRBENCHMODE_vidInitOutput                                           */
/*   2 / THRBENCHMODE_vidNormFunc                                             */
/*                                                                            */
/* !Reference   : V02 NT 09 07776 / 02                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/REF/MODULES/THR/THRBENCHMODE/THRBENCHMODE_fc$*/
/* $Revision::   1.1      $$Author::   vgarnier       $$Date::   13 Oct 2010 $*/
/* $Author::   vgarnier                               $$Date::   13 Oct 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
/*QAC Warning(2:0838): Std_Types.h is included in all files generated from
                                       temp.mde producing this kind of error  */
#include "THRBENCHMODE.h"
#include "THRBENCHMODE_L.h"
#include "THRBENCHMODE_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHMODE_vidInitOutput                                 */
/* !Description :  Output initialization                                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 Thr_posnSpBenchMod;                                         */
/*  output boolean Thr_bAcvSpBenchMod;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHMODE_vidInitOutput(void)
{
   VEMS_vidSET(Thr_posnSpBenchMod, 0);
   VEMS_vidSET(Thr_bAcvSpBenchMod , 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRBENCHMODE_vidNormFunc                                   */
/* !Description :  Fonction pour produite la sortie Thr_posnSpBenchMod.       */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf MATHSRV_u16CalcParaIncAryU16(????);                                  */
/*  extf MATHSRV_u16Interp2d(????);                                           */
/*  extf MATHSRV_u16SlewFilter(????);                                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input sint16 TqSys_tqIdcAirReq;                                           */
/*  input uint16 Thr_nEngX_A[16];                                             */
/*  input uint16 Thr_tqIdcAirY_A[16];                                         */
/*  input uint16 Thr_posnSp_nEngX_tqIdcAirY_M[16][16];                        */
/*  input uint16 Thr_posnSpBenchMod;                                          */
/*  input uint16 Thr_posnSpBenchMod_NotFil;                                   */
/*  input uint16 Thr_posnSpBenchModMaxRate_C;                                 */
/*  input uint16 Thr_posnSpBenchModMinRate_C;                                 */
/*  output uint16 Thr_posnSpBenchMod_NotFil;                                  */
/*  output uint16 Thr_posnSpBenchMod;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRBENCHMODE_vidNormFunc(void)
{
   uint16 u16Local_RegimeMoteur;
   uint16 u16LocalParaX;
   uint16 u16LocalParaY;
   uint16 u16LocalThrPosnSpBenchModNotFil;
   uint16 u16LocalTqSys_tqIdcAirReq;
   uint16 u16LocalThr_posnSpBenchMod;
   sint16 s16LocalTqSys_tqIdcAirReq;
   sint32 s32LocalTqSys_tqIdcAirReq;


   VEMS_vidGET(Regime_moteur, u16Local_RegimeMoteur);
   VEMS_vidGET(TqSys_tqIdcAirReq, s16LocalTqSys_tqIdcAirReq);

   u16LocalParaX = MATHSRV_u16CalcParaIncAryU16(Thr_nEngX_A,
                                                u16Local_RegimeMoteur,
                                                16);
   s32LocalTqSys_tqIdcAirReq = (sint32)(s16LocalTqSys_tqIdcAirReq + 32000);
   u16LocalTqSys_tqIdcAirReq =
      (uint16)MATHSRV_udtMAX(s32LocalTqSys_tqIdcAirReq, 0);
   u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(Thr_tqIdcAirY_A,
                                                u16LocalTqSys_tqIdcAirReq,
                                                16);

   u16LocalThrPosnSpBenchModNotFil =
            MATHSRV_u16Interp2d(&Thr_posnSp_nEngX_tqIdcAirY_M[0][0],
                                u16LocalParaX,
                                u16LocalParaY,
                                16);
   Thr_posnSpBenchMod_NotFil =
      (uint16)MATHSRV_udtMIN(u16LocalThrPosnSpBenchModNotFil ,1024);
   VEMS_vidGET(Thr_posnSpBenchMod, u16LocalThr_posnSpBenchMod);
   u16LocalThr_posnSpBenchMod =
                MATHSRV_u16SlewFilter(u16LocalThr_posnSpBenchMod,
                                      Thr_posnSpBenchMod_NotFil,
                                      Thr_posnSpBenchModMaxRate_C,
                                      Thr_posnSpBenchModMinRate_C);
   u16LocalThr_posnSpBenchMod =
      (uint16)MATHSRV_udtMIN(u16LocalThr_posnSpBenchMod ,1024);
   VEMS_vidSET(Thr_posnSpBenchMod, u16LocalThr_posnSpBenchMod);
}
/*---------------------------------End Of File--------------------------------*/