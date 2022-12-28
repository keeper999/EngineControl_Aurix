/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQCMPMANGBX                                             */
/* !Description     : TQCMPMANGBX Component                                   */
/*                                                                            */
/* !Module          : TQCMPMANGBX                                             */
/* !Description     : ESTIMATION OF MANUAL GEARBOX LOSSES                     */
/*                                                                            */
/* !File            : TQCMPMANGBX_FCT1.C                                      */
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
/*   1 / TQCMPMANGBX_vidInitOutput                                            */
/*   2 / TQCMPMANGBX_vidManualGearBoxLoss                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5199347 / 01                                        */
/* !OtherRefs   : 01460_12_02440 / 1.1                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::                                                                $*/
/* $Revision::            $$Author::                  $$Date::               $*/
/* $Author::                                          $$Date::               $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQCMPMANGBX.h"
#include "TQCMPMANGBX_L.h"
#include "TQCMPMANGBX_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCMPMANGBX_vidInitOutput                                  */
/* !Description :  Fonction d'initialisation des outputs                      */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint16 TqCmp_tOilFil;                                               */
/*  output uint16 TqCmp_tqAuxLoss;                                            */
/*  output uint16 TqCmp_tiEngRunClu;                                          */
/*  output sint16 TqCmp_tOilFil;                                              */
/*  output sint32 TQCMPMANGBX_s32TqCmptOilFilMem;                             */
/*  output uint32 TQCMPMANGBX_u32EOM_tiEngStopMem;                            */
/*  output uint16 TQCMPMANGBX_u16Eng_nCkFilPrev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCMPMANGBX_vidInitOutput(void)
{
   sint16  s16LocalExt_tOilMes;


   VEMS_vidSET(TqCmp_tqAuxLoss, 0);
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);

   TqCmp_tiEngRunClu = 0;
   TqCmp_tOilFil = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tOilMes, -500, 2000);
   TQCMPMANGBX_s32TqCmptOilFilMem = (sint32)(TqCmp_tOilFil * 256);
   TQCMPMANGBX_u32EOM_tiEngStopMem = 0;
   TQCMPMANGBX_u16Eng_nCkFilPrev = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQCMPMANGBX_vidManualGearBoxLoss                           */
