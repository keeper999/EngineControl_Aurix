/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQSYSIDC                                                */
/* !Description     : TQSYSIDC Component.                                     */
/*                                                                            */
/* !Module          : TQSYSIDC                                                */
/* !Description     : GESTION DES CONSIGNES DE COUPLE .                       */
/*                                                                            */
/* !File            : TQSYSIDC_FCT1.C                                         */
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
/*   1 / TQSYSIDC_vidTqSysSlow                                                */
/*   2 / TQSYSIDC_vidTqSysFast                                                */
/*                                                                            */
/* !Reference   : V02 NT 08 05347 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQSYSIDC.h"
#include "TQSYSIDC_L.h"
#include "TQSYSIDC_IM.h"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSIDC_vidTqSysSlow                                      */
/* !Description :  Dans le calcul de la consigne du couple finale de la chaîne*/
/*                 d'air, on ajoutera à la consigne de couple coordonnée avec */
/*                 toutes les limitations branche air, le couple de           */
/*                 compensation généré puis on applique les limitations       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bTqSpBenchModEna;                                     */
/*  input sint16 TqSys_tqIdcAirSpBenchMod;                                    */
/*  input sint16 TqSys_tqIdcAirEngLimCord;                                    */
/*  input sint16 Tde_torque_correction;                                       */
/*  input sint16 TqSys_tqAirAntiBoil;                                         */
/*  input sint16 TqSys_tqAirOverSpdProt;                                      */
/*  output sint16 TqSys_tqIdcAirReq;                                          */
/*  output sint16 TqSys_tqIdcAirReqGen;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSIDC_vidTqSysSlow(void)
{
   boolean bLocalTqSys_bTqSpBenchModEna;
   sint16  s16LocalTqSys_tqIdcAirReqGen;
   sint16  s16LocalTqSys_tqIdcAirSpBenchMod;
   sint16  s16LocalTqSys_tqIdcAirEngLimCord;
   sint16  s16LocalTde_torque_correction;
   sint16  s16LocalTqSys_tqAirAntiBoil;
   sint16  s16LocalTqSys_tqAirOverSpdProt;
   sint32  s32LocalSum;

   VEMS_vidGET(TqSys_bTqSpBenchModEna, bLocalTqSys_bTqSpBenchModEna);

   if (bLocalTqSys_bTqSpBenchModEna != 0)
   {
      VEMS_vidGET(TqSys_tqIdcAirSpBenchMod, s16LocalTqSys_tqIdcAirSpBenchMod);
      s16LocalTqSys_tqIdcAirReqGen =
         (sint16)MATHSRV_udtCLAMP(s16LocalTqSys_tqIdcAirSpBenchMod,
                                  -32000,
                                  32000);
   }
   else
   {
      VEMS_vidGET(TqSys_tqIdcAirEngLimCord, s16LocalTqSys_tqIdcAirEngLimCord);
      VEMS_vidGET(Tde_torque_correction, s16LocalTde_torque_correction);
      VEMS_vidGET(TqSys_tqAirAntiBoil, s16LocalTqSys_tqAirAntiBoil);
      VEMS_vidGET(TqSys_tqAirOverSpdProt, s16LocalTqSys_tqAirOverSpdProt);

      s32LocalSum = (sint32)( s16LocalTqSys_tqIdcAirEngLimCord
                            + s16LocalTde_torque_correction);
      s32LocalSum = MATHSRV_udtMIN(s16LocalTqSys_tqAirAntiBoil, s32LocalSum);
      s32LocalSum = MATHSRV_udtMIN(s16LocalTqSys_tqAirOverSpdProt, s32LocalSum);
      s16LocalTqSys_tqIdcAirReqGen = (sint16)MATHSRV_udtCLAMP(s32LocalSum,
                                                              -32000,
                                                              32000);
   }
   VEMS_vidSET (TqSys_tqIdcAirReq, s16LocalTqSys_tqIdcAirReqGen);
   VEMS_vidSET (TqSys_tqIdcAirReqGen, s16LocalTqSys_tqIdcAirReqGen);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQSYSIDC_vidTqSysFast                                      */
/* !Description :  Pour le calcul de la consigne de couple finale de la chaîne*/
/*                 d'avance, on ajoutera à la consigne de couple coordonnée à */
/*                 la correction curative, le couple de compensation puis on  */
/*                 applique les limitations.                                  */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Atef Dlili                                                 */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqSys_bTqSpBenchModEna;                                     */
/*  input sint16 TqSys_tqIdcIgnSpBenchMod;                                    */
/*  input sint16 TqSys_tqCkAntiOscCord;                                       */
/*  input sint16 Tde_torque_correction;                                       */
/*  input sint16 TqSys_tqAdvAntiBoil;                                         */
/*  input sint16 TqSys_tqAdvOverSpdProt;                                      */
/*  output sint16 TqSys_tqIdcReq;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQSYSIDC_vidTqSysFast(void)
{
   boolean bLocalTqSys_bTqSpBenchModEna;
   sint16  s16LocalTqSys_tqIdcReq;
   sint16  s16LocalTqSys_tqIdcIgnSpBenchMod;
   sint16  s16LocalTqSys_tqCkAntiOscCord;
   sint16  s16LocalTde_torque_correction;
   sint16  s16LocalTqSys_tqAdvAntiBoil;
   sint16  s16LocalTqSys_tqAdvOverSpdProt;
   sint32  s32LocalSum;

   VEMS_vidGET(TqSys_bTqSpBenchModEna, bLocalTqSys_bTqSpBenchModEna);

   if(bLocalTqSys_bTqSpBenchModEna !=0)
   {
      VEMS_vidGET(TqSys_tqIdcIgnSpBenchMod, s16LocalTqSys_tqIdcIgnSpBenchMod);
      s16LocalTqSys_tqIdcReq = (sint16)MATHSRV_udtCLAMP(
                                             s16LocalTqSys_tqIdcIgnSpBenchMod,
                                             -32000,
                                             32000);
   }
   else
   {
      VEMS_vidGET(TqSys_tqCkAntiOscCord, s16LocalTqSys_tqCkAntiOscCord);
      VEMS_vidGET(Tde_torque_correction, s16LocalTde_torque_correction);
      VEMS_vidGET(TqSys_tqAdvAntiBoil, s16LocalTqSys_tqAdvAntiBoil);
      VEMS_vidGET(TqSys_tqAdvOverSpdProt, s16LocalTqSys_tqAdvOverSpdProt);

      s32LocalSum = (sint32)(s16LocalTqSys_tqCkAntiOscCord
                             + s16LocalTde_torque_correction);
      s32LocalSum = MATHSRV_udtMIN(s16LocalTqSys_tqAdvAntiBoil, s32LocalSum);
      s32LocalSum = MATHSRV_udtMIN (s16LocalTqSys_tqAdvOverSpdProt,
                                    s32LocalSum);
      s16LocalTqSys_tqIdcReq = (sint16)MATHSRV_udtCLAMP(s32LocalSum,
                                                      -32000,
                                                      32000);
   }
   VEMS_vidSET (TqSys_tqIdcReq, s16LocalTqSys_tqIdcReq);
}
/*----------------------------- end of file ----------------------------------*/