/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINMNG                                             */
/* !Description     : VLVACTINMNG component.                                  */
/*                                                                            */
/* !Module          : VLVACTINMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ADMISSION .                  */
/*                                                                            */
/* !File            : VLVACTINMNG_FCT2.C                                      */
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
/*   1 / VLVACTINMNG_vidUnlckStr                                              */
/*   2 / VLVACTINMNG_vidUnlockStrategy                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 07174 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068180                                         */
/* !OtherRefs   : VEMS V02 ECU#068137                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINMNG/VLVACTINMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTINMNG.h"
#include "VLVACTINMNG_L.h"
#include "VLVACTINMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidUnlckStr                                    */
/* !Description :  Automate de la stratégie de désengagement du pion de       */
/*                 blocage VVT admission                                      */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07174_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINMNG_vidUnlockStrategy();                         */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_agCmInPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_in_angl_sp;                                         */
/*  input uint16 VlvAct_tOilInUnlckStr_T[5];                                  */
/*  input uint8 VlvAct_tiInUnlckIni_M[5];                                     */
/*  input uint8 VlvAct_tiInUnlckSlop_M[5];                                    */
/*  input uint8 VlvAct_noInUnlckStrThd_M[5];                                  */
/*  input uint8 VlvAct_tiInUnlckStab_M[5];                                    */
/*  input uint16 VlvAct_InUnlckCmdIni_M[5];                                   */
/*  input uint16 VlvAct_InUnlckSlop1_M[5];                                    */
/*  input uint16 VlvAct_InUnlckSlop2_M[5];                                    */
/*  input uint16 VlvAct_InUnlckCmdStab_M[5];                                  */
/*  input boolean VlvAct_bInMngUnlckStEna_C;                                  */
/*  input sint16 VlvAct_tOilInUnlckThdHi_C;                                   */
/*  input sint16 VlvAct_tOilInUnlckThdHiHys_C;                                */
/*  input boolean VLVACTINMNG_bTOilInUnlckThd;                                */
/*  input uint8 VlvAct_nEngInUnlckThdLo_C;                                    */
/*  input uint8 VlvAct_nEngInUnlckThdLoHys_C;                                 */
/*  input boolean VLVACTINMNG_bNEngInUnlckThd;                                */
/*  input uint8 VlvAct_agInAcvUnlckPosnThd_C;                                 */
/*  input uint8 VlvAct_agInAcvUnlckPosnThdHys_C;                              */
/*  input boolean VLVACTINMNG_bAgInAcvUnlckPosnThd;                           */
/*  input uint8 VlvAct_agInAcvSpFuncIntlThd_C;                                */
/*  input uint8 VlvAct_agInAcvSpFuncIntlThdHys_C;                             */
/*  input boolean VLVACTINMNG_bagInAcvSpFuncIntThd;                           */
/*  output uint8 VlvAct_tiInUnlckIni;                                         */
/*  output uint8 VlvAct_tiInUnlckSlop;                                        */
/*  output uint8 VlvAct_noInUnlckStrThd;                                      */
/*  output uint8 VlvAct_tiInUnlckStab;                                        */
/*  output uint16 VlvAct_InUnlckCmdIni;                                       */
/*  output uint16 VlvAct_InUnlckSlop1;                                        */
/*  output uint16 VlvAct_InUnlckSlop2;                                        */
/*  output uint16 VlvAct_InUnlckCmdStab;                                      */
/*  output boolean VlvAct_bInInUnlckStrEndIdc;                                */
/*  output boolean VLVACTINMNG_bTOilInUnlckThd;                               */
/*  output boolean VLVACTINMNG_bagInAcvSpFuncIntThd;                          */
/*  output boolean VlvAct_bInMngUnlckStEna;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidUnlckStr(void)
{
   uint16   u16SiteInterpolation;
   uint16   u16LocalCalcPara;
   uint16   u16LocalInterp;
   uint16   u16LocalAgCmInPosnEstim;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalnEngInUnlckThdLo;
   uint16   u16LocalnEngInUnlckThdHi;
   uint16   u16LocalagInAcvUnlckPosnThdHi;
   uint16   u16LocalVxxvvtcinanglsp;
   sint16   s16LocalEng_tOilEstim;
   sint16   s16LocalagInAcvSpFuncIntlThdLow;
   sint32   s32LocalTOilInUnlckThdLow;
   sint32   s32LocalTOilInUnlckThdHi;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(VlvAct_agCmInPosnEstim, u16LocalAgCmInPosnEstim);
   VEMS_vidGET(Vxx_vvtc_in_angl_sp, u16LocalVxxvvtcinanglsp);
   s16LocalEng_tOilEstim = (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim,
                                                    -200,
                                                    800);
   u16SiteInterpolation = (uint16)(s16LocalEng_tOilEstim + 200);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(VlvAct_tOilInUnlckStr_T,
                                                   u16SiteInterpolation,
                                                   5);

   VlvAct_tiInUnlckIni = MATHSRV_u8Interp1d(VlvAct_tiInUnlckIni_M,
                                            u16LocalCalcPara);
   VlvAct_tiInUnlckSlop = MATHSRV_u8Interp1d(VlvAct_tiInUnlckSlop_M,
                                             u16LocalCalcPara);
   VlvAct_noInUnlckStrThd = MATHSRV_u8Interp1d(VlvAct_noInUnlckStrThd_M,
                                               u16LocalCalcPara);
   VlvAct_tiInUnlckStab = MATHSRV_u8Interp1d(VlvAct_tiInUnlckStab_M,
                                             u16LocalCalcPara);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_InUnlckCmdIni_M,
                                        u16LocalCalcPara);
   VlvAct_InUnlckCmdIni = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_InUnlckSlop1_M,
                                        u16LocalCalcPara);
   VlvAct_InUnlckSlop1 = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_InUnlckSlop2_M,
                                        u16LocalCalcPara);
   VlvAct_InUnlckSlop2 = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_InUnlckCmdStab_M,
                                        u16LocalCalcPara);
   VlvAct_InUnlckCmdStab = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   VLVACTINMNG_vidUnlockStrategy();

   if (VlvAct_bInMngUnlckStEna_C == 0)
   {
      VlvAct_bInInUnlckStrEndIdc = 1;
   }

   s32LocalTOilInUnlckThdLow = (sint32)( 4 * ( VlvAct_tOilInUnlckThdHi_C
                                             - VlvAct_tOilInUnlckThdHiHys_C));
   s32LocalTOilInUnlckThdHi = (sint32)(4 * VlvAct_tOilInUnlckThdHi_C);

   if (VLVACTINMNG_bTOilInUnlckThd == 0)
   {
      if (s16LocalEng_tOilEstim > s32LocalTOilInUnlckThdHi)
      {
         VLVACTINMNG_bTOilInUnlckThd = 1;
      }
      else
      {
         VLVACTINMNG_bTOilInUnlckThd = 0;
      }
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocalTOilInUnlckThdLow)
      {
         VLVACTINMNG_bTOilInUnlckThd = 0;
      }
      else
      {
         VLVACTINMNG_bTOilInUnlckThd = 1;
      }
   }

   u16LocalnEngInUnlckThdHi = (uint16)( ( VlvAct_nEngInUnlckThdLo_C
                                        + VlvAct_nEngInUnlckThdLoHys_C)
                                      * 32);
   u16LocalnEngInUnlckThdHi = (uint16)MATHSRV_udtMIN(u16LocalnEngInUnlckThdHi,
                                                     8160);
   u16LocalnEngInUnlckThdLo = (uint16)(32 * VlvAct_nEngInUnlckThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalnEngInUnlckThdLo,
                                u16LocalnEngInUnlckThdHi,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bNEngInUnlckThd);

   u16LocalagInAcvUnlckPosnThdHi = (uint16)( VlvAct_agInAcvUnlckPosnThd_C
                                           + VlvAct_agInAcvUnlckPosnThdHys_C);

   MATHSRV_vidSchmittTriggerU16(u16LocalAgCmInPosnEstim,
                                (uint16)VlvAct_agInAcvUnlckPosnThd_C,
                                u16LocalagInAcvUnlckPosnThdHi,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTINMNG_bAgInAcvUnlckPosnThd);

   s16LocalagInAcvSpFuncIntlThdLow =
      (sint16)( VlvAct_agInAcvSpFuncIntlThd_C
              - VlvAct_agInAcvSpFuncIntlThdHys_C);

   if (VLVACTINMNG_bagInAcvSpFuncIntThd == 0)
   {
      if (u16LocalVxxvvtcinanglsp > VlvAct_agInAcvSpFuncIntlThd_C)
      {
         VLVACTINMNG_bagInAcvSpFuncIntThd = 1;
      }
      else
      {
         VLVACTINMNG_bagInAcvSpFuncIntThd = 0;
      }
   }
   else
   {
      if (u16LocalVxxvvtcinanglsp <= s16LocalagInAcvSpFuncIntlThdLow)
      {
         VLVACTINMNG_bagInAcvSpFuncIntThd = 0;
      }
      else
      {
         VLVACTINMNG_bagInAcvSpFuncIntThd = 1;
      }
   }

   if (  (VlvAct_bInMngUnlckStEna_C != 0)
      && (VLVACTINMNG_bTOilInUnlckThd != 0)
      && (VLVACTINMNG_bNEngInUnlckThd != 0)
      && (VLVACTINMNG_bAgInAcvUnlckPosnThd != 0)
      && (VLVACTINMNG_bagInAcvSpFuncIntThd != 0))
   {
      VlvAct_bInMngUnlckStEna = 1;
   }
   else
   {
      VlvAct_bInMngUnlckStEna = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINMNG_vidUnlockStrategy                              */
