/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXMNG                                             */
/* !Description     : VLVACTEXMNG Component                                   */
/*                                                                            */
/* !Module          : VLVACTEXMNG                                             */
/* !Description     : MANAGER DE LA FONCTION VVT ECHAPPEMENT                  */
/*                                                                            */
/* !File            : VLVACTEXMNG_FCT2.C                                      */
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
/*   1 / VLVACTEXMNG_vidUnlckStr                                              */
/*   2 / VLVACTEXMNG_vidUnlockStrategy                                        */
/*                                                                            */
/* !Reference   : V02 NT 08 07819 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#068177                                         */
/* !OtherRefs   : VEMS V02 ECU#068136                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXMNG/VLVACTEXMNG$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   17 Feb 2014 $*/
/* $Author::   etsasson                               $$Date::   17 Feb 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXMNG.h"
#include "VLVACTEXMNG_L.h"
#include "VLVACTEXMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidUnlckStr                                    */
/* !Description :  Stratégie de désengagement du pion de blocage VVT          */
/*                 échappement.                                               */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  I.JEMAI                                                    */
/* !Trace_To    :  VEMS_R_08_07819_012.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXMNG_vidUnlockStrategy();                         */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint16 VlvAct_agCmExPosnEstim;                                      */
/*  input uint16 Vxx_vvtc_ex_angl_sp;                                         */
/*  input uint16 VlvAct_tOilExUnlckStr_T[5];                                  */
/*  input uint8 VlvAct_tiExUnlckIni_M[5];                                     */
/*  input uint8 VlvAct_tiExUnlckSlop_M[5];                                    */
/*  input uint8 VlvAct_noExUnlckStrThd_M[5];                                  */
/*  input uint8 VlvAct_tiExUnlckStab_M[5];                                    */
/*  input uint16 VlvAct_ExUnlckCmdIni_M[5];                                   */
/*  input uint16 VlvAct_ExUnlckSlop1_M[5];                                    */
/*  input uint16 VlvAct_ExUnlckSlop2_M[5];                                    */
/*  input uint16 VlvAct_ExUnlckCmdStab_M[5];                                  */
/*  input boolean VlvAct_bExMngUnlckStEna_C;                                  */
/*  input sint16 VlvAct_tOilExUnlckThdHi_C;                                   */
/*  input sint16 VlvAct_tOilExUnlckThdHiHys_C;                                */
/*  input boolean VLVACTEXMNG_bTOilExUnlckThd;                                */
/*  input uint8 VlvAct_nEngExUnlckThdLo_C;                                    */
/*  input uint8 VlvAct_nEngExUnlckThdLoHys_C;                                 */
/*  input boolean VLVACTEXMNG_bNEngExUnlckThd;                                */
/*  input uint8 VlvAct_agExAcvUnlckPosnThd_C;                                 */
/*  input uint8 VlvAct_agExAcvUnlckPosnThdHys_C;                              */
/*  input boolean VLVACTEXMNG_bAgExAcvUnlckPosnThd;                           */
/*  input uint8 VlvAct_agExAcvSpFuncIntlThd_C;                                */
/*  input uint8 VlvAct_agExAcvSpFuncIntlThdHys_C;                             */
/*  input boolean VLVACTEXMNG_bAgExAcvSpFuncIntThd;                           */
/*  output uint8 VlvAct_tiExUnlckIni;                                         */
/*  output uint8 VlvAct_tiExUnlckSlop;                                        */
/*  output uint8 VlvAct_noExUnlckStrThd;                                      */
/*  output uint8 VlvAct_tiExUnlckStab;                                        */
/*  output uint16 VlvAct_ExUnlckCmdIni;                                       */
/*  output uint16 VlvAct_ExUnlckSlop1;                                        */
/*  output uint16 VlvAct_ExUnlckSlop2;                                        */
/*  output uint16 VlvAct_ExUnlckCmdStab;                                      */
/*  output boolean VlvAct_bExUnlckStrEndIdc;                                  */
/*  output boolean VLVACTEXMNG_bTOilExUnlckThd;                               */
/*  output boolean VLVACTEXMNG_bAgExAcvSpFuncIntThd;                          */
/*  output boolean VlvAct_bExMngUnlckStEna;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidUnlckStr(void)
{
   uint16   u16SiteInterpolation;
   uint16   u16LocalCalcPara;
   uint16   u16LocalInterp;
   uint16   u16LocalExt_nEng;
   uint16   u16LocalnEngExUnlckThdlow;
   uint16   u16LocalnEngExUnlckThdHi;
   uint16   u16LocalExPosnEstim;
   uint16   u16LocalExAvUlckPThdHi;
   uint16   u16LocalVxxvvtcexanglsp;
   sint16   s16LocalEng_tOilEstim;
   sint16   s16LocalAgExAcvSpFuncIntThdLow;
   sint32   s32LocaltOilExUnlckThdHi;
   sint32   s32LocaltOilExUnlckThdlow;


   VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   VEMS_vidGET(VlvAct_agCmExPosnEstim, u16LocalExPosnEstim);
   VEMS_vidGET(Vxx_vvtc_ex_angl_sp, u16LocalVxxvvtcexanglsp);

   s16LocalEng_tOilEstim = (sint16)MATHSRV_udtCLAMP(s16LocalEng_tOilEstim,
                                                    -200,
                                                    800);
   u16SiteInterpolation = (uint16)(s16LocalEng_tOilEstim + 200);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU16(VlvAct_tOilExUnlckStr_T,
                                                   u16SiteInterpolation,
                                                   5);

   VlvAct_tiExUnlckIni = MATHSRV_u8Interp1d(VlvAct_tiExUnlckIni_M,
                                            u16LocalCalcPara);
   VlvAct_tiExUnlckSlop = MATHSRV_u8Interp1d(VlvAct_tiExUnlckSlop_M,
                                             u16LocalCalcPara);
   VlvAct_noExUnlckStrThd = MATHSRV_u8Interp1d(VlvAct_noExUnlckStrThd_M,
                                               u16LocalCalcPara);
   VlvAct_tiExUnlckStab = MATHSRV_u8Interp1d(VlvAct_tiExUnlckStab_M,
                                             u16LocalCalcPara);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_ExUnlckCmdIni_M,
                                        u16LocalCalcPara);
   VlvAct_ExUnlckCmdIni = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_ExUnlckSlop1_M,
                                        u16LocalCalcPara);
   VlvAct_ExUnlckSlop1 = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_ExUnlckSlop2_M,
                                        u16LocalCalcPara);
   VlvAct_ExUnlckSlop2 = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   u16LocalInterp = MATHSRV_u16Interp1d(VlvAct_ExUnlckCmdStab_M,
                                        u16LocalCalcPara);
   VlvAct_ExUnlckCmdStab = (uint16)MATHSRV_udtMIN(u16LocalInterp , 1023);

   VLVACTEXMNG_vidUnlockStrategy();

   if (VlvAct_bExMngUnlckStEna_C == 0)
   {
      VlvAct_bExUnlckStrEndIdc = 1;
   }

   s32LocaltOilExUnlckThdlow = (sint32)(4 * ( VlvAct_tOilExUnlckThdHi_C
                                            - VlvAct_tOilExUnlckThdHiHys_C));
   s32LocaltOilExUnlckThdHi = (sint32)(4 * VlvAct_tOilExUnlckThdHi_C);

   if (VLVACTEXMNG_bTOilExUnlckThd == 0)
   {
      if (s16LocalEng_tOilEstim > s32LocaltOilExUnlckThdHi)
      {
         VLVACTEXMNG_bTOilExUnlckThd = 1;
      }
      else
      {
         VLVACTEXMNG_bTOilExUnlckThd = 0;
      }
   }
   else
   {
      if (s16LocalEng_tOilEstim <= s32LocaltOilExUnlckThdlow)
      {
         VLVACTEXMNG_bTOilExUnlckThd = 0;
      }
      else
      {
         VLVACTEXMNG_bTOilExUnlckThd = 1;
      }
   }

   u16LocalnEngExUnlckThdHi = (uint16)( ( VlvAct_nEngExUnlckThdLo_C
                                        + VlvAct_nEngExUnlckThdLoHys_C)
                                      * 32);
   u16LocalnEngExUnlckThdlow = (uint16)(32 * VlvAct_nEngExUnlckThdLo_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalExt_nEng,
                                u16LocalnEngExUnlckThdlow,
                                u16LocalnEngExUnlckThdHi,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bNEngExUnlckThd);

   u16LocalExAvUlckPThdHi = (uint16)( VlvAct_agExAcvUnlckPosnThd_C
                                    + VlvAct_agExAcvUnlckPosnThdHys_C);
   MATHSRV_vidSchmittTriggerU16(u16LocalExPosnEstim,
                                (uint16)VlvAct_agExAcvUnlckPosnThd_C,
                                u16LocalExAvUlckPThdHi,
                                MATHSRV_FALLING_SCHMITT_TRIGGER,
                                &VLVACTEXMNG_bAgExAcvUnlckPosnThd);

   s16LocalAgExAcvSpFuncIntThdLow = (sint16)( VlvAct_agExAcvSpFuncIntlThd_C
                                            - VlvAct_agExAcvSpFuncIntlThdHys_C);
   if (VLVACTEXMNG_bAgExAcvSpFuncIntThd == 0)
   {
      if (u16LocalVxxvvtcexanglsp > VlvAct_agExAcvSpFuncIntlThd_C)
      {
         VLVACTEXMNG_bAgExAcvSpFuncIntThd = 1;
      }
      else
      {
         VLVACTEXMNG_bAgExAcvSpFuncIntThd = 0;
      }
   }
   else
   {
      if (u16LocalVxxvvtcexanglsp <= s16LocalAgExAcvSpFuncIntThdLow)
      {
         VLVACTEXMNG_bAgExAcvSpFuncIntThd = 0;
      }
      else
      {
         VLVACTEXMNG_bAgExAcvSpFuncIntThd = 1;
      }
   }

   if (  (VLVACTEXMNG_bTOilExUnlckThd != 0)
      && (VLVACTEXMNG_bNEngExUnlckThd != 0)
      && (VLVACTEXMNG_bAgExAcvUnlckPosnThd != 0)
      && (VLVACTEXMNG_bAgExAcvSpFuncIntThd != 0)
      && (VlvAct_bExMngUnlckStEna_C != 0))
   {
      VlvAct_bExMngUnlckStEna = 1;
   }
   else
   {
      VlvAct_bExMngUnlckStEna = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXMNG_vidUnlockStrategy                              */
