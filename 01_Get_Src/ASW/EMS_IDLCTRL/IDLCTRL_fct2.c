/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : IDLCTRL                                                 */
/* !Description     : IDLCTRL Component                                       */
/*                                                                            */
/* !Module          : IDLCTRL                                                 */
/* !Description     : Régulateur de régime ralenti                            */
/*                                                                            */
/* !File            : IDLCTRL_FCT2.c                                          */
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
/*   1 / IDLCTRL_vidBorner_correction                                         */
/*   2 / IDLCTRL_vidCalc_correction_PID                                       */
/*   3 / IDLCTRL_vidCalc_terme_regulateur                                     */
/*   4 / IDLCTRL_vidAppliquer_SBPA                                            */
/*   5 / IDLCTRL_vidCalc_regulateur_air                                       */
/*   6 / IDLCTRL_vidCoord_couples_ralenti                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5659858 / 01                                        */
/* !Reference   : PTS_DOC_5700651 / 01                                        */
/* !OtherRefs   : CSMT_CGMT08_1336 / 2.5                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/IDLCTRL/IDLCTRL_F$*/
/* $Revision::   1.19                                                        $*/
/* $Author::   mbenfrad                               $$Date::   21 Oct 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "IDLCTRL.h"
#include "IDLCTRL_L.h"
#include "IDLCTRL_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidBorner_correction                               */
/* !Description :  Fonction qui calcule la saturation maximale et minimale de */
/*                 la correction du régulateur avance..                       */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_010.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input boolean IdlSys_bAcvBrk;                                             */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input sint16 IdlSys_tqIdcIdlMax;                                          */
/*  input sint16 IdlSys_tqIdcIdlStab;                                         */
/*  input sint16 IdlSys_tqIdcIdlMin;                                          */
/*  input sint16 IdlSys_nErrIdlCtlPID;                                        */
/*  input uint16 IdlSys_nErrIdlCorLim_A[8];                                   */
/*  input uint16 IdlSys_tqIdlCorMaxNorm_M[4][8];                              */
/*  input uint16 IdlSys_tqIdlCorMaxBrk_M[4][8];                               */
/*  input uint16 IdlSys_tqIncMaxIdlCorMax_C;                                  */
/*  input sint16 IdlSys_tqDecMaxIdlCorMax_C;                                  */
/*  input uint16 IDLCTRL_u16RatLimOutput;                                     */
/*  output uint16 IDLCTRL_u16RatLimOutput;                                    */
/*  output sint16 IdlSys_tqIdlCorMax;                                         */
/*  output sint16 IdlSys_tqIdlCorMin;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidBorner_correction(void)
{
   boolean  bLocalIdlSys_bAcvBrk;
   boolean  bLocalIdlSys_bIniIdlCtl;
   uint8    u8LocalIdlSys_noGear;
   uint8    u8LocalExt_tiTDC;
   uint16   u16LocalParaColumn;
   uint16   u16LocalParaLine;
   uint16   u16LocalIdlSys_nErrIdlCtlPID;
   uint16   u16LocalRatLimInput;
   uint16   u16LocalRatLimOutput;
   uint16   u16LocalRateLimInc;
   uint16   u16LocalRateLimDec;
   sint16   s16LocalIdlSys_nErrIdlCtlPID;
   sint16   s16LocalRateLimDec;
   sint16   s16LocalRatLimOutput;
   sint16   s16LocalIdlSys_tqIdcIdlMax;
   sint16   s16LocalIdlSys_tqIdcIdlStab;
   sint16   s16LocalIdlSys_tqIdcIdlMin;
   sint32   s32LocalDiffMax;
   sint32   s32LocalDiffMin;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(IdlSys_bAcvBrk, bLocalIdlSys_bAcvBrk);
   VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);
   VEMS_vidGET(IdlSys_tqIdcIdlMax, s16LocalIdlSys_tqIdcIdlMax);
   VEMS_vidGET(IdlSys_tqIdcIdlStab, s16LocalIdlSys_tqIdcIdlStab);
   VEMS_vidGET(IdlSys_tqIdcIdlMin, s16LocalIdlSys_tqIdcIdlMin);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   s16LocalIdlSys_nErrIdlCtlPID = (sint16)((IdlSys_nErrIdlCtlPID / 4) + 8000);
   u16LocalIdlSys_nErrIdlCtlPID =
      (uint16)MATHSRV_udtMAX(s16LocalIdlSys_nErrIdlCtlPID, 0);

   u16LocalParaColumn =
      MATHSRV_u16CalcParaIncAryU16(IdlSys_nErrIdlCorLim_A,
                                   u16LocalIdlSys_nErrIdlCtlPID,
                                   8);

   /*Production of Rate Limiter Input*/
   if (bLocalIdlSys_bAcvBrk == 0)
   {
      u16LocalRatLimInput = MATHSRV_u16Interp2d(&IdlSys_tqIdlCorMaxNorm_M[0][0],
                                                u16LocalParaLine,
                                                u16LocalParaColumn,
                                                8);
   }
   else
   {
      u16LocalRatLimInput = MATHSRV_u16Interp2d(&IdlSys_tqIdlCorMaxBrk_M[0][0],
                                                u16LocalParaLine,
                                                u16LocalParaColumn,
                                                8);
   }

   /*Production of Rate Limiter Output*/
   if (bLocalIdlSys_bIniIdlCtl != 0)
   {
      /*Production of Inc and Dec parameters*/
      u16LocalRateLimInc = (uint16)( ( (uint32)( IdlSys_tqIncMaxIdlCorMax_C
                                               * u8LocalExt_tiTDC)
                                     + 500)
                                   / 1000);

      s16LocalRateLimDec =
         (sint16)MATHSRV_udtMIN(IdlSys_tqDecMaxIdlCorMax_C, 0);
      u16LocalRateLimDec = (uint16)((-1) * s16LocalRateLimDec);
      u16LocalRateLimDec = (uint16)( ( (uint32)( u16LocalRateLimDec
                                               * u8LocalExt_tiTDC)
                                     + 500)
                                   / 1000);

      u16LocalRatLimOutput = MATHSRV_u16SlewFilter(IDLCTRL_u16RatLimOutput,
                                                   u16LocalRatLimInput,
                                                   u16LocalRateLimInc,
                                                   u16LocalRateLimDec);
      IDLCTRL_u16RatLimOutput =
         (uint16)MATHSRV_udtMIN(u16LocalRatLimOutput, 16000);
   }
   else
   {
      IDLCTRL_u16RatLimOutput =
         (uint16)MATHSRV_udtMIN(u16LocalRatLimInput, 16000);
   }

   /*Production of IdlSys_tqIdlCorMax and IdlSys_tqIdlCorMin*/
   s16LocalRatLimOutput = (sint16)((IDLCTRL_u16RatLimOutput * 4) - 32000);
   s32LocalDiffMax = s16LocalIdlSys_tqIdcIdlMax - s16LocalIdlSys_tqIdcIdlStab;

   if (s16LocalRatLimOutput <= s32LocalDiffMax)
   {
      IdlSys_tqIdlCorMax = s16LocalRatLimOutput;
   }
   else
   {
      IdlSys_tqIdlCorMax =
         (sint16)MATHSRV_udtMAX(s32LocalDiffMax, -32000);
   }

   s32LocalDiffMin = s16LocalIdlSys_tqIdcIdlMin - s16LocalIdlSys_tqIdcIdlStab;
   IdlSys_tqIdlCorMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalDiffMin, -32000, 32000);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCalc_correction_PID                             */