/* !Description :  Function that estimates gearbox losses torque based on a   */
/*                 simulated gearbox  temperature.                            */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Mehdi.Fenina                                               */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input boolean Ext_bCluPedPrss;                                            */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input sint8 Ext_tAir;                                                     */
/*  input uint32 EOM_tiEngStop;                                               */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input sint16 TqCmp_tqLossExtSpc;                                          */
/*  input uint16 TQCMPMANGBX_u16Eng_nCkFilPrev;                               */
/*  input boolean TqDem_bManGBxLossClc;                                       */
/*  input uint16 TqCmp_tiEngRunClu;                                           */
/*  input uint8 TqCmp_facTOilFilManGBx_C;                                     */
/*  input sint32 TQCMPMANGBX_s32TqCmptOilFilMem;                              */
/*  input uint32 TQCMPMANGBX_u32EOM_tiEngStopMem;                             */
/*  input uint8 TqCmp_tOfsOilMinManGBx_C;                                     */
/*  input sint16 TqCmp_tOilFil;                                               */
/*  input uint16 TqCmp_tiEngStop_C;                                           */
/*  input uint8 TqCmp_tAirManGBxLossX_A[6];                                   */
/*  input uint16 TqCmp_tiStopManGBxY_A[6];                                    */
/*  input uint8 TqCmp_tManGBxLoss_M[6][6];                                    */
/*  input sint16 TqCmp_tManGBx_MP;                                            */
/*  input uint8 TqCmp_tManGBxX_A[6];                                          */
/*  input uint8 TqCmp_tiEngRunCluManGBxY_A[6];                                */
/*  input uint16 TqCmp_tqManGBxLoss_M[6][6];                                  */
/*  input boolean TqCmp_bInhTqManGBxLoss_C;                                   */
/*  output boolean TqDem_bManGBxLossClc;                                      */
/*  output uint16 TqCmp_tiEngRunClu;                                          */
/*  output uint16 TQCMPMANGBX_u16Eng_nCkFilPrev;                              */
/*  output sint32 TQCMPMANGBX_s32TqCmptOilFilMem;                             */
/*  output sint16 TqCmp_tOilFil;                                              */
/*  output uint32 TQCMPMANGBX_u32EOM_tiEngStopMem;                            */
/*  output sint16 TqCmp_tManGBx_MP;                                           */
/*  output uint16 TqCmp_tqAuxLoss;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQCMPMANGBX_vidManualGearBoxLoss(void)
{
   boolean bLocalExt_bCluPedPrss;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalTqCmp_tiEngRunClu;
   uint8   u8LocalInterp2D;
   uint8   u8LocalExt_tAir;
   uint8   u8LocalTqCmp_tManGBx_MP;
   sint8   s8LocalExt_tAir;
   uint16  u16LocalEng_nCkFil;
   uint16  u16LocalSum2;
   uint16  u16LocalKGain;
   uint16  u16LocalParaX1;
   uint16  u16LocalParaY1;
   uint16  u16LocalParaX2;
   uint16  u16LocalParaY2;
   uint16  u16LocalInterp2D;
   uint16  u16LocalOutSwitch2;
   uint16  u16LocaloutMem;
   uint16  u16LocalTqCmp_tiEngRunClu;
   sint16  s16LocalTqCmp_tManGBx_MP;
   sint16  s16LocalExt_tOilMes;
   sint16  s16LocalTqCmp_tqLossExtSpc;
   sint16  s16LocalnEngFilter;
   sint16  s16LocalSum;
   sint16  s16LocalExt_tAir;
   uint32  u32LocalEOM_tiEngStop;
   sint32  s32LocalSum2;


   VEMS_vidGET(Eng_nCkFil, u16LocalEng_nCkFil);
   VEMS_vidGET(Ext_bCluPedPrss, bLocalExt_bCluPedPrss);
   VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
   VEMS_vidGET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidGET(EOM_tiEngStop, u32LocalEOM_tiEngStop);
   VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
   VEMS_vidGET(TqCmp_tqLossExtSpc, s16LocalTqCmp_tqLossExtSpc);

   /*calcul de TqDem_bManGBxLossClc et TqCmp_tiEngRunClu*/
   if (  (u16LocalEng_nCkFil > 0)
      && (bLocalExt_bCluPedPrss == 0))
   {
      TqDem_bManGBxLossClc = 1;
   }
   else
   {
      TqDem_bManGBxLossClc = 0;
   }

   if (  (u16LocalEng_nCkFil == 0)
      && (TQCMPMANGBX_u16Eng_nCkFilPrev > 0))
   {
      TqCmp_tiEngRunClu = 0;
   }
   else
   {
      if (TqDem_bManGBxLossClc != 0)
      {
         if (TqCmp_tiEngRunClu >= 65500)
         {
            TqCmp_tiEngRunClu = 65500;
         }
         else
         {
            TqCmp_tiEngRunClu = (uint16)(TqCmp_tiEngRunClu + 1);
         }
      }
      else
      {
         TqCmp_tiEngRunClu = (uint16)MATHSRV_udtMIN(TqCmp_tiEngRunClu, 65500);
      }
   }
   TQCMPMANGBX_u16Eng_nCkFilPrev = (uint16)MATHSRV_udtMIN(u16LocalEng_nCkFil,
                                                          32000);
   /*calcul of TqCmp_tOilFil*/
   if (bLocalExt_bCluPedPrss != 0)
   {
      u16LocalKGain = 0;
   }
   else
   {
      u16LocalKGain = (uint16)(TqCmp_facTOilFilManGBx_C * 2);
   }
   if (u16LocalKGain >= 255)
   {
      s16LocalnEngFilter = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tOilMes,
                                                    -500,
                                                    2000);
      TQCMPMANGBX_s32TqCmptOilFilMem = (sint32)(s16LocalnEngFilter * 256);
   }
   else
   {
      s16LocalnEngFilter =
         MATHSRV_s16FirstOrderFilterGu8((uint8)u16LocalKGain,
                                        &TQCMPMANGBX_s32TqCmptOilFilMem,
                                        s16LocalExt_tOilMes);
   }
   TqCmp_tOilFil = (sint16)MATHSRV_udtCLAMP(s16LocalnEngFilter, -500, 2000);

   /* Calcul of TQCMPMANGBX_u32EOM_tiEngStopMem */
   if (u8LocalCoPTSt_stEng == 5)
   {
      TQCMPMANGBX_u32EOM_tiEngStopMem =
         MATHSRV_udtMIN(TQCMPMANGBX_u32EOM_tiEngStopMem, 864000);
   }
   else
   {
      s16LocalSum = (sint16)((TqCmp_tOfsOilMinManGBx_C + s8LocalExt_tAir) * 10);
      if (TqCmp_tOilFil <= s16LocalSum)
      {
         TQCMPMANGBX_u32EOM_tiEngStopMem = TqCmp_tiEngStop_C;
      }
      else
      {
         TQCMPMANGBX_u32EOM_tiEngStopMem = MATHSRV_udtMIN(u32LocalEOM_tiEngStop,
                                                          864000);
      }
   }
   /*Calcul of TqCmp_tManGBx_MP*/
   s16LocalExt_tAir = (sint16)(s8LocalExt_tAir + 40);
   u8LocalExt_tAir = (uint8)MATHSRV_udtMAX(s16LocalExt_tAir, 0);
   u16LocalParaX1 = MATHSRV_u16CalcParaIncAryU8(TqCmp_tAirManGBxLossX_A,
                                                u8LocalExt_tAir,
                                                6);
   u16LocaloutMem = (uint16)MATHSRV_udtMIN(TQCMPMANGBX_u32EOM_tiEngStopMem,
                                           65535);
   u16LocalParaY1 = MATHSRV_u16CalcParaIncAryU16(TqCmp_tiStopManGBxY_A,
                                                 u16LocaloutMem,
                                                 6);
   u8LocalInterp2D = MATHSRV_u8Interp2d(&TqCmp_tManGBxLoss_M[0][0],
                                        u16LocalParaX1,
                                        u16LocalParaY1,
                                        6);
   s16LocalTqCmp_tManGBx_MP =(sint16)(u8LocalInterp2D - 50);
   TqCmp_tManGBx_MP = (sint16)MATHSRV_udtMIN(s16LocalTqCmp_tManGBx_MP, 200);
   /*Calcul of u16LocalInterp2D*/
   u8LocalTqCmp_tManGBx_MP = (uint8)(TqCmp_tManGBx_MP + 50);
   u16LocalParaX2 = MATHSRV_u16CalcParaIncAryU8(TqCmp_tManGBxX_A,
                                                u8LocalTqCmp_tManGBx_MP,
                                                6);
   u16LocalTqCmp_tiEngRunClu = (uint16)((TqCmp_tiEngRunClu + 50) / 100);
   u8LocalTqCmp_tiEngRunClu =
      (uint8)MATHSRV_udtMIN(u16LocalTqCmp_tiEngRunClu, 255);
   u16LocalParaY2 = MATHSRV_u16CalcParaIncAryU8(TqCmp_tiEngRunCluManGBxY_A,
                                                u8LocalTqCmp_tiEngRunClu,
                                                6);
   u16LocalInterp2D = MATHSRV_u16Interp2d(&TqCmp_tqManGBxLoss_M[0][0],
                                          u16LocalParaX2,
                                          u16LocalParaY2,
                                          6);
   if (  (TqDem_bManGBxLossClc == 0)
      || (TqCmp_bInhTqManGBxLoss_C != 0))
   {
      u16LocalOutSwitch2 = 0;
   }
   else
   {
      u16LocalOutSwitch2 = u16LocalInterp2D;
   }
   /*Calcul of TqCmp_tqAuxLoss */
   s32LocalSum2 = (sint32)(s16LocalTqCmp_tqLossExtSpc + u16LocalOutSwitch2);
   u16LocalSum2 = (uint16)MATHSRV_udtCLAMP(s32LocalSum2, 0, 8000);
   VEMS_vidSET(TqCmp_tqAuxLoss, u16LocalSum2);
}
/*---------------------------------End Of File--------------------------------*/