/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCOHEATRES                                             */
/* !Description     : TQCOHEATRES component                                   */
/*                                                                            */
/* !Module          : TQCOHEATRES                                             */
/* !Description     : Réserve de couple chauffage habitacle                   */
/*                                                                            */
/* !File            : TQCOHEATRES_FCT1.C                                      */
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
/*   1 / TQCOHEATRES_vidInitOutput                                            */
/*   2 / TQCOHEATRES_vidReserveThrmHabit                                      */
/*                                                                            */
/* !Reference   : V02 NT 11 02653 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_2028 / 2.1                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQCOHEATRES/TQCOH$*/
/* $Revision::   1.7      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "MATHSRV.H"
#include "TQCOHEATRES.H"
#include "TQCOHEATRES_L.H"
#include "TQCOHEATRES_IM.H"
#include "VEMS.H"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOHEATRES_vidInitOutput                                  */
/* !Description :  fonction d'initialisation des sorties                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 ThMgt_rCoHeatReq;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqCkEngLimCord;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint16 TqRes_nEngCoHeatRes_A[8];                                    */
/*  input uint16 TqRes_tqCkEngCoHeatRes_A[8];                                 */
/*  input uint16 TqRes_tqCoHeatRes_M[8][8];                                   */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint8 TqRes_tAir_A[8];                                              */
/*  input uint8 TqRes_facCorCoHeatRes_M[8][8];                                */
/*  input uint16 TqRes_tqCoHeatResMax_MP;                                     */
/*  input uint16 TqRes_tqCoHeatResNotSat_MP;                                  */
/*  output uint16 TqRes_tqCoHeatResMax_MP;                                    */
/*  output uint16 TqRes_tqCoHeatResNotSat_MP;                                 */
/*  output uint16 TQCOHEATRES_u16RateLimterOut;                               */
/*  output uint16 TqRes_tqCoHeatRes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOHEATRES_vidInitOutput(void)
{
   uint8    u8LocalThMgt_rCoHeatReq;
   uint8    u8LocalInterpFacCorCoHeatRes;
   uint8    u8LocalExt_tCoMes;
   uint8    u8LocalExt_tAir;
   uint16   u16LocalInterpTqCoHeatRes;
   uint16   u16LocalEng_nCkFil;
   uint16   u16LocalTqSys_tqCkEngLimCord;
   uint16   u16LocalCalcParaX;
   uint16   u16LocalCalcParaY;
   uint32   u32Localproduct;
   sint8    s8LocalExt_tAir;
   sint16   s16LocalTqSys_tqCkEngLimCord;
   sint16   s16LocalExt_tCoMes;
   sint16   s16LocalExt_tAir;
   sint32   s32LocalTqSys_tqCkEngLimCord;
   sint32   s32LocalExt_tCoMes;


   VEMS_vidGET(ThMgt_rCoHeatReq, u8LocalThMgt_rCoHeatReq);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(TqSys_tqCkEngLimCord, s16LocalTqSys_tqCkEngLimCord);
   VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);

   /*interpolation of TqRes_tqCoHeatRes_M*/
   /* Scaling: u16LocalEng_nCkFil : 1/4 */
   /* TqRes_nEngCoHeatRes_A : 1         */
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(TqRes_nEngCoHeatRes_A,
                                                    u16LocalEng_nCkFil,
                                                    8);

   s32LocalTqSys_tqCkEngLimCord =
      (sint32)(s16LocalTqSys_tqCkEngLimCord + 32000);
   u16LocalTqSys_tqCkEngLimCord =
      (uint16)MATHSRV_udtMAX(s32LocalTqSys_tqCkEngLimCord, 0);
   u16LocalCalcParaY =
      MATHSRV_u16CalcParaIncAryU16(TqRes_tqCkEngCoHeatRes_A,
                                   u16LocalTqSys_tqCkEngLimCord,
                                   8);

   u16LocalInterpTqCoHeatRes = MATHSRV_u16Interp2d(&TqRes_tqCoHeatRes_M[0][0],
                                                   u16LocalCalcParaX,
                                                   u16LocalCalcParaY,
                                                   8);

   /*interpolation of TqRes_facCorCoHeatRes_M*/
   s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
   u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);
   u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                                   u8LocalExt_tCoMes,
                                                   8);

   s16LocalExt_tAir = (sint16)(s8LocalExt_tAir + 50);
   u8LocalExt_tAir = (uint8)MATHSRV_udtMAX(s16LocalExt_tAir, 0);
   u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(TqRes_tAir_A,
                                                   u8LocalExt_tAir,
                                                   8);

   u8LocalInterpFacCorCoHeatRes =
      MATHSRV_u8Interp2d(&TqRes_facCorCoHeatRes_M[0][0],
                         u16LocalCalcParaX,
                         u16LocalCalcParaY,
                         8);

   /*production of TqRes_tqCoHeatResMax_MP*/
   /* Scaling: u16LocalInterpTqCoHeatRes : 1/16 */
   /* u8LocalInterpFacCorCoHeatRes : 1/128      */
   /* u32Localproduct = 1/16                    */
   u32Localproduct = (uint32)(  ( u16LocalInterpTqCoHeatRes
                                * u8LocalInterpFacCorCoHeatRes)
                             / 128);
   TqRes_tqCoHeatResMax_MP = (uint16)MATHSRV_udtMIN(u32Localproduct, 1600);

   /*production of TqRes_tqCoHeatResNotSat_MP*/
   /* Scaling: u8LocalThMgt_rCoHeatReq : 1  */
   /* TqRes_tqCoHeatResMax_MP : 1/16        */
   /* u32Localproduct = 1/16                */
   u32Localproduct = (uint32)(   (u8LocalThMgt_rCoHeatReq
                                 * TqRes_tqCoHeatResMax_MP)
                             / 100);
   TqRes_tqCoHeatResNotSat_MP = (uint16)MATHSRV_udtMIN(u32Localproduct, 1600);
   TQCOHEATRES_u16RateLimterOut = TqRes_tqCoHeatResNotSat_MP;
   VEMS_vidSET(TqRes_tqCoHeatRes, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCOHEATRES_vidReserveThrmHabit                            */
/* !Description :  La réserve de couple chauffage habitacle est issue du      */
/*                 produit de la dégradation chauffage habitacle et de deux   */
/*                 cartographie (régime, remplissage et température de l’eau, */
/*                 température de l’air).                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_02653_001.01                                     */
/*                 VEMS_R_11_02653_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bAcvCoHeatRes_C;                                      */
/*  input uint8 ThMgt_rCoHeatReq;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input sint16 TqSys_tqCkEngLimCord;                                        */
/*  input sint16 Ext_tCoMes;                                                  */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint16 TqRes_nEngCoHeatRes_A[8];                                    */
/*  input uint16 TqRes_tqCkEngCoHeatRes_A[8];                                 */
/*  input uint16 TqRes_tqCoHeatRes_M[8][8];                                   */
/*  input uint8 TqRes_tCo_A[8];                                               */
/*  input uint8 TqRes_tAir_A[8];                                              */
/*  input uint8 TqRes_facCorCoHeatRes_M[8][8];                                */
/*  input uint16 TqRes_tqCoHeatResMax_MP;                                     */
/*  input uint16 TqRes_tqIncMaxCoHeatRes_C;                                   */
/*  input sint16 TqRes_tqDecMaxCoHeatRes_C;                                   */
/*  input uint16 TQCOHEATRES_u16RateLimterOut;                                */
/*  input uint16 TqRes_tqCoHeatResNotSat_MP;                                  */
/*  input uint16 TqRes_tqMaxCoHeatRes_C;                                      */
/*  output uint16 TqRes_tqCoHeatResMax_MP;                                    */
/*  output uint16 TqRes_tqCoHeatResNotSat_MP;                                 */
/*  output uint16 TQCOHEATRES_u16RateLimterOut;                               */
/*  output uint16 TqRes_tqCoHeatRes;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCOHEATRES_vidReserveThrmHabit(void)
{
   uint8    u8LocalThMgt_rCoHeatReq;
   uint8    u8LocalInterpFacCorCoHeatRes;
   uint8    u8LocalExt_tCoMes;
   uint8    u8LocalExt_tAir;
   uint16   u16LocalInterpTqCoHeatRes;
   uint16   u16LocalEng_nCkFil;
   uint16   u16LocalTqSys_tqCkEngLimCord;
   uint16   u16LocalTqRes_tqCoHeatRes;
   uint16   u16LocalCalcParaX;
   uint16   u16LocalCalcParaY;
   uint16   u16LocalInc;
   uint16   u16LocalDec;
   uint32   u32Localproduct;
   sint8    s8LocalExt_tAir;
   sint16   s16LocalDec;
   sint16   s16LocalTqSys_tqCkEngLimCord;
   sint16   s16LocalExt_tCoMes;
   sint16   s16LocalExt_tAir;
   sint32   s32LocalTqSys_tqCkEngLimCord;
   sint32   s32LocalExt_tCoMes;


   if (TqRes_bAcvCoHeatRes_C != 0)
   {
      VEMS_vidGET(ThMgt_rCoHeatReq, u8LocalThMgt_rCoHeatReq);
      VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
      VEMS_vidGET(TqSys_tqCkEngLimCord, s16LocalTqSys_tqCkEngLimCord);
      VEMS_vidGET(Ext_tCoMes, s16LocalExt_tCoMes);
      VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);

      /*interpolation of TqRes_tqCoHeatRes_M*/
      /* Scaling: u16LocalEng_nCkFil : 1/4 */
      /* TqRes_nEngCoHeatRes_A : 1         */
      u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
      u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU16(TqRes_nEngCoHeatRes_A,
                                                       u16LocalEng_nCkFil,
                                                       8);

      s32LocalTqSys_tqCkEngLimCord =
         (sint32)(s16LocalTqSys_tqCkEngLimCord + 32000) ;
      u16LocalTqSys_tqCkEngLimCord =
         (uint16)MATHSRV_udtMAX(s32LocalTqSys_tqCkEngLimCord, 0);
      u16LocalCalcParaY =
         MATHSRV_u16CalcParaIncAryU16(TqRes_tqCkEngCoHeatRes_A,
                                      u16LocalTqSys_tqCkEngLimCord,
                                      8);

      u16LocalInterpTqCoHeatRes =
         MATHSRV_u16Interp2d(&TqRes_tqCoHeatRes_M[0][0],
                             u16LocalCalcParaX,
                             u16LocalCalcParaY,
                             8);

      /*interpolation of TqRes_facCorCoHeatRes_M*/
      s32LocalExt_tCoMes = (sint32)(s16LocalExt_tCoMes + 40);
      u8LocalExt_tCoMes = (uint8)MATHSRV_udtCLAMP(s32LocalExt_tCoMes, 0, 254);
      u16LocalCalcParaX = MATHSRV_u16CalcParaIncAryU8(TqRes_tCo_A,
                                                      u8LocalExt_tCoMes,
                                                      8);

      s16LocalExt_tAir = (sint16)(s8LocalExt_tAir + 50);
      u8LocalExt_tAir = (uint8)MATHSRV_udtMAX(s16LocalExt_tAir, 0);
      u16LocalCalcParaY = MATHSRV_u16CalcParaIncAryU8(TqRes_tAir_A,
                                                      u8LocalExt_tAir,
                                                      8);

      u8LocalInterpFacCorCoHeatRes =
         MATHSRV_u8Interp2d(&TqRes_facCorCoHeatRes_M[0][0],
                            u16LocalCalcParaX,
                            u16LocalCalcParaY,
                            8);

      /*production of TqRes_tqCoHeatResMax_MP*/
      /* Scaling: u16LocalInterpTqCoHeatRes : 1/16 */
      /* u8LocalInterpFacCorCoHeatRes : 1/128      */
      /* u32Localproduct = 1/16                    */
      u32Localproduct = (uint32)(  (u16LocalInterpTqCoHeatRes
                                   * u8LocalInterpFacCorCoHeatRes)
                                / 128);
      TqRes_tqCoHeatResMax_MP = (uint16)MATHSRV_udtMIN(u32Localproduct, 1600);

      /*production of TqRes_tqCoHeatResNotSat_MP*/
      /* Scaling: u8LocalThMgt_rCoHeatReq : 1  */
      /* TqRes_tqCoHeatResMax_MP : 1/16        */
      /* u32Localproduct = 1/16                */
      u32Localproduct =
         (uint32)(   ( u8LocalThMgt_rCoHeatReq
                     * TqRes_tqCoHeatResMax_MP)
                 / 100);
      TqRes_tqCoHeatResNotSat_MP =
         (uint16)MATHSRV_udtMIN(u32Localproduct, 1600);

      /*production of TqRes_tqCoHeatRes*/
      /* Scaling: TqRes_tqIncMaxCoHeatRes_C : 1/4 */
      /* TqRes_tqDecMaxCoHeatRes_C : 1/4         */
      /* TQCOHEATRES_u16RateLimterOut = 1/16     */
      u16LocalInc = (uint16)(TqRes_tqIncMaxCoHeatRes_C / 25);
      s16LocalDec = (sint16)(((-1) * TqRes_tqDecMaxCoHeatRes_C) / 25);
      u16LocalDec = (uint16)MATHSRV_udtMAX(s16LocalDec, 0);
      TQCOHEATRES_u16RateLimterOut =
         MATHSRV_u16SlewFilter(TQCOHEATRES_u16RateLimterOut,
                               TqRes_tqCoHeatResNotSat_MP,
                               u16LocalInc,
                               u16LocalDec);
      u16LocalTqRes_tqCoHeatRes =
         (uint16)MATHSRV_udtMIN(TqRes_tqMaxCoHeatRes_C,
                                TQCOHEATRES_u16RateLimterOut);
      u16LocalTqRes_tqCoHeatRes =
         (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqCoHeatRes, 1600);
      VEMS_vidSET(TqRes_tqCoHeatRes, u16LocalTqRes_tqCoHeatRes);
   }
}
/*------------------------------- end of file --------------------------------*/