/* !Description :  Fonction de calcul du régulateur PID.                      */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_011.03                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void IDLCTRL_vidCalc_terme_regulateur();                      */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input sint16 IdlSys_nErrIdlCtl1;                                          */
/*  input sint16 IDLCTRL_s16EngErrIdlCtlPrev;                                 */
/*  input sint32 IDLCTRL_s32TqIdlCor;                                         */
/*  input sint32 IdlSys_tqIdlCor;                                             */
/*  input sint16 IdlSys_nErrIdlCtlPID;                                        */
/*  input sint16 IdlSys_tqIdlCorIni;                                          */
/*  input uint16 IdlSys_facFilIdlCtl;                                         */
/*  input uint16 IdlSys_facDerIdlCtl;                                         */
/*  input uint16 IdlSys_facPropIdlCtl;                                        */
/*  input uint16 IdlSys_facIntIdlCtl;                                         */
/*  input sint16 IdlSys_nErrIdlCtl2;                                          */
/*  input sint16 IdlSys_tqOfsIdlCorSatMin_C;                                  */
/*  input sint16 IdlSys_tqIdlCorMin;                                          */
/*  input uint16 IdlSys_tqOfsIdlCorSatMax_C;                                  */
/*  input sint16 IdlSys_tqIdlCorMax;                                          */
/*  input sint32 IdlSys_tqIdlCorNotSat_MP;                                    */
/*  input sint16 IdlSys_tqIdlCorSatMin;                                       */
/*  output sint16 IdlSys_nErrIdlCtl2;                                         */
/*  output sint16 IdlSys_nErrIdlCtl1;                                         */
/*  output sint32 IDLCTRL_s32TqIdlCor;                                        */
/*  output sint32 IdlSys_tqIdlCorNotSat_MP;                                   */
/*  output sint32 IdlSys_tqIdlCor;                                            */
/*  output sint16 IdlSys_tqIdlCorSatMin;                                      */
/*  output sint16 IdlSys_tqIdlCorPID;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCalc_correction_PID(void)
{
   boolean bLocalIdlSys_bIniIdlCtl;
   uint32  u32LocalFacFilIdlCtl;
   uint32  u32LocalFacDerIdlCtl;
   uint32  u32LocalTqIdlCorNotSat;
   uint32  u32LocalMod;
   sint16  s16LocalIdlSys_tqIdlCorPID;
   sint16  s16LocalIdlSys_nErrIdlCtlPID;
   sint32  s32LocalTqIdlCor;
   sint32  s32LocalMaxValue;
   sint32  s32LocalMod;
   sint32  s32LocalResidue;
   sint32  s32LocalTqIdlCorNotSat1;
   sint32  s32LocalTqIdlCorNotSat2;
   sint32  s32LocalTqIdlCorNotSat3;
   sint32  s32LocalTqIdlCorNotSat4;
   sint32  s32LocalTqIdlCorNotSat;
   sint32  s32LocalMax1;
   sint32  s32LocalMin1;
   sint32  s32LocalSommeCorMin;
   sint32  s32LocalSommeCorMax;
   sint32  s32Localoutputswitch;
   sint32  s32LocalIdlSys_tqIdlCorSatMin;


   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);

   /*Production of IdlSys_nErrIdlCtl1 and IdlSys_nErrIdlCtl2*/
   if (bLocalIdlSys_bIniIdlCtl == 0)
   {
      IdlSys_nErrIdlCtl2 =
         (sint16)MATHSRV_udtCLAMP(IdlSys_nErrIdlCtl1, -32000, 32000);
      IdlSys_nErrIdlCtl1 =
         (sint16)MATHSRV_udtCLAMP(IDLCTRL_s16EngErrIdlCtlPrev, -32000, 32000);
      s32LocalTqIdlCor =
         MATHSRV_udtCLAMP(IDLCTRL_s32TqIdlCor, -65536000, 65536000);
      IDLCTRL_s32TqIdlCor =
         MATHSRV_udtCLAMP(IdlSys_tqIdlCor, -65536000, 65536000);
   }
   else
   {
      s16LocalIdlSys_nErrIdlCtlPID =
         (sint16)MATHSRV_udtCLAMP(IdlSys_nErrIdlCtlPID, -32000, 32000);
      IdlSys_nErrIdlCtl1 = s16LocalIdlSys_nErrIdlCtlPID;
      IdlSys_nErrIdlCtl2 = s16LocalIdlSys_nErrIdlCtlPID;

      s32LocalTqIdlCor = (sint32)(IdlSys_tqIdlCorIni * 2048);
      s32LocalTqIdlCor =
         MATHSRV_udtCLAMP(s32LocalTqIdlCor, -65536000, 65536000);
      IDLCTRL_s32TqIdlCor = s32LocalTqIdlCor;
   }

   /*Production of IdlSys_tqIdlCorNotSat_MP*/
   u32LocalFacFilIdlCtl = (uint32)(IdlSys_facFilIdlCtl + 1024);
   u32LocalFacDerIdlCtl = (uint32)(IdlSys_facDerIdlCtl * 512);

   /*Production of s32LocalTqIdlCorNotSat1*/

   if (IdlSys_nErrIdlCtlPID == 0)
   {
      s32LocalTqIdlCorNotSat1 = 0;
   }
   else
   {
      u32LocalTqIdlCorNotSat = ( (uint32)( IdlSys_facPropIdlCtl
                                         * IdlSys_facFilIdlCtl)
                               / 4)
                             + ( (uint32)( IdlSys_facIntIdlCtl
                                         * IdlSys_facFilIdlCtl)
                               / 4)
                             + (uint32)(256 * ( IdlSys_facPropIdlCtl
                                              + IdlSys_facIntIdlCtl
                                              + IdlSys_facDerIdlCtl));
      /*u32LocalTqIdlCorNotSat (Max) = 2197748992*/

      s32LocalMaxValue = SINT32_MAX / (sint32)IdlSys_nErrIdlCtlPID;
      s32LocalMaxValue = MATHSRV_udtABS(s32LocalMaxValue);

      if (u32LocalTqIdlCorNotSat < (uint32)s32LocalMaxValue)
      {
         s32LocalTqIdlCorNotSat1 = ( (sint32)u32LocalTqIdlCorNotSat
                                   * IdlSys_nErrIdlCtlPID)
                                 / ((sint32)u32LocalFacFilIdlCtl);
      }
      else
      {
         u32LocalMod = u32LocalTqIdlCorNotSat % u32LocalFacFilIdlCtl;
         /*u32LocalMod (Max) = 66558*/

         u32LocalMod = (u32LocalMod + 1) / 2;
         s32LocalResidue = ((sint32)u32LocalMod * IdlSys_nErrIdlCtlPID)
                         / ((sint32)u32LocalFacFilIdlCtl);
         s32LocalResidue = s32LocalResidue * 2;

         s32LocalTqIdlCorNotSat1 = ( (sint32)( u32LocalTqIdlCorNotSat
                                             / u32LocalFacFilIdlCtl)
                                   * IdlSys_nErrIdlCtlPID)
                                 + s32LocalResidue;
      }
   }

   /*Production of s32LocalTqIdlCorNotSat2*/

   if (IdlSys_nErrIdlCtl1 == 0)
   {
      s32LocalTqIdlCorNotSat2 = 0;
   }
   else
   {
      u32LocalTqIdlCorNotSat = (uint32)( ( IdlSys_facPropIdlCtl
                                         * IdlSys_facFilIdlCtl)
                                       / 2)
                             + (uint32)(IdlSys_facPropIdlCtl * 256)
                             + ( (uint32)( IdlSys_facFilIdlCtl
                                         * IdlSys_facIntIdlCtl)
                               / 4)
                             + u32LocalFacDerIdlCtl;
      /*u32LocalTqIdlCorNotSat (Max) = 3237904128*/

      s32LocalMaxValue = SINT32_MAX / (sint32)IdlSys_nErrIdlCtl1;
      s32LocalMaxValue = MATHSRV_udtABS(s32LocalMaxValue);

      if (u32LocalTqIdlCorNotSat < (uint32)s32LocalMaxValue)
      {
         s32LocalTqIdlCorNotSat2 = ( (sint32)u32LocalTqIdlCorNotSat
                                   * IdlSys_nErrIdlCtl1)
                                 / ((sint32)u32LocalFacFilIdlCtl);
      }
      else
      {
         u32LocalMod = u32LocalTqIdlCorNotSat % u32LocalFacFilIdlCtl;
         /*u32LocalMod (Max) = 66558*/

         u32LocalMod = (u32LocalMod + 1) / 2;
         s32LocalResidue = ((sint32)u32LocalMod * IdlSys_nErrIdlCtl1)
                         / ((sint32)u32LocalFacFilIdlCtl);
         s32LocalResidue = s32LocalResidue * 2;

         s32LocalTqIdlCorNotSat2 =  ( (sint32)( u32LocalTqIdlCorNotSat
                                              / u32LocalFacFilIdlCtl)
                                    * IdlSys_nErrIdlCtl1)
                                 +  s32LocalResidue;
      }
   }
   /*Production of s32LocalTqIdlCorNotSat3*/
   if (IdlSys_nErrIdlCtl2 == 0)
   {
      s32LocalTqIdlCorNotSat3 = 0;
   }
   else
   {
      u32LocalTqIdlCorNotSat = ( (uint32)( IdlSys_facPropIdlCtl
                                         * IdlSys_facFilIdlCtl)
                               / 2)
                             + u32LocalFacDerIdlCtl;
      /*u32LocalTqIdlCorNotSat (Max) = 2180972033*/

      s32LocalMaxValue = SINT32_MAX / (sint32)IdlSys_nErrIdlCtl2;
      s32LocalMaxValue = MATHSRV_udtABS(s32LocalMaxValue);

      if (u32LocalTqIdlCorNotSat < (uint32)s32LocalMaxValue)
      {
         s32LocalTqIdlCorNotSat3 = ( (sint32)u32LocalTqIdlCorNotSat
                                   * IdlSys_nErrIdlCtl2)
                                 / ((sint32)u32LocalFacFilIdlCtl);
      }
      else
      {
         u32LocalMod = u32LocalTqIdlCorNotSat % u32LocalFacFilIdlCtl;
         /*u32LocalMod (Max) = 66558*/

         u32LocalMod = (u32LocalMod + 1) / 2;
         s32LocalResidue = ((sint32)u32LocalMod * IdlSys_nErrIdlCtl2)
                         / ((sint32)u32LocalFacFilIdlCtl);
         s32LocalResidue = s32LocalResidue * 2;

         s32LocalTqIdlCorNotSat3 = ( (sint32)( u32LocalTqIdlCorNotSat
                                             / u32LocalFacFilIdlCtl)
                                   * IdlSys_nErrIdlCtl2)
                                 +  s32LocalResidue;
      }
   }

   /*Production of s32LocalTqIdlCorNotSat4*/

   s32LocalTqIdlCorNotSat4 = (IDLCTRL_s32TqIdlCor - s32LocalTqIdlCor);

   if (s32LocalTqIdlCorNotSat4 == 0)
   {
      s32LocalTqIdlCorNotSat4 = IDLCTRL_s32TqIdlCor;
   }
   else
   {
      s32LocalMaxValue = SINT32_MAX / s32LocalTqIdlCorNotSat4;
      s32LocalMaxValue = MATHSRV_udtABS(s32LocalMaxValue);

      if (IdlSys_facFilIdlCtl < s32LocalMaxValue)
      {
         s32LocalTqIdlCorNotSat4 = ( (sint32)IdlSys_facFilIdlCtl
                                   * s32LocalTqIdlCorNotSat4)
                                 / ((sint32)u32LocalFacFilIdlCtl);
         s32LocalTqIdlCorNotSat4 = s32LocalTqIdlCorNotSat4
                                 + IDLCTRL_s32TqIdlCor;
      }
      else
      {
         s32LocalMod = s32LocalTqIdlCorNotSat4 % (sint32)u32LocalFacFilIdlCtl;

         if (s32LocalMod > 0)
         {
            s32LocalMod = (s32LocalMod + 2) / 4;
         }
         else
         {
            s32LocalMod = (s32LocalMod - 2) / 4;
         }

         s32LocalResidue = (s32LocalMod * (sint32)IdlSys_facFilIdlCtl)
                         / ((sint32)u32LocalFacFilIdlCtl);
         s32LocalResidue = s32LocalResidue * 4;

         s32LocalMaxValue = MATHSRV_udtABS(s32LocalTqIdlCorNotSat4);
         if (s32LocalMaxValue >= (sint32)u32LocalFacFilIdlCtl)
         {
            s32LocalTqIdlCorNotSat4 = ( ( s32LocalTqIdlCorNotSat4
                                        / (sint32)u32LocalFacFilIdlCtl)
                                      * ((sint32)IdlSys_facFilIdlCtl))
                                    + s32LocalResidue
                                    + IDLCTRL_s32TqIdlCor;
         }
         else
         {
            s32LocalTqIdlCorNotSat4 = IDLCTRL_s32TqIdlCor + s32LocalResidue;
         }
      }
   }

   /*s32LocalTqIdlCorNotSat1 (Max) = 1081984990*/
   /*s32LocalTqIdlCorNotSat2 (Max) = 1594069058*/
   /*s32LocalTqIdlCorNotSat3 (Max) = 1073725440*/
   /*s32LocalTqIdlCorNotSat4 (Max) =   65664000*/

   if (s32LocalTqIdlCorNotSat1 > 0)
   {
      s32LocalTqIdlCorNotSat1 = (s32LocalTqIdlCorNotSat1 + 1) / 2;
   }
   else
   {
      s32LocalTqIdlCorNotSat1 = (s32LocalTqIdlCorNotSat1 - 1) / 2;
   }

   if (s32LocalTqIdlCorNotSat2 > 0)
   {
      s32LocalTqIdlCorNotSat2 = (s32LocalTqIdlCorNotSat2 + 1) / 2;
   }
   else
   {
      s32LocalTqIdlCorNotSat2 = (s32LocalTqIdlCorNotSat2 - 1) / 2;
   }

   if (s32LocalTqIdlCorNotSat3 > 0)
   {
      s32LocalTqIdlCorNotSat3 = (s32LocalTqIdlCorNotSat3 + 2) / 4;
   }
   else
   {
      s32LocalTqIdlCorNotSat3 = (s32LocalTqIdlCorNotSat3 - 2) / 4;
   }

   if (s32LocalTqIdlCorNotSat4 > 0)
   {
      s32LocalTqIdlCorNotSat4 = (s32LocalTqIdlCorNotSat4 + 2) / 4;
   }
   else
   {
      s32LocalTqIdlCorNotSat4 = (s32LocalTqIdlCorNotSat4 - 2) / 4;
   }

   s32LocalTqIdlCorNotSat = (s32LocalTqIdlCorNotSat1 - s32LocalTqIdlCorNotSat2)
                          + (s32LocalTqIdlCorNotSat3 + s32LocalTqIdlCorNotSat4);

   s32LocalTqIdlCorNotSat =
      MATHSRV_udtCLAMP(s32LocalTqIdlCorNotSat, -16384000, 16384000);

   IdlSys_tqIdlCorNotSat_MP = s32LocalTqIdlCorNotSat * 4;

   /* Production of IdlSys_tqIdlCorSatMin*/

   s32LocalSommeCorMin = ( IdlSys_tqOfsIdlCorSatMin_C
                         + IdlSys_tqIdlCorMin)
                       * 2048;
   s32LocalSommeCorMax = ( IdlSys_tqOfsIdlCorSatMax_C
                         + IdlSys_tqIdlCorMax)
                       * 2048;

   if (bLocalIdlSys_bIniIdlCtl == 0)
   {
      s32Localoutputswitch = IdlSys_tqIdlCorNotSat_MP;
   }
   else
   {
      s32Localoutputswitch = IdlSys_tqIdlCorIni * 2048;
   }
   s32LocalMax1 = MATHSRV_udtMAX(s32Localoutputswitch, s32LocalSommeCorMin);

   s32LocalMin1 = MATHSRV_udtMIN(s32LocalSommeCorMax, s32LocalMax1);

   /*Production of IdlSys_tqIdlCor*/
   IdlSys_tqIdlCor =
      MATHSRV_udtCLAMP(s32LocalMin1, -65536000, 65536000);

   /*Production of IdlSys_tqIdlCorSatMin*/
   s32LocalMin1 = s32LocalMin1 / 2048;
   s32LocalIdlSys_tqIdlCorSatMin =
      MATHSRV_udtMAX(s32LocalMin1, IdlSys_tqIdlCorMin);
   IdlSys_tqIdlCorSatMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_tqIdlCorSatMin, -32000, 32000);

   /*Production of IdlSys_tqIdlCorPID*/
   s16LocalIdlSys_tqIdlCorPID =
      (sint16)MATHSRV_udtMIN(IdlSys_tqIdlCorSatMin, IdlSys_tqIdlCorMax);

   IdlSys_tqIdlCorPID =
      (sint16)MATHSRV_udtMAX(s16LocalIdlSys_tqIdlCorPID, -32000);

   /*F01_05_01_Calculer_termes_regulateur*/
   IDLCTRL_vidCalc_terme_regulateur();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCalc_terme_regulateur                           */