/* !Description :  Automate de la stratégie de désengagement du pion de       */
/*                 blocage VVT échappement.                                   */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  I.JEMAI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input st46 VlvAct_ExUnlckStrSt;                                           */
/*  input boolean VlvAct_bExUnlckEna;                                         */
/*  input uint16 VlvAct_ExUnlckCmdIni;                                        */
/*  input uint8 VlvAct_tiExUnlck;                                             */
/*  input uint8 VlvAct_tiExUnlckIni;                                          */
/*  input uint16 VlvAct_ExUnlckSlop1;                                         */
/*  input uint8 VlvAct_tiExUnlckSlop;                                         */
/*  input uint16 VlvAct_ExUnlckCmdStab;                                       */
/*  input uint8 VlvAct_noExUnlckStr;                                          */
/*  input uint16 VlvAct_ExUnlckSlop2;                                         */
/*  input uint8 VlvAct_noExUnlckStrThd;                                       */
/*  input uint8 VlvAct_tiExUnlckStab;                                         */
/*  output boolean VlvAct_bExUnlckStrEndIdc;                                  */
/*  output uint8 VlvAct_noExUnlckStr;                                         */
/*  output st46 VlvAct_ExUnlckStrSt;                                          */
/*  output uint16 VlvAct_ExUnlckCmd;                                          */
/*  output uint8 VlvAct_tiExUnlck;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXMNG_vidUnlockStrategy(void)
{
   sint16  s16LocalMult2;
   sint16  s16LocalDiv;
   sint32  s32LocalMult;
   sint32  s32LocalOut;


   switch (VlvAct_ExUnlckStrSt)
   {
      /*Warning QAC: The QAC indentation check of a switch-cases bloc is not
      those used by VEMS presenting rules.*/
      case VLVACT_EX_UNLOCK_IDLE:
         if (VlvAct_bExUnlckEna != 0)
         {
            VlvAct_bExUnlckStrEndIdc = 0;
            VlvAct_noExUnlckStr = 0;
            VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_INIT;
            VlvAct_ExUnlckCmd =
                  (uint16)MATHSRV_udtMIN(VlvAct_ExUnlckCmdIni, 1023);
            VlvAct_tiExUnlck = 0;
         }
         break;

      case VLVACT_EX_UNLOCK_INIT:
         if (VlvAct_bExUnlckEna == 0)
         {
            VlvAct_noExUnlckStr = 0;
            VlvAct_bExUnlckStrEndIdc = 1;
            VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
         }
         else
         {
            if (VlvAct_tiExUnlck >= VlvAct_tiExUnlckIni)
            {
               VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_SLOPE;
               VlvAct_ExUnlckCmd =
                     (uint16)MATHSRV_udtMIN(VlvAct_ExUnlckSlop1 , 1023);
            }
            if (VlvAct_tiExUnlck < 255)
            {
               VlvAct_tiExUnlck = (uint8)(VlvAct_tiExUnlck + 1);
            }
         }
         break;

      case VLVACT_EX_UNLOCK_SLOPE:
         if (VlvAct_bExUnlckEna == 0)
         {
            VlvAct_noExUnlckStr = 0;
            VlvAct_bExUnlckStrEndIdc = 1;
            VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
         }
         else
         {
            if (VlvAct_tiExUnlck >= VlvAct_tiExUnlckSlop)
            {
               if (VlvAct_tiExUnlck < 255)
               {
                  VlvAct_tiExUnlck = (uint8)(VlvAct_tiExUnlck + 1);
               }
               VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_STAB;
               VlvAct_ExUnlckCmd =
                     (uint16)MATHSRV_udtMIN(VlvAct_ExUnlckCmdStab , 1023);
               if (VlvAct_noExUnlckStr < 255)
               {
                  VlvAct_noExUnlckStr = (uint8)(VlvAct_noExUnlckStr + 1);
               }
            }
            else
            {
               VlvAct_tiExUnlck = (uint8)(VlvAct_tiExUnlck + 1);
               s32LocalMult = (sint32)( VlvAct_ExUnlckSlop2
                                      - VlvAct_ExUnlckSlop1);
               s16LocalMult2 = (sint16)(VlvAct_tiExUnlck - VlvAct_tiExUnlckIni);
               s16LocalDiv = (sint16)( VlvAct_tiExUnlckSlop
                                     - VlvAct_tiExUnlckIni);
               s32LocalMult = s32LocalMult * s16LocalMult2;
               if (s16LocalDiv != 0)
               {
                  s32LocalOut = ( (s32LocalMult / s16LocalDiv)
                                + VlvAct_ExUnlckSlop1);
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
               VlvAct_ExUnlckCmd = (uint16)MATHSRV_udtCLAMP(s32LocalOut,
                                                            0,
                                                            1023);
            }
         }
         break;

      case VLVACT_EX_UNLOCK_STAB:
         if (VlvAct_bExUnlckEna == 0)
         {
            VlvAct_noExUnlckStr = 0;
            VlvAct_bExUnlckStrEndIdc = 1;
            VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
         }
         else
         {
            if (  (VlvAct_noExUnlckStr >= VlvAct_noExUnlckStrThd)
               && (VlvAct_tiExUnlck >= VlvAct_tiExUnlckStab))

            {
               VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_END;
               VlvAct_bExUnlckStrEndIdc = 1;
            }
            else
            {
               if (  (VlvAct_noExUnlckStr < VlvAct_noExUnlckStrThd)
                  && (VlvAct_tiExUnlck >= VlvAct_tiExUnlckStab))
               {
                  VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_INIT;
                  VlvAct_ExUnlckCmd =
                        (uint16)MATHSRV_udtMIN(VlvAct_ExUnlckCmdIni , 1023);
                  VlvAct_tiExUnlck = 0;
               }
               else
               {
                  VlvAct_tiExUnlck = (uint8)(VlvAct_tiExUnlck + 1);
               }
            }
         }
         break;

      case VLVACT_EX_UNLOCK_END:
         VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         VlvAct_ExUnlckStrSt = VLVACT_EX_UNLOCK_IDLE;
         break;
   }
}
/*------------------------------- end of file --------------------------------*/