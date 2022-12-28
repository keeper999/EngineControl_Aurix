/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQADVMIN                                                */
/* !Description     : TQADVMIN component.                                     */
/*                                                                            */
/* !Module          : TQADVMIN                                                */
/* !Description     : CLOSED LOOP REQUEST FOR LOW TORQUE                      */
/*                                                                            */
/* !File            : TQADVMIN_FCT1.c                                         */
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
/*   1 / TQADVMIN_vidInitOutput                                               */
/*   2 / TQADVMIN_vidRqestClosedLopTqmin1                                     */
/*   3 / TQADVMIN_vidRqestClosedLopTqmin2                                     */
/*                                                                            */
/* !Reference   : V02 NT 11 05439 / 01                                        */
/* !OtherRefs   : 01460_11_03421 / 1                                          */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQADVMIN/TQADVMIN$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQADVMIN.h"
#include "TQADVMIN_L.h"
#include "TQADVMIN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQADVMIN_vidInitOutput                                     */
/* !Description :  Fonction d'initialisation des variables.                   */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint16 TqAdvMin_tiTranCll;                                         */
/*  output boolean TqAdvMin_bAcvCll;                                          */
/*  output uint16 TqAdvMin_tqIncCll;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQADVMIN_vidInitOutput(void)
{
   VEMS_vidSET(TqAdvMin_tiTranCll,0);
   VEMS_vidSET(TqAdvMin_bAcvCll,1);
   VEMS_vidSET(TqAdvMin_tqIncCll,0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQADVMIN_vidRqestClosedLopTqmin1                           */
/* !Description :  determines the condition to require the closed loop for low*/
/*                 torque                                                     */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_05439_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MATHSRV_u16CalcParaIncAryU16(argin const uint16          */
/* kau16BreakpointMap[], argin uint16 u16Value, argin uint8                   */
/* u8BreakpointNumber);                                                       */
/*  extf argret void MATHSRV_u16Interp1d( argin const uint16                  */
/* kau16Cartography[], argin uint16 u16SiteInterpolation, uint16);            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 TqCmp_tqSumLossCmp;                                          */
/*  input sint16 TqLimEM_tqLimEM;                                             */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqAdvMin_nEng_A[6];                                          */
/*  input uint16 TqAdvMin_tqThdAcvCllLo_T[6];                                 */
/*  input uint16 TqAdvMin_tqAcvCllOfs_C;                                      */
/*  output boolean TqAdvMin_bAcvCll;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQADVMIN_vidRqestClosedLopTqmin1(void)
{
   sint16  s16LocalTqCmp_tqSumLossCmp;
   sint16  s16LocalTqLimEM_tqLimEM;
   uint16  u16LocalAdvMinEng;
   uint16  u16LocalnEng_nCkFil;
   uint16  u16LocalEng_nCkFil;
   sint32  s32LocalAdvMin_EngFil;
   sint32  s32LocalLow;
   sint32  s32LocalTqAdvMin_tqDif;


   VEMS_vidGET(TqCmp_tqSumLossCmp, s16LocalTqCmp_tqSumLossCmp);
   VEMS_vidGET(TqLimEM_tqLimEM, s16LocalTqLimEM_tqLimEM);
   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);

   s32LocalTqAdvMin_tqDif =
      (sint32)(s16LocalTqCmp_tqSumLossCmp + s16LocalTqLimEM_tqLimEM);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);
   u16LocalAdvMinEng =
      MATHSRV_u16CalcParaIncAryU16(TqAdvMin_nEng_A,
                                   u16LocalEng_nCkFil,
                                   6);

   u16LocalnEng_nCkFil =
      MATHSRV_u16Interp1d(TqAdvMin_tqThdAcvCllLo_T, u16LocalAdvMinEng);


   s32LocalAdvMin_EngFil =
      (sint32)(TqAdvMin_tqAcvCllOfs_C
      + ((u16LocalnEng_nCkFil * 16) - 32000));
   s32LocalLow = (sint32)((u16LocalnEng_nCkFil * 16) - 32000);

   if (s32LocalTqAdvMin_tqDif >= s32LocalAdvMin_EngFil)
   {
      VEMS_vidSET(TqAdvMin_bAcvCll, 0);
   }
   else
   {
      if (s32LocalLow >= s32LocalTqAdvMin_tqDif)
      {
         VEMS_vidSET(TqAdvMin_bAcvCll, 1);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQADVMIN_vidRqestClosedLopTqmin2                           */
/* !Description :  determines the value of the torque increment and the       */
/*                 maximum time allowed to reach the driver torque            */
/*                 (transition)                                               */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_11_05439_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MATHSRV_u16CalcParaIncAryU16(argin const uint16          */
/* kau16BreakpointMap[], argin uint16 u16Value, argin uint8                   */
/* u8BreakpointNumber);                                                       */
/*  extf argret void MATHSRV_u16Interp1d( argin const uint16                  */
/* kau16Cartography[], argin uint16 u16SiteInterpolation, uint16);            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint16 TqAdvMin_nEng_A[6];                                          */
/*  input uint16 TqAdvMin_tqIncCll_T[6];                                      */
/*  input uint16 TqAdvMin_tiTranCll_T[6];                                     */
/*  output uint16 TqAdvMin_tqIncCll;                                          */
/*  output uint16 TqAdvMin_tiTranCll;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQADVMIN_vidRqestClosedLopTqmin2(void)
{
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalAdvMinEng;
   uint16  u16LocalTqAdvMin_tqIncCll;
   uint16  u16LocalTqAdvMin_tiTranCll;

   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   u16LocalEng_nCkFil = (uint16)(u16LocalEng_nCkFil / 4);

   u16LocalAdvMinEng =
      MATHSRV_u16CalcParaIncAryU16(TqAdvMin_nEng_A,
                                   u16LocalEng_nCkFil,
                                   6);
   u16LocalTqAdvMin_tqIncCll =
      MATHSRV_u16Interp1d(TqAdvMin_tqIncCll_T, u16LocalAdvMinEng);
   u16LocalTqAdvMin_tqIncCll = (uint16)MATHSRV_udtMIN(u16LocalTqAdvMin_tqIncCll,
                                                      32000);

   u16LocalTqAdvMin_tiTranCll =
      MATHSRV_u16Interp1d(TqAdvMin_tiTranCll_T, u16LocalAdvMinEng);

   u16LocalTqAdvMin_tiTranCll =
      (uint16)MATHSRV_udtMIN(u16LocalTqAdvMin_tiTranCll, 500);
   VEMS_vidSET(TqAdvMin_tqIncCll, u16LocalTqAdvMin_tqIncCll);
   VEMS_vidSET(TqAdvMin_tiTranCll, u16LocalTqAdvMin_tiTranCll);
}

/*------------------------------- end of file --------------------------------*/