/* !Description :  Stratégie de désengagement du pion de blocage VVT admission*/
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st43 VlvAct_InUnlckStrSt;                                           */
/*  input boolean VlvAct_bInUnlckEna;                                         */
/*  input uint16 VlvAct_InUnlckCmdIni;                                        */
/*  input uint8 VlvAct_tiInUnlck;                                             */
/*  input uint8 VlvAct_tiInUnlckIni;                                          */
/*  input uint16 VlvAct_InUnlckSlop1;                                         */
/*  input uint8 VlvAct_tiInUnlckSlop;                                         */
/*  input uint16 VlvAct_InUnlckCmdStab;                                       */
/*  input uint8 VlvAct_noInUnlckStr;                                          */
/*  input uint16 VlvAct_InUnlckSlop2;                                         */
/*  input uint8 VlvAct_noInUnlckStrThd;                                       */
/*  input uint8 VlvAct_tiInUnlckStab;                                         */
/*  output boolean VlvAct_bInInUnlckStrEndIdc;                                */
/*  output uint8 VlvAct_noInUnlckStr;                                         */
/*  output st43 VlvAct_InUnlckStrSt;                                          */
/*  output uint16 VlvAct_InUnlckCmd;                                          */
/*  output uint8 VlvAct_tiInUnlck;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINMNG_vidUnlockStrategy(void)
{
   sint16  s16LocalMult2;
   sint16  s16LocalDiv;
   sint32  s32LocalMult;
   sint32  s32LocalOut;


   switch (VlvAct_InUnlckStrSt)
   {
      /*Warning QAC: The QAC indentation check of a switch-cases bloc is not
      those used by VEMS presenting rules.*/
      case VLVACT_IN_UNLOCK_IDLE:
         if (VlvAct_bInUnlckEna != 0)
         {
            VlvAct_bInInUnlckStrEndIdc = 0;
            VlvAct_noInUnlckStr = 0;
            VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_INIT;
            VlvAct_InUnlckCmd =
                  (uint16)MATHSRV_udtMIN(VlvAct_InUnlckCmdIni, 1023);
            VlvAct_tiInUnlck = 0;
         }
         break;

      case VLVACT_IN_UNLOCK_INIT:
         if (VlvAct_bInUnlckEna == 0)
         {
            VlvAct_noInUnlckStr = 0;
            VlvAct_bInInUnlckStrEndIdc = 1;
            VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
         }
         else
         {
            if (VlvAct_tiInUnlck >= VlvAct_tiInUnlckIni)
            {
               VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_SLOPE;
               VlvAct_InUnlckCmd =
                     (uint16)MATHSRV_udtMIN(VlvAct_InUnlckSlop1 , 1023);
            }
            if (VlvAct_tiInUnlck < 255)
            {
               VlvAct_tiInUnlck = (uint8)(VlvAct_tiInUnlck + 1);
            }
         }
         break;

      case VLVACT_IN_UNLOCK_SLOPE:
         if (VlvAct_bInUnlckEna == 0)
         {
            VlvAct_noInUnlckStr = 0;
            VlvAct_bInInUnlckStrEndIdc = 1;
            VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
         }
         else
         {
            if (VlvAct_tiInUnlck >= VlvAct_tiInUnlckSlop)
            {
               if (VlvAct_tiInUnlck < 255)
               {
                  VlvAct_tiInUnlck = (uint8)(VlvAct_tiInUnlck + 1);
               }
               VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_STAB;
               VlvAct_InUnlckCmd =
                     (uint16)MATHSRV_udtMIN(VlvAct_InUnlckCmdStab , 1023);
               if (VlvAct_noInUnlckStr < 255)
               {
                  VlvAct_noInUnlckStr = (uint8)(VlvAct_noInUnlckStr + 1);
               }
            }
            else
            {
               VlvAct_tiInUnlck = (uint8)(VlvAct_tiInUnlck + 1);
               s32LocalMult = (sint32)( VlvAct_InUnlckSlop2
                                      - VlvAct_InUnlckSlop1);
               s16LocalMult2 = (sint16)(VlvAct_tiInUnlck - VlvAct_tiInUnlckIni);
               s16LocalDiv = (sint16)( VlvAct_tiInUnlckSlop
                                     - VlvAct_tiInUnlckIni);
               s32LocalMult = s32LocalMult * s16LocalMult2;
               if (s16LocalDiv != 0)
               {
                  s32LocalOut = ( (s32LocalMult / s16LocalDiv)
                                + VlvAct_InUnlckSlop1);
               }
               else
               {
                  if(s32LocalMult < 0)
                  {
                     s32LocalOut = 0;
                  }
                  else
                  {
                     s32LocalOut = 1023;
                  }
               }
               VlvAct_InUnlckCmd = (uint16)MATHSRV_udtCLAMP(s32LocalOut,
                                                            0,
                                                            1023);
            }
         }
         break;

      case VLVACT_IN_UNLOCK_STAB:
         if (VlvAct_bInUnlckEna == 0)
         {
            VlvAct_noInUnlckStr = 0;
            VlvAct_bInInUnlckStrEndIdc = 1;
            VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
         }
         else
         {
            if (  (VlvAct_noInUnlckStr >= VlvAct_noInUnlckStrThd)
               && (VlvAct_tiInUnlck >= VlvAct_tiInUnlckStab))

            {
               VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_END;
               VlvAct_bInInUnlckStrEndIdc = 1;
            }
            else
            {
               if (  (VlvAct_noInUnlckStr < VlvAct_noInUnlckStrThd)
                  && (VlvAct_tiInUnlck >= VlvAct_tiInUnlckStab))
               {
                  VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_INIT;
                  VlvAct_InUnlckCmd =
                        (uint16)MATHSRV_udtMIN(VlvAct_InUnlckCmdIni , 1023);
                  VlvAct_tiInUnlck = 0;
               }
               else
               {
                  VlvAct_tiInUnlck = (uint8)(VlvAct_tiInUnlck + 1);
               }
            }
         }
         break;

      case VLVACT_IN_UNLOCK_END:
         VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VlvAct_InUnlckStrSt = VLVACT_IN_UNLOCK_IDLE;
         break;
   }
}
/*------------------------------- end of file --------------------------------*/