/* !Description :  Fonction qui recalcule les différents termes du régulateur */
/*                 PID. Ce besoin sert juste pour la mise au point de la      */
/*                 fonction.                                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_012.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_nErrIdlCtlPID;                                        */
/*  input uint16 IdlSys_facPropIdlCtl;                                        */
/*  input sint16 IdlSys_nErrIdlCtl1;                                          */
/*  input uint16 IdlSys_facDerIdlCtl;                                         */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input uint16 IdlSys_facFilIdlCtl;                                         */
/*  input sint16 IdlSys_tqIdlCorDer_MP;                                       */
/*  input sint16 IdlSys_tqIdlCorDerFil_MP;                                    */
/*  input sint32 IdlSys_tqIdlCor;                                             */
/*  input sint16 IdlSys_tqIdlCorProp_MP;                                      */
/*  output sint16 IdlSys_tqIdlCorProp_MP;                                     */
/*  output sint16 IdlSys_tqIdlCorDer_MP;                                      */
/*  output sint16 IdlSys_tqIdlCorDerFil_MP;                                   */
/*  output sint16 IdlSys_tqIdlCorInt_MP;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCalc_terme_regulateur(void)
{
   boolean bLocalIdlSys_bIniIdlCtl;
   uint32  u32LocalVar;
   sint32  s32LocalVar;
   sint32  s32LocalFacFilIdlCtl;
   sint32  s32LocalTqIdlCorDer;
   sint32  s32LocalTqIdlCorDerFil;
   sint32  s32LocalIdlSys_tqIdlCor;


   /*Production of IdlSys_tqIdlCorProp_MP*/
   if (IdlSys_nErrIdlCtlPID > 0)
   {
      s32LocalVar = (sint32)( ( ( IdlSys_facPropIdlCtl
                                * IdlSys_nErrIdlCtlPID)
                              + 2048)
                            / 4096);
   }
   else
   {
      s32LocalVar = (sint32)( ( ( IdlSys_facPropIdlCtl
                                * IdlSys_nErrIdlCtlPID)
                              - 2048)
                            / 4096);
   }
   IdlSys_tqIdlCorProp_MP =
      (sint16)MATHSRV_udtCLAMP(s32LocalVar, -32000, 32000);

   /*Production of IdlSys_tqIdlCorDer_MP*/
   if (IdlSys_nErrIdlCtlPID > IdlSys_nErrIdlCtl1)
   {
      s32LocalVar = (sint32)( (uint32)( ( IdlSys_facDerIdlCtl
                                        * ( IdlSys_nErrIdlCtlPID
                                          - IdlSys_nErrIdlCtl1))
                                      + 2048)
                            / 4096);
      IdlSys_tqIdlCorDer_MP = (sint16)MATHSRV_udtMIN(s32LocalVar, 32000);
   }
   else
   {
      s32LocalVar = (sint32)( (uint32)( ( IdlSys_facDerIdlCtl
                                        * ( IdlSys_nErrIdlCtl1
                                          - IdlSys_nErrIdlCtlPID))
                                      + 2048)
                            / 4096);
      s32LocalVar = MATHSRV_udtMIN(s32LocalVar, 32000);
      IdlSys_tqIdlCorDer_MP = (sint16)((-1) * s32LocalVar);
   }

   /*Production of IdlSys_tqIdlCorDerFil_MP*/
   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);
   if (bLocalIdlSys_bIniIdlCtl == 0)
   {
      if ( IdlSys_facFilIdlCtl == 0)
      {
         IdlSys_tqIdlCorDerFil_MP = IdlSys_tqIdlCorDer_MP;
      }
      else
      {
         s32LocalTqIdlCorDer = (sint32)(IdlSys_tqIdlCorDer_MP * 1024);
         s32LocalTqIdlCorDerFil =
            (sint32)(IdlSys_tqIdlCorDerFil_MP * IdlSys_facFilIdlCtl);
         s32LocalFacFilIdlCtl = (sint32)(IdlSys_facFilIdlCtl + 1024);

         if (  (s32LocalTqIdlCorDerFil >= 0)
            && (s32LocalTqIdlCorDer >= 0))
         {

            u32LocalVar = (uint32)( ( s32LocalTqIdlCorDerFil
                                    + s32LocalTqIdlCorDer)
                                  / s32LocalFacFilIdlCtl);
            IdlSys_tqIdlCorDerFil_MP =
               (sint16)MATHSRV_udtMIN(u32LocalVar, 32000);
         }
         else
         {
            if (  (s32LocalTqIdlCorDerFil < 0)
               && (s32LocalTqIdlCorDer < 0))
            {
               u32LocalVar = (uint32)( ( ((-1) * s32LocalTqIdlCorDerFil)
                                       + ((-1) * s32LocalTqIdlCorDer))
                                     / s32LocalFacFilIdlCtl);
               s32LocalVar = (sint32)MATHSRV_udtMIN(u32LocalVar, 32000);
               IdlSys_tqIdlCorDerFil_MP = (sint16)((-1) * s32LocalVar);
            }
            else
            {
               s32LocalVar = ( s32LocalTqIdlCorDerFil
                             + s32LocalTqIdlCorDer)
                           / s32LocalFacFilIdlCtl;
               IdlSys_tqIdlCorDerFil_MP = (sint16)s32LocalVar;
            }
         }
      }
   }
   else
   {
      IdlSys_tqIdlCorDerFil_MP = 0;
   }

   /*Production of IdlSys_tqIdlCorInt_MP*/
   s32LocalIdlSys_tqIdlCor = IdlSys_tqIdlCor / 2048;
   s32LocalVar = ( s32LocalIdlSys_tqIdlCor
                 - IdlSys_tqIdlCorProp_MP
                 - IdlSys_tqIdlCorDerFil_MP);
   IdlSys_tqIdlCorInt_MP =
      (sint16)MATHSRV_udtCLAMP(s32LocalVar, -32000, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidAppliquer_SBPA                                  */
/* !Description :  Le paramètre de mise au point « IdlSys_bAcvSBPA_C » permet */
/*                 de substituer la correction du régulateur avance par un    */
/*                 signal en provenance d’un générateur de SBPA.              */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_013.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input sint16 IdlSys_tqIdcIdlStab;                                         */
/*  input boolean IdlSys_bAcvSBPA_C;                                          */
/*  input sint16 IdlSys_tqIdlCorPID;                                          */
/*  input sint16 IdlSys_tqIdlCorSatMin;                                       */
/*  input sint16 TqSys_tqIdcSBPA;                                             */
/*  output sint16 IdlSys_tqIdcIdlRaw;                                         */
/*  output sint16 IdlSys_tqIdcIdlSatMin;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidAppliquer_SBPA(void)
{
   sint16 s16LocalIdlSys_tqIdcIdlStab;
   sint16 s16LocalTqSys_tqIdcSBPA;
   sint32 s32LocalIdlSys_tqIdcIdlRaw;
   sint32 s32LocalIdlSys_tqIdcIdlSatMin;


   VEMS_vidGET(IdlSys_tqIdcIdlStab, s16LocalIdlSys_tqIdcIdlStab);

   if (IdlSys_bAcvSBPA_C == 0)
   {
      s32LocalIdlSys_tqIdcIdlRaw =
         (sint32)(s16LocalIdlSys_tqIdcIdlStab + IdlSys_tqIdlCorPID);
      s32LocalIdlSys_tqIdcIdlSatMin =
         (sint32)(s16LocalIdlSys_tqIdcIdlStab + IdlSys_tqIdlCorSatMin);
   }
   else
   {
      VEMS_vidGET(TqSys_tqIdcSBPA, s16LocalTqSys_tqIdcSBPA);
      s32LocalIdlSys_tqIdcIdlRaw =
         (sint32)(s16LocalIdlSys_tqIdcIdlStab + s16LocalTqSys_tqIdcSBPA);
      s32LocalIdlSys_tqIdcIdlSatMin = (sint32)s16LocalIdlSys_tqIdcIdlStab;
   }

   IdlSys_tqIdcIdlRaw =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_tqIdcIdlRaw, -32000, 32000);
   IdlSys_tqIdcIdlSatMin =
      (sint16)MATHSRV_udtCLAMP(s32LocalIdlSys_tqIdcIdlSatMin, -32000, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCalc_regulateur_air                             */
/* !Description :  La correction de couple émise par le régulateur avance est */
/*                 filtrée par un filtre passe-bas dont la constante de temps */
/*                 dépend de son sens de variation.                           */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_014.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 IdlSys_noGear;                                                */
/*  input boolean IdlSys_bIniIdlCtl;                                          */
/*  input sint16 IdlSys_tqIdcIdlSatMin;                                       */
/*  input sint16 IdlSys_tqIdcAirIdlRaw;                                       */
/*  input uint16 IdlSys_tqErrIdlAir_A[8];                                     */
/*  input uint16 IDLCTRL_u16TqErrIdlAir;                                      */
/*  input uint16 IdlSys_tiFilTqIdlAirSpc_M[4][8];                             */
/*  input uint16 IdlSys_tiFilTqIdlAir_M[4][8];                                */
/*  input uint16 TqSys_facTranSpcAirSys;                                      */
/*  input sint16 IdlSys_tqIdcIdlIniAir;                                       */
/*  input uint8 Ext_tiTDC;                                                    */
/*  input uint16 IdlSys_tiFilTqIdlAir_MP;                                     */
/*  input sint32 IDLCTRL_s32TqIdcAirIdlRawFiltMem;                            */
/*  output uint16 IDLCTRL_u16TqErrIdlAir;                                     */
/*  output uint16 IdlSys_tiFilTqIdlAir_MP;                                    */
/*  output sint16 IdlSys_tqIdcAirIdlRaw;                                      */
/*  output sint32 IDLCTRL_s32TqIdcAirIdlRawFiltMem;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCalc_regulateur_air(void)
{
   boolean bLocalIdlSys_bIniIdlCtl;
   uint8   u8LocalIdlSys_noGear;
   uint8   u8LocalExt_tiTDC;
   uint16  u16LocalParaColumn;
   uint16  u16LocalParaLine;
   uint16  u16LocalInterp1;
   uint16  u16LocalInterp2;
   uint16  u16LocalFilterGain;
   uint16  u16LocalTqSys_facTranSpcAirSys;
   uint16  u16LocalDiff;
   sint16  s16LocalIdlSys_tqIdcIdlIniAir;
   sint16  s16LocalIdlSys_tqIdcAirIdlRaw;
   uint32  u32LocalFilterGainDen;
   uint32  u32LocalFilterGainNum;
   uint32  u32LocalMult1;
   uint32  u32LocalMult2;
   uint32  u32LocalSom;
   sint32  s32LocalDiff;


   VEMS_vidGET(IdlSys_noGear, u8LocalIdlSys_noGear);
   VEMS_vidGET(IdlSys_bIniIdlCtl, bLocalIdlSys_bIniIdlCtl);

   /*Production of IdlSys_tiFilTqIdlAir_MP*/
   s32LocalDiff =
      (sint32)(((IdlSys_tqIdcIdlSatMin - IdlSys_tqIdcAirIdlRaw) / 4) + 8000);
   IDLCTRL_u16TqErrIdlAir = (uint16)MATHSRV_udtCLAMP(s32LocalDiff, 0, 16000);

   u8LocalIdlSys_noGear = (uint8)MATHSRV_udtMIN(u8LocalIdlSys_noGear, 3);
   u16LocalParaLine = (uint16)(u8LocalIdlSys_noGear * 256);

   u16LocalParaColumn = MATHSRV_u16CalcParaIncAryU16(IdlSys_tqErrIdlAir_A,
                                                     IDLCTRL_u16TqErrIdlAir,
                                                     8);
   /*in1*/
   u16LocalInterp1 = MATHSRV_u16Interp2d(&IdlSys_tiFilTqIdlAirSpc_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);
   /*in2*/
   u16LocalInterp2 = MATHSRV_u16Interp2d(&IdlSys_tiFilTqIdlAir_M[0][0],
                                        u16LocalParaLine,
                                        u16LocalParaColumn,
                                        8);

   /*Barycentre*/
   VEMS_vidGET(TqSys_facTranSpcAirSys, u16LocalTqSys_facTranSpcAirSys);
   u16LocalTqSys_facTranSpcAirSys =
      (uint16)MATHSRV_udtMIN(u16LocalTqSys_facTranSpcAirSys, 1024);

   u16LocalDiff = (uint16)(1024 - u16LocalTqSys_facTranSpcAirSys);
   u32LocalMult1 = (uint32)(u16LocalInterp1 * u16LocalTqSys_facTranSpcAirSys);
   u32LocalMult2 = (uint32)(u16LocalInterp2 * u16LocalDiff);
   u32LocalSom = ((u32LocalMult1 + u32LocalMult2 + 128) / 256);
   IdlSys_tiFilTqIdlAir_MP = (uint16)MATHSRV_udtMIN(u32LocalSom, 7680);

   /*Production of DLowPassFilter_TypeT output*/
   if (bLocalIdlSys_bIniIdlCtl != 0)
   {
      /*Initialization*/
      VEMS_vidGET(IdlSys_tqIdcIdlIniAir, s16LocalIdlSys_tqIdcIdlIniAir);
      IdlSys_tqIdcAirIdlRaw =
         (sint16)MATHSRV_udtCLAMP(s16LocalIdlSys_tqIdcIdlIniAir, -32000, 32000);
      IDLCTRL_s32TqIdcAirIdlRawFiltMem =
         (sint32)(IdlSys_tqIdcAirIdlRaw * 65536);
   }
   else
   {
      VEMS_vidGET(Ext_tiTDC, u8LocalExt_tiTDC);
      u32LocalFilterGainDen =
         (uint32)((64 * u8LocalExt_tiTDC) + (125 * IdlSys_tiFilTqIdlAir_MP));

      if (  (u32LocalFilterGainDen != 0)
         && (IdlSys_tiFilTqIdlAir_MP != 0))
      {
         /*Filter Gain < 100%*/
         u32LocalFilterGainNum = (uint32)(4194304 * u8LocalExt_tiTDC);
         u16LocalFilterGain =
            (uint16)(u32LocalFilterGainNum / u32LocalFilterGainDen);

         s16LocalIdlSys_tqIdcAirIdlRaw =
            MATHSRV_s16FirstOrderFilterGu16(u16LocalFilterGain,
                                           &IDLCTRL_s32TqIdcAirIdlRawFiltMem,
                                           IdlSys_tqIdcIdlSatMin);
         IdlSys_tqIdcAirIdlRaw =
            (sint16)MATHSRV_udtCLAMP(s16LocalIdlSys_tqIdcAirIdlRaw,
                                     -32000,
                                     32000);

      }
      else
      {
         /*Filter Gain = 100%*/
         IdlSys_tqIdcAirIdlRaw =
            (sint16)MATHSRV_udtCLAMP(IdlSys_tqIdcIdlSatMin, -32000, 32000);
         IDLCTRL_s32TqIdcAirIdlRawFiltMem =
           (sint32)(IdlSys_tqIdcAirIdlRaw * 65536);
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  IDLCTRL_vidCoord_couples_ralenti                           */
/* !Description :  Lorsque le régulateur de ralenti est actif, les couples    */
/*                 calculés par le régulateur de ralenti sont appliqués en    */
/*                 sortie de la fonction. Sinon, les couples basculent sur    */
/*                 leurs valeurs de repli (couple nul).                       */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_08597_015.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean IdlSys_bAcvIdlCtl;                                          */
/*  input sint16 IdlSys_tqIdcIdlRaw;                                          */
/*  input boolean TqSys_bTypFu;                                               */
/*  input sint16 IdlSys_tqIdcAirIdlRaw;                                       */
/*  output sint16 IdlSys_tqIdcIdlNotSat;                                      */
/*  output sint16 IdlSys_tqIdcIdl;                                            */
/*  output sint16 IdlSys_tqIdcAirIdl;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void IDLCTRL_vidCoord_couples_ralenti(void)
{
   boolean bLocalIdlSys_bAcvIdlCtl;
   boolean bLocalTqSys_bTypFu;
   sint16  s16LocalIdlSys_tqIdcIdlNotSat;
   sint16  s16LocalIdlSys_tqIdcIdl;
   sint16  s16LocalIdlSys_tqIdcAirIdl;


   VEMS_vidGET(IdlSys_bAcvIdlCtl, bLocalIdlSys_bAcvIdlCtl);
   if (bLocalIdlSys_bAcvIdlCtl == 0)
   {
      VEMS_vidSET(IdlSys_tqIdcIdlNotSat, 0);
      VEMS_vidSET(IdlSys_tqIdcIdl, 0);
      VEMS_vidSET(IdlSys_tqIdcAirIdl, 0);
   }
   else
   {
      s16LocalIdlSys_tqIdcIdlNotSat =
         (sint16)MATHSRV_udtCLAMP(IdlSys_tqIdcIdlRaw, -32000, 32000);
      VEMS_vidSET(IdlSys_tqIdcIdlNotSat, s16LocalIdlSys_tqIdcIdlNotSat);

      s16LocalIdlSys_tqIdcIdl =
         (sint16)MATHSRV_udtCLAMP(IdlSys_tqIdcIdlRaw, 0, 32000);
      VEMS_vidSET(IdlSys_tqIdcIdl, s16LocalIdlSys_tqIdcIdl);

      VEMS_vidGET(TqSys_bTypFu, bLocalTqSys_bTypFu);
      if (bLocalTqSys_bTypFu == 0)
      {
         VEMS_vidSET(IdlSys_tqIdcAirIdl, 0);
      }
      else
      {
         s16LocalIdlSys_tqIdcAirIdl =
            (sint16)MATHSRV_udtCLAMP(IdlSys_tqIdcAirIdlRaw, 0, 32000);
         VEMS_vidSET(IdlSys_tqIdcAirIdl, s16LocalIdlSys_tqIdcAirIdl);
      }
   }
}

/*------------------------------ end of file ---------------------------------*/