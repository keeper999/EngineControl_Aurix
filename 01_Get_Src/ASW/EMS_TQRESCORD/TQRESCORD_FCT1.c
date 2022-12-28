/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQRESCORD                                               */
/* !Description     : TQRESCORD component.                                    */
/*                                                                            */
/* !Module          : TQRESCORD                                               */
/* !Description     : COORDINATION DES RESERVES.                              */
/*                                                                            */
/* !File            : TQRESCORD_FCT1.C                                        */
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
/*   1 / TQRESCORD_vidInitOutput                                              */
/*   2 / TQRESCORD_vidCoord_degradations                                      */
/*   3 / TQRESCORD_vidCoord_reserves                                          */
/*                                                                            */
/* !Reference   : V02 NT 11 02659 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0183 / 2.4                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQRESCORD/TQRESCO$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQRESCORD.h"
#include "TQRESCORD_L.h"
#include "TQRESCORD_IM.h"
#include "VEMS.h"



/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQRESCORD_vidInitOutput                                    */
/* !Description :  Initialisation des variables de sortie                     */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CanPurg_rCanRes;                                             */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 CanPurg_tqCanRes;                                            */
/*  output boolean TqRes_bAcvCll;                                             */
/*  output uint16 TqRes_tiTranCll;                                            */
/*  output uint16 TqRes_tqIncCll;                                             */
/*  output sint16 TqRes_tqMaxRes;                                             */
/*  output sint16 TqRes_tqMaxResnoSat;                                        */
/*  output uint16 TqRes_tqCanPurgRes;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQRESCORD_vidInitOutput(void)
{
   uint16 u16LocalCanPurg_rCanRes;
   uint16 u16LocalCanPurg_tqCanRes;
   uint32 u32LocalRateLimIn1;
   sint16 s16LocalTqSys_tqIdcAirLimCordWR;
   sint32 s32Localmultipl;


   /*Output Initialization*/
   VEMS_vidSET(TqRes_bAcvCll, 0);
   VEMS_vidSET(TqRes_tiTranCll, 0);
   VEMS_vidSET(TqRes_tqIncCll, 0);
   VEMS_vidSET(TqRes_tqMaxRes, 0);
   VEMS_vidSET(TqRes_tqMaxResnoSat, 0);

   /*F09_01_Coordination_degradations*/
   VEMS_vidGET(CanPurg_rCanRes, u16LocalCanPurg_rCanRes);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes, s16LocalTqSys_tqIdcAirLimCordWR);

   s32Localmultipl = (sint32)( ( u16LocalCanPurg_rCanRes
                               * s16LocalTqSys_tqIdcAirLimCordWR)
                             / 1000);


   VEMS_vidGET(CanPurg_tqCanRes, u16LocalCanPurg_tqCanRes);

   u32LocalRateLimIn1 = (uint32)MATHSRV_udtMAX(u16LocalCanPurg_tqCanRes,
                                               s32Localmultipl);
   TqRes_tqCanPurgRes =
      (uint16)MATHSRV_udtMIN(u32LocalRateLimIn1, 8000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQRESCORD_vidCoord_degradations                            */
/* !Description :  Cette fonction calcule le couple de compensation à         */
/*                 appliquer sur la branche air lorsque le rendement d’avance */
/*                 maximum n’est pas à 1, ainsi que le couple de réserve pour */
/*                 la purge canister.                                         */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05006_003.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 CanPurg_rCanRes;                                             */
/*  input sint16 TqSys_tqIdcAirLimCordWoutRes;                                */
/*  input uint16 CanPurg_tqCanRes;                                            */
/*  input uint16 TqRes_tqIncMaxCanPurgRes_C;                                  */
/*  input sint16 TqRes_tqDecMaxCanPurgRes_C;                                  */
/*  input uint16 TqRes_tqCanPurgRes;                                          */
/*  input uint16 TqRes_rBasRes;                                               */
/*  output uint16 TqRes_tqCanPurgRes;                                         */
/*  output uint16 TqRes_tqAirCmp;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQRESCORD_vidCoord_degradations(void)
{
   uint16 u16LocalCanPurg_rCanRes;
   uint16 u16LocalTqRes_rBasRes;
   uint16 u16LocalRateLimIn;
   uint16 u16LocalRateLimOut;
   uint16 u16LocalSlewFilterInc;
   uint16 u16LocalSlewFilterDec;
   uint16 u16LocalCanPurg_tqCanRes;
   uint32 u32LocalRateLimIn11;
   sint16 s16LocalSlewFilterDec;
   sint16 s16LocalTqSys_tqIdcAirLimCordWR;
   sint32 s32Localmultipl;
   sint32 s32localProd;


   VEMS_vidGET(CanPurg_rCanRes, u16LocalCanPurg_rCanRes);
   VEMS_vidGET(TqSys_tqIdcAirLimCordWoutRes, s16LocalTqSys_tqIdcAirLimCordWR);

   s32Localmultipl = (sint32)( ( u16LocalCanPurg_rCanRes
                               * s16LocalTqSys_tqIdcAirLimCordWR)
                             / 1000);

   VEMS_vidGET(CanPurg_tqCanRes, u16LocalCanPurg_tqCanRes);

   u32LocalRateLimIn11 = (uint32)MATHSRV_udtMAX(u16LocalCanPurg_tqCanRes,
                                                s32Localmultipl);

   u16LocalRateLimIn = (uint16)MATHSRV_udtMIN(u32LocalRateLimIn11, 65535);

   u16LocalSlewFilterInc = (uint16)(TqRes_tqIncMaxCanPurgRes_C / 100);
   s16LocalSlewFilterDec = (sint16)(((-1) * TqRes_tqDecMaxCanPurgRes_C) / 100);
   u16LocalSlewFilterDec = (uint16)MATHSRV_udtMAX(s16LocalSlewFilterDec, 0);

   u16LocalRateLimOut = MATHSRV_u16SlewFilter(TqRes_tqCanPurgRes,
                                              u16LocalRateLimIn,
                                              u16LocalSlewFilterInc,
                                              u16LocalSlewFilterDec);

   TqRes_tqCanPurgRes = (uint16)MATHSRV_udtMIN(u16LocalRateLimOut, 8000);

   VEMS_vidGET(TqRes_rBasRes, u16LocalTqRes_rBasRes);
   s32localProd = (sint32)( ( u16LocalTqRes_rBasRes
                            * s16LocalTqSys_tqIdcAirLimCordWR)
                          / 1000);
   TqRes_tqAirCmp = (uint16)MATHSRV_udtCLAMP(s32localProd, 0, 8000);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQRESCORD_vidCoord_reserves                                */
/* !Description :  Le couple des réserves totales est le maximum de l’ensemble*/
/*                 des couples réserve. Un flag est ajouté à la sortie du     */
/*                 couple des réserves totales pour boucler la structure      */
/*                 couple.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/* !Trace_To    :  VEMS_R_10_05006_004.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqRes_tqACRes;                                               */
/*  input uint16 TqRes_tqAltRes;                                              */
/*  input uint16 TqRes_tqStgPmpRes;                                           */
/*  input uint16 TqRes_tqLnchRes;                                             */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqRes_tqGasModRes;                                           */
/*  input uint16 TqRes_tqFanRes;                                              */
/*  input uint16 TqRes_tqEOMRes;                                              */
/*  input uint16 TqRes_tqElPmpGrpRes;                                         */
/*  input uint16 TqRes_tqCrwlRes;                                             */
/*  input uint16 TqRes_tqCoHeatRes;                                           */
/*  input uint16 TqRes_tqCnvRes;                                              */
/*  input uint16 TqRes_tqAirCmp;                                              */
/*  input uint16 TqRes_tqCanPurgRes;                                          */
/*  input uint16 TqRes_tqMaxResNotSat_MP;                                     */
/*  input uint16 TqRes_tqSatMaxRes_C;                                         */
/*  input uint16 TqRes_idxTqResAcvCll_C;                                      */
/*  input uint16 TqRes_tqThrLoMaxRes_C;                                       */
/*  input uint16 TqRes_tqThrHiMaxRes_C;                                       */
/*  input uint16 TqRes_tqValIncCll_C;                                         */
/*  input uint16 TqRes_tiValTranCll_C;                                        */
/*  output uint16 TqRes_tqMaxResNotSat_MP;                                    */
/*  output sint16 TqRes_tqMaxRes;                                             */
/*  output sint16 TqRes_tqMaxResnoSat;                                        */
/*  output boolean TqRes_bAcvCll;                                             */
/*  output uint16 TqRes_tqIncCll;                                             */
/*  output uint16 TqRes_tiTranCll;                                            */
/*  output uint16 TqRes_tiValTranCll_C;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQRESCORD_vidCoord_reserves(void)
{
   uint8   u8LocalIndex;
   uint16  u16LocalTqRes_tqAltRes;
   uint16  u16LocalTqRes_tqIncCll;
   uint16  u16LocalTqRes_tqEOMRes;
   uint16  u16LocalTqRes_tqACRes;
   uint16  u16LocalTqRes_tqGasModRes;
   uint16  u16LocalTqRes_tqMaxRes;
   uint16  u16LocalTqRes_tqCnvRes;
   uint16  u16LocalTqRes_tqCoHeatRes;
   uint16  u16LocalTqRes_tqElPmpGrpRes;
   uint16  u16LocalTqRes_tqFanRes;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqRes_tqLnchRes;
   uint16  u16LocalTqRes_tqStgPmpRes;
   uint16  u16LocalTqRes_tqCrwlRes;
   uint16  u16LocalTqResTqMaxRes;
   uint16  u16LocalMaxRes;
   uint16  u16LocalTqRes_tqMaxResnoSat;
   uint16  u16LocalTabRes[14];
   /*QAC Warning : Msg(2:3132), u16LocalTabRes is a local array*/


   VEMS_vidGET(TqRes_tqACRes, u16LocalTqRes_tqACRes);
   VEMS_vidGET(TqRes_tqAltRes, u16LocalTqRes_tqAltRes);
   VEMS_vidGET(TqRes_tqStgPmpRes, u16LocalTqRes_tqStgPmpRes);
   VEMS_vidGET(TqRes_tqLnchRes, u16LocalTqRes_tqLnchRes);
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   VEMS_vidGET(TqRes_tqGasModRes, u16LocalTqRes_tqGasModRes);
   VEMS_vidGET(TqRes_tqFanRes, u16LocalTqRes_tqFanRes);
   VEMS_vidGET(TqRes_tqEOMRes, u16LocalTqRes_tqEOMRes);
   VEMS_vidGET(TqRes_tqElPmpGrpRes, u16LocalTqRes_tqElPmpGrpRes);
   VEMS_vidGET(TqRes_tqCrwlRes, u16LocalTqRes_tqCrwlRes);
   VEMS_vidGET(TqRes_tqCoHeatRes, u16LocalTqRes_tqCoHeatRes);
   VEMS_vidGET(TqRes_tqCnvRes, u16LocalTqRes_tqCnvRes);

   u16LocalTabRes[0] = TqRes_tqAirCmp;
   u16LocalTabRes[1] = u16LocalTqRes_tqACRes;
   u16LocalTabRes[2] = u16LocalTqRes_tqAltRes;
   u16LocalTabRes[3] = TqRes_tqCanPurgRes;
   u16LocalTabRes[4] = u16LocalTqRes_tqCnvRes;
   u16LocalTabRes[5] = u16LocalTqRes_tqCoHeatRes;
   u16LocalTabRes[6] = u16LocalTqRes_tqCrwlRes;
   u16LocalTabRes[7] = u16LocalTqRes_tqElPmpGrpRes;
   u16LocalTabRes[8] = u16LocalTqRes_tqEOMRes;
   u16LocalTabRes[9] = u16LocalTqRes_tqFanRes;
   u16LocalTabRes[10] = u16LocalTqRes_tqGasModRes;
   u16LocalTabRes[11] = u16LocalTqRes_tqIdlRes;
   u16LocalTabRes[12] = u16LocalTqRes_tqLnchRes;
   u16LocalTabRes[13] = u16LocalTqRes_tqStgPmpRes;

   u16LocalTqRes_tqMaxRes = (uint16)MATHSRV_udtMAX(TqRes_tqAirCmp,
                                                   u16LocalTqRes_tqACRes);

   for (u8LocalIndex = 2; u8LocalIndex < 14; u8LocalIndex++)
   {
      u16LocalTqRes_tqMaxRes =
         (uint16)MATHSRV_udtMAX(u16LocalTqRes_tqMaxRes,
                                u16LocalTabRes[u8LocalIndex]);
   }

   TqRes_tqMaxResNotSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqMaxRes,
                                                    3200);
   u16LocalTqResTqMaxRes = (uint16)MATHSRV_udtMIN(TqRes_tqMaxResNotSat_MP,
                                                  TqRes_tqSatMaxRes_C);
   VEMS_vidSET(TqRes_tqMaxRes, (sint16)u16LocalTqResTqMaxRes);


   if ((TqRes_idxTqResAcvCll_C & 0x0001) != 0)
   {
      u16LocalMaxRes = TqRes_tqAirCmp;
   }
   else
   {
      u16LocalMaxRes = 0;
   }

   for (u8LocalIndex = 1; u8LocalIndex < 14; u8LocalIndex++)
   {
      if (((TqRes_idxTqResAcvCll_C >> u8LocalIndex) & 0x0001) != 0)
      {
         u16LocalMaxRes = (uint16)MATHSRV_udtMAX(u16LocalTabRes[u8LocalIndex],
                                                 u16LocalMaxRes);
      }
   }

   u16LocalTqRes_tqMaxResnoSat = (uint16)MATHSRV_udtMIN(u16LocalMaxRes,
                                                        32000);

   VEMS_vidSET(TqRes_tqMaxResnoSat, (sint16)u16LocalTqRes_tqMaxResnoSat);

   if (u16LocalTqRes_tqMaxResnoSat <= TqRes_tqThrLoMaxRes_C)
   {
      VEMS_vidSET(TqRes_bAcvCll, 0);
   }
   else
   {
      if (u16LocalTqRes_tqMaxResnoSat >= TqRes_tqThrHiMaxRes_C)
      {
         VEMS_vidSET(TqRes_bAcvCll, 1);
      }

   }

   u16LocalTqRes_tqIncCll = (uint16)MATHSRV_udtMIN(TqRes_tqValIncCll_C, 32000);
   VEMS_vidSET(TqRes_tqIncCll, u16LocalTqRes_tqIncCll);

   if (TqRes_tiValTranCll_C < 500)
   {
      VEMS_vidSET(TqRes_tiTranCll, TqRes_tiValTranCll_C);
   }
   else
   {
      VEMS_vidSET(TqRes_tiTranCll, 500);
   }
}
/*-------------------------------- End of file -------------------------------*/