/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFDFTLRN                                              */
/* !Description     : MISFDFTLRN component.                                   */
/*                                                                            */
/* !Module          : MISFDFTLRN                                              */
/* !Description     : Apprentissage des défauts Misfire.                      */
/*                                                                            */
/* !File            : MISFDFTLRN_FCT2.C                                       */
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
/*   1 / MISFDFTLRN_vidSaveLrn                                                */
/*   2 / MISFDFTLRN_vidCalcWinApp                                             */
/*   3 / MISFDFTLRN_vidCalcLongWinApp                                         */
/*   4 / MISFDFTLRN_vidCalcTDCWinApp                                          */
/*   5 / MISFDFTLRN_vidCalcExpWinApp                                          */
/*   6 / MISFDFTLRN_vidCalcBdcWinApp                                          */
/*   7 / MISFDFTLRN_vidCalcIndWinApp                                          */
/*   8 / MISFDFTLRN_vidCalcLrnInit                                            */
/*   9 / MISFDFTLRN_vidCalcLrn                                                */
/*   10 / MISFDFTLRN_vidLongWinVar                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5069555 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#068760                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFDFTLRN/MISFDFTLRN_FCT2.C_$*/
/* $Revision::   1.16     $$Author::   achebino       $$Date::   06 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   06 Jul 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "MISFDFTLRN.h"
#include "MISFDFTLRN_L.h"
#include "MISFDFTLRN_IM.h"
#include "VEMS.h"
#include "SWFAIL.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidSaveLrn                                      */
/* !Description :  Fonction de sauvergade des fenêtres d'apprentissage        */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidIniSaveLrn();                              */
/*  extf argret void MISFDFTLRN_vidWinAdap();                                 */
/*  extf argret void MISFDFTLRN_vidWinAdapSave();                             */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Mf_adap_bkpt_ind_uavn0;                                       */
/*  input st96 Misf_stLrnWin;                                                 */
/*  input st98 Misf_stDftLrn;                                                 */
/*  input boolean Mf_adap_lw_cond_ok_uavb0;                                   */
/*  input boolean Mf_adap_Exp_cond_ok_uavb0;                                  */
/*  input boolean Mf_adap_TDC_cond_ok_uavb0;                                  */
/*  input boolean Mf_adap_Bdc_cond_ok_uavb0;                                  */
/*  input uint8 Mf_adap_lw_sample_count_uavn1[4];                             */
/*  input uint8 Misf_noWinSample_T[4];                                        */
/*  input boolean Misf_bDgoORng_ShrtWinLrn;                                   */
/*  input boolean Misf_bMonRunORng_ShrtWinLrn;                                */
/*  input boolean Misf_bDgoORng_LongWinLrn;                                   */
/*  input boolean Misf_bMonRunORng_LongWinLrn;                                */
/*  input boolean Misf_bDgoORng_ShrtWinLrnMax;                                */
/*  input boolean Misf_bMonRunORng_ShrtWinLrnMax;                             */
/*  input boolean Misf_bDgoORng_LongWinLrnMax;                                */
/*  input boolean Misf_bMonRunORng_LongWinLrnMax;                             */
/*  output st96 Misf_stLrnWin;                                                */
/*  output uint8 Mf_adap_lw_sample_count_uavn1[4];                            */
/*  output uint8 Mf_adap_shrt_sample_count_uavn1[4];                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidSaveLrn(void)
{
   uint8   u8LocalIndex;
   uint8   u8LocalMf_adap_bkpt_ind_uavn0;


   VEMS_vidGET(Mf_adap_bkpt_ind_uavn0, u8LocalMf_adap_bkpt_ind_uavn0);

   switch(Misf_stLrnWin)
   {
      case LRN_CALC_INIT:
         if (Misf_stDftLrn == LRN_COND)
         {
            Misf_stLrnWin = WIN_WAIT;
            for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
            {
               Mf_adap_lw_sample_count_uavn1[u8LocalIndex] = 0;
               Mf_adap_shrt_sample_count_uavn1[u8LocalIndex] = 0;
            }
         }
         break;

      case WIN_WAIT:
         if (Misf_stDftLrn == CALC_INIT)
         {
            Misf_stLrnWin = LRN_CALC_INIT;
         }
         else
         {
            if (  (u8LocalMf_adap_bkpt_ind_uavn0 > 0)
               && (Mf_adap_lw_cond_ok_uavb0 != 0)
               && (Mf_adap_Exp_cond_ok_uavb0 != 0)
               && (Mf_adap_TDC_cond_ok_uavb0 != 0)
               && (Mf_adap_Bdc_cond_ok_uavb0 != 0))
            {
               MISFDFTLRN_vidIniSaveLrn();
               if (Misf_stDftLrn != CALC_CYL1)
               {
                  Misf_stLrnWin = LRN_WIN;
                  MISFDFTLRN_vidWinAdap();
               }
               else
               {
                  Misf_stLrnWin = LRN_WAIT_CYL1;
               }
            }
         }
         break;

      case LRN_WIN:
         if (Misf_stDftLrn == CALC_INIT)
         {
            Misf_stLrnWin = LRN_CALC_INIT;
         }
         else
         {
            if (u8LocalMf_adap_bkpt_ind_uavn0 == 0)
            {
               if (  (Mf_adap_lw_sample_count_uavn1[0] >= Misf_noWinSample_T[0])
                  && (Mf_adap_lw_sample_count_uavn1[1] >= Misf_noWinSample_T[1])
                  && (Mf_adap_lw_sample_count_uavn1[2] >= Misf_noWinSample_T[2])
                  && (  Mf_adap_lw_sample_count_uavn1[3]
                     >= Misf_noWinSample_T[3]))
               {
                  MISFDFTLRN_vidWinAdapSave();
                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRN,
                               Misf_bDgoORng_ShrtWinLrn,
                               Misf_bMonRunORng_ShrtWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRN,
                               Misf_bDgoORng_LongWinLrn,
                               Misf_bMonRunORng_LongWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRNMAX,
                               Misf_bDgoORng_ShrtWinLrnMax,
                               Misf_bMonRunORng_ShrtWinLrnMax,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRNMAX,
                               Misf_bDgoORng_LongWinLrnMax,
                               Misf_bMonRunORng_LongWinLrnMax,
                               DIAG_DISPO);
               }
               Misf_stLrnWin = WIN_WAIT;

               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  Mf_adap_lw_sample_count_uavn1[u8LocalIndex] = 0;
                  Mf_adap_shrt_sample_count_uavn1[u8LocalIndex] = 0;
               }
            }
            else
            {
               if (  (Mf_adap_lw_cond_ok_uavb0 == 0)
                  && (Mf_adap_Exp_cond_ok_uavb0 == 0)
                  && (Mf_adap_TDC_cond_ok_uavb0 == 0)
                  && (Mf_adap_Bdc_cond_ok_uavb0 == 0)
                  && (Misf_stDftLrn != CALC_CYL1))
               {
                  Misf_stLrnWin = LRN_WAIT;
               }
               else
               {
                  if (Misf_stDftLrn == CALC_CYL1)
                  {
                     Misf_stLrnWin = LRN_WAIT_CYL1;
                  }
                  else
                  {
                     MISFDFTLRN_vidWinAdap();
                  }
               }
            }
         }
         break;

      case LRN_WAIT_CYL1:
         if (Misf_stDftLrn == CALC_INIT)
         {
            Misf_stLrnWin = LRN_CALC_INIT;
         }
         else
         {
            if (u8LocalMf_adap_bkpt_ind_uavn0 == 0)
            {
               if (  (Mf_adap_lw_sample_count_uavn1[0] >= Misf_noWinSample_T[0])
                  && (Mf_adap_lw_sample_count_uavn1[1] >= Misf_noWinSample_T[1])
                  && (Mf_adap_lw_sample_count_uavn1[2] >= Misf_noWinSample_T[2])
                  && (  Mf_adap_lw_sample_count_uavn1[3]
                     >= Misf_noWinSample_T[3]))
               {
                  MISFDFTLRN_vidWinAdapSave();
                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRN,
                               Misf_bDgoORng_ShrtWinLrn,
                               Misf_bMonRunORng_ShrtWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRN,
                               Misf_bDgoORng_LongWinLrn,
                               Misf_bMonRunORng_LongWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRNMAX,
                               Misf_bDgoORng_ShrtWinLrnMax,
                               Misf_bMonRunORng_ShrtWinLrnMax,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRNMAX,
                               Misf_bDgoORng_LongWinLrnMax,
                               Misf_bMonRunORng_LongWinLrnMax,
                               DIAG_DISPO);
               }
               Misf_stLrnWin = WIN_WAIT;

               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  Mf_adap_lw_sample_count_uavn1[u8LocalIndex] = 0;
                  Mf_adap_shrt_sample_count_uavn1[u8LocalIndex] = 0;
               }
            }
            else
            {
               if (  (Mf_adap_lw_cond_ok_uavb0 != 0)
                  && (Mf_adap_Exp_cond_ok_uavb0 != 0)
                  && (Mf_adap_TDC_cond_ok_uavb0 != 0)
                  && (Mf_adap_Bdc_cond_ok_uavb0 != 0)
                  && (Misf_stDftLrn == LRN_COND))
               {
                  Misf_stLrnWin = LRN_WIN;
                  MISFDFTLRN_vidWinAdap();
               }
               else
               {
                  if (  (Mf_adap_lw_cond_ok_uavb0 == 0)
                     && (Mf_adap_Exp_cond_ok_uavb0 == 0)
                     && (Mf_adap_TDC_cond_ok_uavb0 == 0)
                     && (Mf_adap_Bdc_cond_ok_uavb0 == 0))
                  {
                     Misf_stLrnWin = LRN_WAIT;
                  }
               }
            }
         }
         break;

      case LRN_WAIT:
         if (Misf_stDftLrn == CALC_INIT)
         {
            Misf_stLrnWin = LRN_CALC_INIT;
         }
         else
         {
            if (u8LocalMf_adap_bkpt_ind_uavn0 == 0)
            {
               if (  (Mf_adap_lw_sample_count_uavn1[0] >= Misf_noWinSample_T[0])
                  && (Mf_adap_lw_sample_count_uavn1[1] >= Misf_noWinSample_T[1])
                  && (Mf_adap_lw_sample_count_uavn1[2] >= Misf_noWinSample_T[2])
                  && (  Mf_adap_lw_sample_count_uavn1[3]
                     >= Misf_noWinSample_T[3]))
               {
                  MISFDFTLRN_vidWinAdapSave();
                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRN,
                               Misf_bDgoORng_ShrtWinLrn,
                               Misf_bMonRunORng_ShrtWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRN,
                               Misf_bDgoORng_LongWinLrn,
                               Misf_bMonRunORng_LongWinLrn,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_SHRTWINLRNMAX,
                               Misf_bDgoORng_ShrtWinLrnMax,
                               Misf_bMonRunORng_ShrtWinLrnMax,
                               DIAG_DISPO);

                  GDGAR_vidGdu(GD_DFT_ORNG_LONGWINLRNMAX,
                               Misf_bDgoORng_LongWinLrnMax,
                               Misf_bMonRunORng_LongWinLrnMax,
                               DIAG_DISPO);
               }
               Misf_stLrnWin = WIN_WAIT;

               for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
               {
                  Mf_adap_lw_sample_count_uavn1[u8LocalIndex] = 0;
                  Mf_adap_shrt_sample_count_uavn1[u8LocalIndex] = 0;
               }
            }
            else
            {
               if (  (Mf_adap_lw_cond_ok_uavb0 != 0)
                  && (Mf_adap_Exp_cond_ok_uavb0 != 0)
                  && (Mf_adap_TDC_cond_ok_uavb0 != 0)
                  && (Mf_adap_Bdc_cond_ok_uavb0 != 0))
               {
                  if (Misf_stDftLrn == CALC_CYL1)
                  {
                     Misf_stLrnWin = LRN_WAIT_CYL1;
                  }
                  else
                  {
                     Misf_stLrnWin = LRN_WIN;
                     MISFDFTLRN_vidWinAdap();
                  }
               }
            }
         }
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcWinApp                                   */
/* !Description :  Ce module calcule les erreurs brutes sur les durées des    */
/*                 fenêtres longues et des fenêtres courtes des cylindres 2 et*/
/*                 3 par rapport aux fenêtres du cylindre 1 du même cycle.    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidCalcLongWinApp();                          */
/*  extf argret void MISFDFTLRN_vidCalcTDCWinApp();                           */
/*  extf argret void MISFDFTLRN_vidCalcExpWinApp();                           */
/*  extf argret void MISFDFTLRN_vidCalcBdcWinApp();                           */
/*  extf argret void MISFDFTLRN_vidCalcIndWinApp();                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcWinApp(void)
{

   MISFDFTLRN_vidCalcLongWinApp();
   MISFDFTLRN_vidCalcTDCWinApp();
   MISFDFTLRN_vidCalcExpWinApp();
   MISFDFTLRN_vidCalcBdcWinApp();
   MISFDFTLRN_vidCalcIndWinApp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcLongWinApp                               */
/* !Description :  calcul des erreurs brutes sur les durées des fenêtres      */
/*                 longues des cylindres 2 et 3 par rapport aux fenêtres du   */
/*                 cylindre 1 du même cycle.                                  */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Misf_noCylIg;                                                 */
/*  input uint32 Misf_tiDlyLongWin;                                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint32 Misf_tiDlyLongWin1;                                          */
/*  input sint16 Misf_LongWin1Delta;                                          */
/*  output sint32 Misf_LongWinErrRaw[4];                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcLongWinApp(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalExtnoCylEng;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylIg;
   uint8  u8LocalLsbH;
   uint8  u8LocalLsbL;
   uint16 u16LocalMsb;
   uint16 u16LocalLsb;
   sint16 s16LocalLongWinErrRaw;
   uint32 u32LocalMisf_tiDlyLongWin;
   uint32 u32LocalNum;
   uint32 u32LocalDen;
   uint32 u32LocalR;
   uint32 u32LocalRHi;
   uint32 u32LocalRLo;
   uint32 u32LocalRLo2;
   uint32 u32LocalRLo1;
   sint32 s32LocalDen;
   sint32 s32LocalNum;


   VEMS_vidGET(Ext_noCylEng, u8LocalExtnoCylEng);
   u8LocalExt_noCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExtnoCylEng, 1, 12);
   VEMS_vidGET(Misf_noCylIg, u8LocalMisf_noCylIg);
   VEMS_vidGET(Misf_tiDlyLongWin, u32LocalMisf_tiDlyLongWin);
   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         if (Misf_tiDlyLongWin1 > 199999)
         {
            s32LocalDen = (sint32)( (u8LocalExt_noCylEng * 199999)
                                  + (Misf_LongWin1Delta * u8LocalMisf_noCylIg));
         }
         else
         {
            s32LocalDen = (sint32)(u8LocalExt_noCylEng * Misf_tiDlyLongWin1)
                        + (sint32)(Misf_LongWin1Delta * u8LocalMisf_noCylIg);
         }

         if (u32LocalMisf_tiDlyLongWin > Misf_tiDlyLongWin1)
         {
            u32LocalNum = u32LocalMisf_tiDlyLongWin - Misf_tiDlyLongWin1;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 199999);
            s32LocalNum = (sint32)u32LocalNum;
         }
         else
         {
            u32LocalNum = Misf_tiDlyLongWin1 - u32LocalMisf_tiDlyLongWin;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 199999);
            s32LocalNum = (sint32)u32LocalNum;
            s32LocalNum = -s32LocalNum;
         }
         s32LocalNum = (u8LocalExt_noCylEng * s32LocalNum)
                     - (sint32)(Misf_LongWin1Delta * u8LocalMisf_noCylIg);
         if (s32LocalDen == 0)
         {
            s16LocalLongWinErrRaw = 32767;
         }
         else
         {
            if (s32LocalNum == 0)
            {
               s16LocalLongWinErrRaw = 0;
            }
            else
            {
               u32LocalNum = (uint32)MATHSRV_udtABS(s32LocalNum);
               u32LocalDen = (uint32)MATHSRV_udtABS(s32LocalDen);
               if (u32LocalNum <= 1023)
               {
                  u32LocalR = (u32LocalNum * (uint32)4194304) / u32LocalDen;
               }
               else
               {
                  u16LocalMsb = (uint16)(u32LocalNum / 65536);
                  u32LocalRHi = (u16LocalMsb * (uint32)4194304) / u32LocalDen;
                  if (u32LocalRHi > 65535uL)
                  {
                     u32LocalR = UINT32_MAX;
                  }
                  else
                  {
                     u32LocalRHi = u32LocalRHi * 65536;
                     u16LocalLsb = (uint16)u32LocalNum;
                     if (u16LocalLsb <= 1023)
                     {
               /* !Deviation: Violation of QAC_3356 rule.                     */
               /* !Reason : The result of this logical operation can be TRUE  */
                        u32LocalRLo = (u16LocalLsb * (uint32)4194304)
                                    / u32LocalDen;
               /* !Deviation: Violation of QAC_3201 rule.                     */
               /* !Reason : This statement is reachable                       */
                     }
                     else
                     {
                        u8LocalLsbH = (uint8)(u16LocalLsb / 256);
                        u32LocalRLo1 = (u8LocalLsbH * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo1 = u32LocalRLo1 * 256;
                        u8LocalLsbL = (uint8)u16LocalLsb;
                        u32LocalRLo2 = (u8LocalLsbL * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo = u32LocalRLo1 + u32LocalRLo2;
                     }
                     u32LocalR = u32LocalRHi + u32LocalRLo;
                  }
               }

               if( (  (s32LocalNum > 0) && (s32LocalDen > 0))
                   || ((s32LocalNum < 0) && (s32LocalDen < 0)))
               {
                  u32LocalR = MATHSRV_udtMIN(u32LocalR, 32767);
                  s16LocalLongWinErrRaw = (sint16)u32LocalR;
               }
               else
               {
                  if (u32LocalR < 32768)
                  {
                     s16LocalLongWinErrRaw = (sint16)(-( (sint16)u32LocalR ));
                  }
                  else
                  {
                     s16LocalLongWinErrRaw = -32768;
                  }
               }
            }
         }
         Misf_LongWinErrRaw[u8LocalMisf_noCyl] = s16LocalLongWinErrRaw;
         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcTDCWinApp                                */
/* !Description :  calcul des erreurs brutes sur les durées des fenêtres      */
/*                 courtes TDC des cylindres 2 et 3 par rapport aux fenêtres  */
/*                 du cylindre 1 du même cycle.                               */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Misf_noCylIg;                                                 */
/*  input uint32 Misf_tiDlyTDCWin;                                            */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint32 Misf_tiDlyTDCWin1;                                           */
/*  input sint16 Misf_TDCWin1Delta;                                           */
/*  output sint16 Misf_TDCWinErrRaw[4];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcTDCWinApp(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalExtnoCylEng;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylIg;
   uint8  u8LocalLsbH;
   uint8  u8LocalLsbL;
   uint16 u16LocalMsb;
   uint16 u16LocalLsb;
   uint32 u32LocalMisf_tiDlyTDCWin;
   uint32 u32LocalNum;
   uint32 u32LocalDen;
   uint32 u32LocalR;
   sint16 s16LocalTDCWinErrRaw;
   uint32 u32LocalRHi;
   uint32 u32LocalRLo;
   uint32 u32LocalRLo2;
   uint32 u32LocalRLo1;
   sint32 s32LocalDen;
   sint32 s32LocalNum;


   VEMS_vidGET(Ext_noCylEng, u8LocalExtnoCylEng);
   u8LocalExt_noCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExtnoCylEng, 1, 12);
   VEMS_vidGET(Misf_noCylIg, u8LocalMisf_noCylIg);
   VEMS_vidGET(Misf_tiDlyTDCWin, u32LocalMisf_tiDlyTDCWin);
   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         if (Misf_tiDlyTDCWin1 > 99999)
         {
            s32LocalDen = (sint32)( (u8LocalExt_noCylEng * 99999)
                                  + (Misf_TDCWin1Delta * u8LocalMisf_noCylIg));
         }
         else
         {
            s32LocalDen = (sint32)(u8LocalExt_noCylEng * Misf_tiDlyTDCWin1)
                        + (sint32)(Misf_TDCWin1Delta * u8LocalMisf_noCylIg);
         }

         if (u32LocalMisf_tiDlyTDCWin > Misf_tiDlyTDCWin1)
         {
            u32LocalNum = u32LocalMisf_tiDlyTDCWin - Misf_tiDlyTDCWin1;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
         }
         else
         {
            u32LocalNum = Misf_tiDlyTDCWin1 - u32LocalMisf_tiDlyTDCWin;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
            s32LocalNum = -s32LocalNum;
         }

         s32LocalNum = (u8LocalExt_noCylEng * s32LocalNum)
                     - (sint32)(Misf_TDCWin1Delta * u8LocalMisf_noCylIg);


         if (s32LocalDen == 0)
         {
            s16LocalTDCWinErrRaw = 32767;
         }
         else
         {
            if (s32LocalNum == 0)
            {
               s16LocalTDCWinErrRaw = 0;
            }
            else
            {
               u32LocalNum = (uint32)MATHSRV_udtABS(s32LocalNum);
               u32LocalDen = (uint32)MATHSRV_udtABS(s32LocalDen);
               if (u32LocalNum <= 1023)
               {
                  u32LocalR = (u32LocalNum * (uint32)4194304) / u32LocalDen;
               }
               else
               {
                  u16LocalMsb = (uint16)(u32LocalNum / 65536);
                  u32LocalRHi = (u16LocalMsb * (uint32)4194304) / u32LocalDen;
                  if (u32LocalRHi > 65535uL)
                  {
                     u32LocalR = UINT32_MAX;
                  }
                  else
                  {
                     u32LocalRHi = u32LocalRHi * 65536;
                     u16LocalLsb = (uint16)u32LocalNum;
                     if (u16LocalLsb <= 1023)
                     {
               /* !Deviation: Violation of QAC_3356 rule.                     */
               /* !Reason : The result of this logical operation can be TRUE  */
                        u32LocalRLo = (u16LocalLsb * (uint32)4194304)
                                    / u32LocalDen;
               /* !Deviation: Violation of QAC_3201 rule.                     */
               /* !Reason : This statement is reachable                       */
                     }
                     else
                     {
                        u8LocalLsbH = (uint8)(u16LocalLsb / 256);
                        u32LocalRLo1 = (u8LocalLsbH * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo1 = u32LocalRLo1 * 256;
                        u8LocalLsbL = (uint8)u16LocalLsb;
                        u32LocalRLo2 = (u8LocalLsbL * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo = u32LocalRLo1 + u32LocalRLo2;
                     }
                     u32LocalR = u32LocalRHi + u32LocalRLo;
                  }
               }

               if( (  (s32LocalNum > 0) && (s32LocalDen > 0))
                   || ((s32LocalNum < 0) && (s32LocalDen < 0)))
               {
                  u32LocalR = MATHSRV_udtMIN(u32LocalR, (uint32)32767);
                  s16LocalTDCWinErrRaw = (sint16)u32LocalR;
               }
               else
               {
                  if (u32LocalR < 32768)
                  {
                     s16LocalTDCWinErrRaw = (sint16)(-( (sint16)u32LocalR ));
                  }
                  else
                  {
                     s16LocalTDCWinErrRaw = -32768;
                  }
               }
            }
         }
         Misf_TDCWinErrRaw[u8LocalMisf_noCyl] = s16LocalTDCWinErrRaw;
         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcExpWinApp                                */
/* !Description :  calcul des erreurs brutes sur les durées des fenêtres      */
/*                 courtes Exp des cylindres 2 et 3 par rapport aux fenêtres  */
/*                 du cylindre 1 du même cycle.                               */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Misf_noCylIg;                                                 */
/*  input uint32 Misf_tiDlyExpWin;                                            */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint32 Misf_tiDlyExpWin1;                                           */
/*  input sint16 Misf_ExpWin1Delta;                                           */
/*  output sint16 Misf_ExpWinErrRaw[4];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcExpWinApp(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalExtnoCylEng;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylIg;
   uint8  u8LocalLsbH;
   uint8  u8LocalLsbL;
   uint16 u16LocalMsb;
   uint16 u16LocalLsb;
   uint32 u32LocalMisf_tiDlyExpWin;
   uint32 u32LocalNum;
   uint32 u32LocalDen;
   uint32 u32LocalR;
   sint16 s16LocalExpWinErrRaw;
   uint32 u32LocalRHi;
   uint32 u32LocalRLo;
   uint32 u32LocalRLo2;
   uint32 u32LocalRLo1;
   sint32 s32LocalDen;
   sint32 s32LocalNum;


   VEMS_vidGET(Ext_noCylEng, u8LocalExtnoCylEng);
   u8LocalExt_noCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExtnoCylEng, 1, 12);
   VEMS_vidGET(Misf_noCylIg, u8LocalMisf_noCylIg);
   VEMS_vidGET(Misf_tiDlyExpWin, u32LocalMisf_tiDlyExpWin);
   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         if (Misf_tiDlyExpWin1 > 99999)
         {
            s32LocalDen = (sint32)( (u8LocalExt_noCylEng * 99999)
                                  + (Misf_ExpWin1Delta * u8LocalMisf_noCylIg));
         }
         else
         {
            s32LocalDen = (sint32)(u8LocalExt_noCylEng * Misf_tiDlyExpWin1)
                        + (sint32)(Misf_ExpWin1Delta * u8LocalMisf_noCylIg);
         }
         if (u32LocalMisf_tiDlyExpWin > Misf_tiDlyExpWin1)
         {
            u32LocalNum = u32LocalMisf_tiDlyExpWin - Misf_tiDlyExpWin1;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
         }
         else
         {
            u32LocalNum = Misf_tiDlyExpWin1 - u32LocalMisf_tiDlyExpWin;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
            s32LocalNum = -s32LocalNum;
         }
         s32LocalNum = (u8LocalExt_noCylEng * s32LocalNum)
                     - (sint32)(Misf_ExpWin1Delta * u8LocalMisf_noCylIg);


         if (s32LocalDen == 0)
         {
            s16LocalExpWinErrRaw = 32767;
         }
         else
         {
            if (s32LocalNum == 0)
            {
               s16LocalExpWinErrRaw = 0;
            }
            else
            {
               u32LocalNum = (uint32)MATHSRV_udtABS(s32LocalNum);
               u32LocalDen = (uint32)MATHSRV_udtABS(s32LocalDen);
               if (u32LocalNum <= 1023)
               {
                  u32LocalR = (u32LocalNum * (uint32)4194304) / u32LocalDen;
               }
               else
               {
                  u16LocalMsb = (uint16)(u32LocalNum / 65536);
                  u32LocalRHi = (u16LocalMsb * (uint32)4194304) / u32LocalDen;
                  if (u32LocalRHi > 65535uL)
                  {
                     u32LocalR = UINT32_MAX;
                  }
                  else
                  {
                     u32LocalRHi = u32LocalRHi * 65536;
                     u16LocalLsb = (uint16)u32LocalNum;
                     if (u16LocalLsb <= 1023)
                     {
               /* !Deviation: Violation of QAC_3356 rule.                     */
               /* !Reason : The result of this logical operation can be TRUE  */
                        u32LocalRLo = (u16LocalLsb * (uint32)4194304)
                                    / u32LocalDen;
               /* !Deviation: Violation of QAC_3201 rule.                     */
               /* !Reason : This statement is reachable                       */
                     }
                     else
                     {
                        u8LocalLsbH = (uint8)(u16LocalLsb / 256);
                        u32LocalRLo1 = (u8LocalLsbH * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo1 = u32LocalRLo1 * 256;
                        u8LocalLsbL = (uint8)u16LocalLsb;
                        u32LocalRLo2 = (u8LocalLsbL * (uint32)4194304)
                                     / u32LocalDen;
                        u32LocalRLo = u32LocalRLo1 + u32LocalRLo2;
                     }
                     u32LocalR = u32LocalRHi + u32LocalRLo;
                  }
               }

               if( (  (s32LocalNum > 0) && (s32LocalDen > 0))
                   || ((s32LocalNum < 0) && (s32LocalDen < 0)))
               {
                  u32LocalR = MATHSRV_udtMIN(u32LocalR, (uint32)32767);
                  s16LocalExpWinErrRaw = (sint16)u32LocalR;
               }
               else
               {
                  if (u32LocalR < 32768)
                  {
                     s16LocalExpWinErrRaw = (sint16)(-( (sint16)u32LocalR ));
                  }
                  else
                  {
                     s16LocalExpWinErrRaw = -32768;
                  }
               }
            }
         }
         Misf_ExpWinErrRaw[u8LocalMisf_noCyl] = s16LocalExpWinErrRaw;

         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcBdcWinApp                                */
/* !Description :  calcul des erreurs brutes sur les durées des fenêtres      */
/*                 courtes Bdc des cylindres 2 et 3 par rapport aux fenêtres  */
/*                 du cylindre 1 du même cycle.                               */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Ext_noCylEng;                                                 */
/*  input uint8 Misf_noCylIg;                                                 */
/*  input uint32 Misf_tiDlyBdcWin;                                            */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint32 Misf_tiDlyBdcWin1;                                           */
/*  input sint16 Misf_BdcWin1Delta;                                           */
/*  output sint16 Misf_BdcWinErrRaw[4];                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcBdcWinApp(void)
{
   uint8  u8LocalExt_noCylEng;
   uint8  u8LocalExtnoCylEng;
   uint8  u8LocalMisf_noCyl;
   uint8  u8LocalMisf_noCylIg;
   uint8  u8LocalLsbH;
   uint8  u8LocalLsbL;
   uint16 u16LocalMsb;
   uint16 u16LocalLsb;
   uint32 u32LocalMisf_tiDlyBdcWin;
   uint32 u32LocalNum;
   uint32 u32LocalDen;
   uint32 u32LocalR;
   sint16 s16LocalBdcWinErrRaw;
   uint32 u32LocalRHi;
   uint32 u32LocalRLo;
   uint32 u32LocalRLo2;
   uint32 u32LocalRLo1;
   sint32 s32LocalDen;
   sint32 s32LocalNum;


   VEMS_vidGET(Ext_noCylEng, u8LocalExtnoCylEng);
   u8LocalExt_noCylEng = (uint8)MATHSRV_udtCLAMP(u8LocalExtnoCylEng, 1, 12);
   VEMS_vidGET(Misf_noCylIg, u8LocalMisf_noCylIg);
   VEMS_vidGET(Misf_tiDlyBdcWin, u32LocalMisf_tiDlyBdcWin);
   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         if (Misf_tiDlyBdcWin1 > 99999)
         {
            s32LocalDen = (sint32)( (u8LocalExt_noCylEng * 99999)
                                  + (Misf_BdcWin1Delta * u8LocalMisf_noCylIg));
         }
         else
         {
            s32LocalDen = (sint32)(u8LocalExt_noCylEng * Misf_tiDlyBdcWin1)
                        + (sint32)(Misf_BdcWin1Delta * u8LocalMisf_noCylIg);
         }

         if (u32LocalMisf_tiDlyBdcWin > Misf_tiDlyBdcWin1)
         {
            u32LocalNum = u32LocalMisf_tiDlyBdcWin - Misf_tiDlyBdcWin1;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
         }
         else
         {
            u32LocalNum = Misf_tiDlyBdcWin1 - u32LocalMisf_tiDlyBdcWin;
            u32LocalNum = MATHSRV_udtMIN(u32LocalNum, 99999);
            s32LocalNum = (sint32)u32LocalNum;
            s32LocalNum = -s32LocalNum;
         }
         s32LocalNum = (u8LocalExt_noCylEng * s32LocalNum)
                     - (sint32)(Misf_BdcWin1Delta * u8LocalMisf_noCylIg);


         if (s32LocalDen == 0)
         {
               s16LocalBdcWinErrRaw = 32767;
         }
         else
         {
            if (s32LocalNum == 0)
            {
               s16LocalBdcWinErrRaw = 0;
            }
            else
            {
               u32LocalNum = (uint32)MATHSRV_udtABS(s32LocalNum);
               u32LocalDen = (uint32)MATHSRV_udtABS(s32LocalDen);
               if (u32LocalNum <= 1023)
               {
                  u32LocalR = (u32LocalNum * (uint32)4194304) / u32LocalDen;
               }
               else
               {
                  u16LocalMsb = (uint16)(u32LocalNum / 65536);
                  u32LocalRHi = (u16LocalMsb * (uint32)4194304) / u32LocalDen;
                  if (u32LocalRHi > 65535uL)
                  {
                     u32LocalR = UINT32_MAX;
                  }
                  else
                  {
                     u32LocalRHi = u32LocalRHi * 65536;
                     u16LocalLsb = (uint16)u32LocalNum;
                     if (u16LocalLsb <= 1023)
                     {
               /* !Deviation: Violation of QAC_3356 rule.                     */
               /* !Reason : The result of this logical operation can be TRUE  */
                        u32LocalRLo = (u16LocalLsb * (uint32)4194304)
                                    / u32LocalDen;
               /* !Deviation: Violation of QAC_3201 rule.                     */
               /* !Reason : This statement is reachable                       */
                     }
                     else
                     {
                        u8LocalLsbH = (uint8)(u16LocalLsb / 256);
                        u32LocalRLo1 = (u8LocalLsbH * (uint32)4194304)
                                      / u32LocalDen;
                        u32LocalRLo1 = u32LocalRLo1 * 256;
                        u8LocalLsbL = (uint8)u16LocalLsb;
                        u32LocalRLo2 = (u8LocalLsbL * (uint32)4194304)
                                      / u32LocalDen;
                        u32LocalRLo = u32LocalRLo1 + u32LocalRLo2;
                     }
                     u32LocalR = u32LocalRHi + u32LocalRLo;
                  }
               }

               if( (  (s32LocalNum > 0) && (s32LocalDen > 0))
                   || ((s32LocalNum < 0) && (s32LocalDen < 0)))
               {
                  u32LocalR = MATHSRV_udtMIN(u32LocalR, (uint32)32767);
                  s16LocalBdcWinErrRaw = (sint16)u32LocalR;
               }
               else
               {
                  if (u32LocalR < 32768)
                  {
                     s16LocalBdcWinErrRaw = (sint16)(-( (sint16)u32LocalR ));
                  }
                  else
                  {
                     s16LocalBdcWinErrRaw = -32768;
                  }
               }
            }
         }
         Misf_BdcWinErrRaw[u8LocalMisf_noCyl] = s16LocalBdcWinErrRaw;
         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcIndWinApp                                */
/* !Description :  Calcul de l'indice Mf_adap_bkpt_ind_uavn0                  */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Mf_adap_bkpt_ind_uavn0;                                       */
/*  input uint8 Mf_adap_bkpt_ind_prev_uavn0;                                  */
/*  input uint8 Mf_adap_n_bkpt_diff_lth_uacn0;                                */
/*  input uint8 Mf_adap_n_bkpt_diff_hth_uacn0;                                */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint16 Misf_Delta;                                                  */
/*  input uint16 Regime_moteur;                                               */
/*  input uint8 Mf_adap_n_index;                                              */
/*  input boolean Mf_adap_auth_uacn1[9];                                      */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input boolean Mf_adap_auth_uavb0;                                         */
/*  input boolean Mf_adap_manu_inh_auth_uacb0;                                */
/*  output uint8 Mf_adap_bkpt_ind_prev_uavn0;                                 */
/*  output uint16 Misf_Delta;                                                 */
/*  output uint8 Mf_adap_n_index;                                             */
/*  output boolean Mf_adap_auth_uavb0;                                        */
/*  output uint8 Mf_adap_bkpt_ind_uavn0;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcIndWinApp(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   boolean bLocalScndAndOprnd;
   uint8   u8LocalInd;
   uint8   u8LocalIndex;
   uint8   u8LocalIndexPlus;
   uint8   u8LocalMf_adap_bkpt_ind_uavn0;
   uint8   u8LocalIndx;
   uint16  u16LocalMf_adap_n_bkpt_uacn1[MISFDFTLRN_u8ARRAY_LENGTH];
   uint16  u16LocalBkpt;
   uint16  u16LocalAbs;
   uint16  u16LocalRegime_moteur;
   uint16  u16LocalPara;
   uint16  u16LocalCalcPara;
   sint32  s32LocalDiff;


   /* calcul des prev */
   VEMS_vidGET(Mf_adap_bkpt_ind_uavn0, u8LocalMf_adap_bkpt_ind_uavn0);
   Mf_adap_bkpt_ind_prev_uavn0 =
      (uint8)MATHSRV_udtMIN(u8LocalMf_adap_bkpt_ind_uavn0, 9);

   if (Mf_adap_bkpt_ind_prev_uavn0 == 0)
   {
      Misf_Delta = (uint16)(Mf_adap_n_bkpt_diff_lth_uacn0 * 32);
   }
   else
   {
      Misf_Delta = (uint16)(Mf_adap_n_bkpt_diff_hth_uacn0 * 32);
   }

   for (u8LocalInd = 0; u8LocalInd < 9; u8LocalInd++)
   {
      s32LocalDiff = (sint32)( (Mf_adap_n_bkpt_uacn1[u8LocalInd] * 32)
                                 - Misf_Delta);
      u16LocalBkpt = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);
      u16LocalMf_adap_n_bkpt_uacn1[u8LocalInd] = u16LocalBkpt;
   }

   /* calc para*/
   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   u16LocalRegime_moteur = (uint16)MATHSRV_udtMIN(u16LocalRegime_moteur, 8160);

   u16LocalPara = MATHSRV_u16CalcParaIncAryU16(u16LocalMf_adap_n_bkpt_uacn1,
                                               u16LocalRegime_moteur,
                                               9);
   u8LocalIndex = (uint8)(u16LocalPara / 256);
   u8LocalIndexPlus = (uint8)(u8LocalIndex + 1);

   Mf_adap_n_index = Mf_adap_n_bkpt_uacn1[u8LocalIndex];
   s32LocalDiff = (sint32)((Mf_adap_n_index * 32) - u16LocalRegime_moteur);
   u16LocalAbs = (uint16)MATHSRV_udtABS(s32LocalDiff);
   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                  Mf_adap_n_index,
                                                  9);
   u8LocalIndx = (uint8)(u16LocalCalcPara >> 8);
   Mf_adap_auth_uavb0 = Mf_adap_auth_uacn1[u8LocalIndx];
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);
   if (  (bLocalSrv_bAcvPlaMod == 0)
      || (Mf_adap_auth_uavb0 != 0)
      || (Mf_adap_manu_inh_auth_uacb0 != 0))
   {
      bLocalScndAndOprnd = 1;
   }
   else
   {
      bLocalScndAndOprnd = 0;
   }

   if (  (u16LocalAbs < Misf_Delta)
      && (bLocalScndAndOprnd != 0))
   {
      u8LocalMf_adap_bkpt_ind_uavn0 = u8LocalIndexPlus;
   }
   else
   {
      u8LocalMf_adap_bkpt_ind_uavn0 = 0;
   }
   VEMS_vidSET(Mf_adap_bkpt_ind_uavn0, u8LocalMf_adap_bkpt_ind_uavn0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcLrnInit                                  */
/* !Description :  Ce module extrait les valeurs des durées des fenêtres      */
/*                 longues et des fenêtres courtes du cylindre 1 afin d'en    */
/*                 calculer les variations par rapport au cycle précédent.    */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint16 Mf_adap_lw_err_dif_init_uacn0;                               */
/*  input uint16 Mf_adap_Exp_err_dif_init_uacn0;                              */
/*  input uint16 Mf_adap_TDC_err_dif_init_uacn0;                              */
/*  input uint16 Mf_adap_Bdc_err_dif_init_uacn0;                              */
/*  input sint32 Misf_LongWinErrRaw[4];                                       */
/*  input sint16 Misf_ExpWinErrRaw[4];                                        */
/*  input sint16 Misf_TDCWinErrRaw[4];                                        */
/*  input sint16 Misf_BdcWinErrRaw[4];                                        */
/*  output sint32 Mf_adap_lw_err_filt_uavn1[4];                               */
/*  output sint16 Mf_adap_lw_err_dif_neg_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_dif_pos_uavn1[4];                            */
/*  output sint16 Mf_adap_Exp_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Exp_err_dif_neg_uavn1[4];                           */
/*  output sint16 Mf_adap_Exp_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_TDC_err_dif_neg_uavn1[4];                           */
/*  output sint16 Mf_adap_TDC_err_dif_pos_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_filt_uavn1[4];                              */
/*  output sint16 Mf_adap_Bdc_err_dif_neg_uavn1[4];                           */
/*  output sint16 Mf_adap_Bdc_err_dif_pos_uavn1[4];                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcLrnInit(void)
{
   uint8  u8LocalIndex;
   uint16 u16LocalMfAdapLwErrDifInitUacn0;
   uint16 u16LocalMfAdapExpErrDifInitUacn0;
   uint16 u16LocalMfAdapTDCErrDifInitUacn0;
   uint16 u16LocalMfAdapBdcErrDifInitUacn0;
   sint16 s16LocalMfAdapLwErrDifInitUacn0;
   sint16 s16LocalMfAdapExpErrDifInitUacn0;
   sint16 s16LocalMfAdapTDCErrDifInitUacn0;
   sint16 s16LocalMfAdapBdcErrDifInitUacn0;


   u16LocalMfAdapLwErrDifInitUacn0 =
      (uint16)(Mf_adap_lw_err_dif_init_uacn0 / 2);
   u16LocalMfAdapExpErrDifInitUacn0 =
      (uint16)(Mf_adap_Exp_err_dif_init_uacn0 / 2);
   u16LocalMfAdapTDCErrDifInitUacn0 =
      (uint16)(Mf_adap_TDC_err_dif_init_uacn0 / 2);
   u16LocalMfAdapBdcErrDifInitUacn0 =
      (uint16)(Mf_adap_Bdc_err_dif_init_uacn0 / 2);

   s16LocalMfAdapLwErrDifInitUacn0 =
      (sint16)( (-1) * u16LocalMfAdapLwErrDifInitUacn0);
   s16LocalMfAdapExpErrDifInitUacn0 =
      (sint16)( (-1) * u16LocalMfAdapExpErrDifInitUacn0);
   s16LocalMfAdapTDCErrDifInitUacn0 =
      (sint16)( (-1) * u16LocalMfAdapTDCErrDifInitUacn0);
   s16LocalMfAdapBdcErrDifInitUacn0 =
      (sint16)( (-1) * u16LocalMfAdapBdcErrDifInitUacn0);

   for (u8LocalIndex = 0; u8LocalIndex < 4; u8LocalIndex++)
   {
      /* Fenêtre longue */
      Mf_adap_lw_err_filt_uavn1[u8LocalIndex] =
         MATHSRV_udtCLAMP(Misf_LongWinErrRaw[u8LocalIndex],
                          -8388608,
                          8388188);
      Mf_adap_lw_err_dif_neg_uavn1[u8LocalIndex] =
         s16LocalMfAdapLwErrDifInitUacn0;
      Mf_adap_lw_err_dif_pos_uavn1[u8LocalIndex] =
         (sint16)u16LocalMfAdapLwErrDifInitUacn0;

      /* Fenêtre courte détente */
      Mf_adap_Exp_err_filt_uavn1[u8LocalIndex] =
         Misf_ExpWinErrRaw[u8LocalIndex];
      Mf_adap_Exp_err_dif_neg_uavn1[u8LocalIndex] =
         s16LocalMfAdapExpErrDifInitUacn0;
      Mf_adap_Exp_err_dif_pos_uavn1[u8LocalIndex] =
         (sint16)u16LocalMfAdapExpErrDifInitUacn0;

      /* Fenêtre courte PMH */
      Mf_adap_TDC_err_filt_uavn1[u8LocalIndex] =
         Misf_TDCWinErrRaw[u8LocalIndex];
      Mf_adap_TDC_err_dif_neg_uavn1[u8LocalIndex] =
         s16LocalMfAdapTDCErrDifInitUacn0;
      Mf_adap_TDC_err_dif_pos_uavn1[u8LocalIndex] =
         (sint16)u16LocalMfAdapTDCErrDifInitUacn0;

      /* Fenêtre courte PMB */
      Mf_adap_Bdc_err_filt_uavn1[u8LocalIndex] =
         Misf_BdcWinErrRaw[u8LocalIndex];
      Mf_adap_Bdc_err_dif_neg_uavn1[u8LocalIndex] =
         s16LocalMfAdapBdcErrDifInitUacn0;
      Mf_adap_Bdc_err_dif_pos_uavn1[u8LocalIndex] =
         (sint16)u16LocalMfAdapBdcErrDifInitUacn0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidCalcLrn                                      */
/* !Description :  Cette fonction filtre l’erreur brute et calcule l’écart    */
/*                 entre les erreurs brute et filtrée.                        */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void MISFDFTLRN_vidLongWinVar();                              */
/*  extf argret void MISFDFTLRN_vidTDCWinVar();                               */
/*  extf argret void MISFDFTLRN_vidExpWinVar();                               */
/*  extf argret void MISFDFTLRN_vidBdcWinVar();                               */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFDFTLRN_vidCalcSumDeltaPrecal();                      */
/*  input uint8 Mf_adap_lw_corr_count_uavn1[9];                               */
/*  input uint8 Mf_adap_shrt_corr_count_uavn1[9];                             */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Mf_adap_inh_corr_precal_uacb0;                              */
/*  input boolean Mf_adap_lw_cond_ok_uavb0;                                   */
/*  input boolean Mf_adap_TDC_cond_ok_uavb0;                                  */
/*  input boolean Mf_adap_Exp_cond_ok_uavb0;                                  */
/*  input boolean Mf_adap_Bdc_cond_ok_uavb0;                                  */
/*  input uint8 Mf_adap_corr_precal_n_max_uacb0;                              */
/*  input uint8 Mf_adap_corr_precal_n_min_uacb0;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidCalcLrn(void)
{
   /* 06_calc_lrn */
   boolean bLocalResultlw;
   boolean bLocalResultshrt;
   uint8   u8LocalRegime_moteur_32;


   MISFDFTLRN_vidLongWinVar();
   MISFDFTLRN_vidTDCWinVar();
   MISFDFTLRN_vidExpWinVar();
   MISFDFTLRN_vidBdcWinVar();

   if (  (Mf_adap_lw_corr_count_uavn1[0] == 0)
      || (Mf_adap_lw_corr_count_uavn1[1] == 0)
      || (Mf_adap_lw_corr_count_uavn1[2] == 0)
      || (Mf_adap_lw_corr_count_uavn1[3] == 0)
      || (Mf_adap_lw_corr_count_uavn1[4] == 0)
      || (Mf_adap_lw_corr_count_uavn1[5] == 0)
      || (Mf_adap_lw_corr_count_uavn1[6] == 0)
      || (Mf_adap_lw_corr_count_uavn1[7] == 0)
      || (Mf_adap_lw_corr_count_uavn1[8] == 0))
   {
      bLocalResultlw = 1;
   }
   else
   {
      bLocalResultlw = 0;
   }

   if (  (Mf_adap_shrt_corr_count_uavn1[0] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[1] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[2] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[3] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[4] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[5] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[6] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[7] == 0)
      || (Mf_adap_shrt_corr_count_uavn1[8] == 0))
   {
      bLocalResultshrt = 1;
   }
   else
   {
      bLocalResultshrt = 0;
   }
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   if (  (Mf_adap_inh_corr_precal_uacb0 == 0)
      && (Mf_adap_lw_cond_ok_uavb0 != 0)
      && (Mf_adap_TDC_cond_ok_uavb0 != 0)
      && (Mf_adap_Exp_cond_ok_uavb0 != 0)
      && (Mf_adap_Bdc_cond_ok_uavb0 != 0)
      && (bLocalResultlw != 0)
      && (bLocalResultshrt != 0)
      && (  (u8LocalRegime_moteur_32 <= Mf_adap_corr_precal_n_max_uacb0)
         && (u8LocalRegime_moteur_32 >= Mf_adap_corr_precal_n_min_uacb0)))
   {
      MISFDFTLRN_vidCalcSumDeltaPrecal();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFDFTLRN_vidLongWinVar                                   */
/* !Description :  Ce module filtre l’erreur brute et calcule l’écart entre   */
/*                 les erreurs brute et filtrée des fenêtres longues.         */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input boolean Srv_bAcvPlaMod;                                             */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  input uint8 Mf_adap_lw_err_gain_ut_uacn0;                                 */
/*  input uint8 Mf_adap_lw_err_dif_gain_ut_uacn0;                             */
/*  input uint16 Mf_adap_lw_err_dif_lth_ut_uacn0;                             */
/*  input uint16 Mf_adap_lw_err_dif_hth_ut_uacn1[9];                          */
/*  input uint8 Mf_adap_lw_err_gain_uacn0;                                    */
/*  input uint8 Mf_adap_lw_err_dif_gain_uacn0;                                */
/*  input uint16 Mf_adap_lw_err_dif_lth_uacn0;                                */
/*  input uint16 Mf_adap_lw_err_dif_hth_uacn1[9];                             */
/*  input sint32 Mf_adap_lw_err_filt_uavn1[4];                                */
/*  input sint32 Misf_LongWinErrRaw[4];                                       */
/*  input sint16 Mf_adap_lw_err_dif_pos_uavn1[4];                             */
/*  input sint16 Mf_adap_lw_err_dif_neg_uavn1[4];                             */
/*  input boolean MISFDFTLRN_bLwHystOut;                                      */
/*  input boolean Mf_adap_lw_cond_ok_uavb1[4];                                */
/*  output sint32 Mf_adap_lw_err_filt_uavn1[4];                               */
/*  output sint16 Mf_adap_lw_err_dif_raw_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_dif_pos_uavn1[4];                            */
/*  output sint16 Mf_adap_lw_err_dif_neg_uavn1[4];                            */
/*  output uint16 Mf_adap_lw_err_dif_filt_uavn1[4];                           */
/*  output boolean Mf_adap_lw_cond_ok_uavb1[4];                               */
/*  output boolean Mf_adap_lw_cond_ok_uavb0;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFDFTLRN_vidLongWinVar(void)
{
   boolean bLocalSrv_bAcvPlaMod;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMf_adap_lw_err_gain;
   uint8   u8LocalMf_adap_lw_err_dif_gain;
   uint16  u16LocalLwErrDifFilt;
   uint16  u16LocalCalcPara;
   uint16  u16LocalMf_adap_Threshold_1;
   uint16  u16LocalMf_adap_Threshold_2;
   sint16  s16LocalLwErrDifRawUavn0;
   sint16  s16LocalLwErrDifPosUavn0;
   sint16  s16LocalLwErrDifPos;
   sint16  s16LocalLwErrDifNegUavn0;
   sint16  s16LocalLwErrDifNeg;
   uint32  u32LocalLwErrDifPosUavn0;
   uint32  u32LocalLwErrDifNegUavn0;
   uint32  u32LocalLwErrDifFiltMax;
   uint32  u32LocalLwErrDifFilt;
   uint32  u32LocalResult1;
   uint32  u32LocalResult2;
   uint32  u32LocalRes;
   uint32  u32LocalMod;
   uint32  u32LocalAdd1;
   uint32  u32LocalPos1;
   uint32  u32LocalPos2;
   sint32  s32LocalLwErrDifRawUavn0;
   sint32  s32LocalLwErrDifPosUavn0;
   sint32  s32LocalLwErrDifNegUavn0;
   sint32  s32LocalLwErrFiltUavn0;
   sint32  s32LocalLongWinErrRaw;
   sint32  s32LocalLwErrFilt;
   sint32  s32LocalDif;
   sint32  s32LocalResult1;
   sint32  s32LocalResult2;
   sint32  s32LocalMod;
   sint32  s32LocalDifRawPos;
   sint32  s32LocalCompDiv1;
   sint32  s32LocalCompDiv2;
   sint32  s32LocalMult;


   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);
   VEMS_vidGET(Srv_bAcvPlaMod, bLocalSrv_bAcvPlaMod);

   u16LocalCalcPara = MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                                  u8LocalRegime_moteur_32,
                                                  9);
   if (bLocalSrv_bAcvPlaMod != 0)
   {
      u8LocalMf_adap_lw_err_gain = Mf_adap_lw_err_gain_ut_uacn0;
      u8LocalMf_adap_lw_err_dif_gain = Mf_adap_lw_err_dif_gain_ut_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_lw_err_dif_lth_ut_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_lw_err_dif_hth_ut_uacn1, u16LocalCalcPara);
   }
   else
   {
      u8LocalMf_adap_lw_err_gain = Mf_adap_lw_err_gain_uacn0;
      u8LocalMf_adap_lw_err_dif_gain = Mf_adap_lw_err_dif_gain_uacn0;
      u16LocalMf_adap_Threshold_1 = Mf_adap_lw_err_dif_lth_uacn0;
      u16LocalMf_adap_Threshold_2 =
         MATHSRV_u16Interp1d(Mf_adap_lw_err_dif_hth_uacn1, u16LocalCalcPara);
   }

   switch(u8LocalMisf_noCyl)
   {
      case 0:
      case 1:
      case 2:
      case 3:
         /* Calcul de Mf_adap_lw_err_filt_uavn1 */
         s32LocalLwErrFiltUavn0 = Mf_adap_lw_err_filt_uavn1[u8LocalMisf_noCyl];
         s32LocalLongWinErrRaw = Misf_LongWinErrRaw[u8LocalMisf_noCyl];

         if (s32LocalLongWinErrRaw >= s32LocalLwErrFiltUavn0)
         {
            u32LocalRes = (uint32)( s32LocalLongWinErrRaw
                                  - s32LocalLwErrFiltUavn0);
            u32LocalResult1 = (u32LocalRes / 256) * u8LocalMf_adap_lw_err_gain;
            u32LocalMod = ( (u32LocalRes % 256) * u8LocalMf_adap_lw_err_gain)
                          / 256;
            u32LocalResult2 = u32LocalResult1 + u32LocalMod;
            s32LocalLwErrFilt =
               (sint32)(u32LocalResult2 + (uint32)s32LocalLwErrFiltUavn0);
         }
         else
         {
            u32LocalRes = (uint32)( s32LocalLwErrFiltUavn0
                                  - s32LocalLongWinErrRaw);
            u32LocalRes = MATHSRV_udtMIN(u32LocalRes, 2147483647);
            s32LocalDif = (sint32)u32LocalRes * (sint32)(-1);

            s32LocalResult1 = (s32LocalDif / 256) * u8LocalMf_adap_lw_err_gain;
            s32LocalMod = ( (s32LocalDif % 256) * u8LocalMf_adap_lw_err_gain)
                          / 256;
            s32LocalResult2 = s32LocalResult1 + s32LocalMod;

            if (s32LocalLwErrFiltUavn0 > 0)
            {
               s32LocalLwErrFilt = s32LocalResult2 + s32LocalLwErrFiltUavn0;
            }
            else
            {
               u32LocalPos1 = (uint32)(s32LocalResult2 * (-1));
               u32LocalPos2 = (uint32)(s32LocalLwErrFiltUavn0 * (-1));
               u32LocalAdd1 = u32LocalPos1 + u32LocalPos2;
               s32LocalLwErrFilt = (sint32)u32LocalAdd1 * (-1);
            }
         }
         Mf_adap_lw_err_filt_uavn1[u8LocalMisf_noCyl] =
            MATHSRV_udtCLAMP(s32LocalLwErrFilt, -8388608, 8388188);

         /* Calcul de Mf_adap_lw_err_dif_raw_uavn1*/
         if (s32LocalLongWinErrRaw > s32LocalLwErrFilt)
         {
            s32LocalLwErrDifRawUavn0 =
               s32LocalLongWinErrRaw - s32LocalLwErrFilt;
         }
         else
         {
            u32LocalRes = (uint32)(s32LocalLwErrFilt - s32LocalLongWinErrRaw);
            s32LocalLwErrDifRawUavn0 = (sint32)u32LocalRes * (sint32)(-1);
         }

         s16LocalLwErrDifRawUavn0 =
            (sint16)MATHSRV_udtCLAMP(s32LocalLwErrDifRawUavn0, -32768, 32767);
         Mf_adap_lw_err_dif_raw_uavn1[u8LocalMisf_noCyl] =
            s16LocalLwErrDifRawUavn0;


         /* Calcul de Mf_adap_lw_err_dif_pos_uavn1 */
         s16LocalLwErrDifPosUavn0 =
            Mf_adap_lw_err_dif_pos_uavn1[u8LocalMisf_noCyl];

         s32LocalDifRawPos =
            s32LocalLwErrDifRawUavn0 - s16LocalLwErrDifPosUavn0;

         if (u8LocalMf_adap_lw_err_dif_gain != 0)
         {
            s32LocalCompDiv1 =
               SINT32_MAX / (sint32)u8LocalMf_adap_lw_err_dif_gain;
            s32LocalCompDiv2 = SINT32_MIN / u8LocalMf_adap_lw_err_dif_gain;
            if (s32LocalDifRawPos > 0)
            {
               if (s32LocalDifRawPos > s32LocalCompDiv1)
               {
                  s32LocalMult = SINT32_MAX;
               }
               else
               {
                  s32LocalMult =
                     s32LocalDifRawPos * u8LocalMf_adap_lw_err_dif_gain;
               }
            }
            else
            {
               if (s32LocalDifRawPos < s32LocalCompDiv2)
               {
                  s32LocalMult = SINT32_MIN;
               }
               else
               {
                  s32LocalMult =
                     s32LocalDifRawPos * u8LocalMf_adap_lw_err_dif_gain;
               }
            }
         }
         else
         {
            s32LocalMult = 0;
         }

         s32LocalLwErrDifPosUavn0 = ( s32LocalMult
                                    / 256)
                                  + s16LocalLwErrDifPosUavn0;
         s16LocalLwErrDifPos =
            (sint16)MATHSRV_udtCLAMP(s32LocalLwErrDifPosUavn0, -32768, 32767);
         Mf_adap_lw_err_dif_pos_uavn1[u8LocalMisf_noCyl] = s16LocalLwErrDifPos;

         /* Calcul de Mf_adap_lw_err_dif_neg_uavn1 */
         s16LocalLwErrDifNegUavn0 =
            Mf_adap_lw_err_dif_neg_uavn1[u8LocalMisf_noCyl];

         if (s32LocalLwErrDifRawUavn0 > 0)
         {
            if (s16LocalLwErrDifNegUavn0 > 0)
            {
               s32LocalDifRawPos =
                  s32LocalLwErrDifRawUavn0 - s16LocalLwErrDifNegUavn0;
            }
            else
            {
               s32LocalDifRawPos =
                  s32LocalLwErrDifRawUavn0 - s16LocalLwErrDifNegUavn0;
            }
         }
         else
         {

            s32LocalDifRawPos =
               s32LocalLwErrDifRawUavn0 - s16LocalLwErrDifNegUavn0;
         }

         if (u8LocalMf_adap_lw_err_dif_gain != 0)
         {
            s32LocalCompDiv1 =
               SINT32_MAX / (sint32)u8LocalMf_adap_lw_err_dif_gain;
            s32LocalCompDiv2 = SINT32_MIN / u8LocalMf_adap_lw_err_dif_gain;
            if (s32LocalDifRawPos > 0)
            {
               if (s32LocalDifRawPos > s32LocalCompDiv1)
               {
                  s32LocalMult = SINT32_MAX;
               }
               else
               {
                  s32LocalMult =
                     s32LocalDifRawPos * u8LocalMf_adap_lw_err_dif_gain;
               }
            }
            else
            {
               if (s32LocalDifRawPos < s32LocalCompDiv2)
               {
                  s32LocalMult = SINT32_MIN;
               }
               else
               {
                  s32LocalMult =
                     s32LocalDifRawPos * u8LocalMf_adap_lw_err_dif_gain;
               }
            }
         }
         else
         {
            s32LocalMult = 0;
         }

         s32LocalLwErrDifNegUavn0 = ( s32LocalMult
                                    / 256)
                                  + s16LocalLwErrDifNegUavn0;

         s16LocalLwErrDifNeg =
            (sint16)MATHSRV_udtCLAMP(s32LocalLwErrDifNegUavn0, -32768, 32767);
         Mf_adap_lw_err_dif_neg_uavn1[u8LocalMisf_noCyl] = s16LocalLwErrDifNeg;

         /* Calcul de Mf_adap_lw_err_dif_filt_uavn1 */
         u32LocalLwErrDifPosUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalLwErrDifPosUavn0);
         u32LocalLwErrDifNegUavn0 =
            (uint32)MATHSRV_udtABS(s32LocalLwErrDifNegUavn0);
         u32LocalLwErrDifFiltMax = MATHSRV_udtMAX(u32LocalLwErrDifPosUavn0,
                                                  u32LocalLwErrDifNegUavn0);
         u32LocalLwErrDifFilt = u32LocalLwErrDifFiltMax * 2;
         u16LocalLwErrDifFilt =
            (uint16)MATHSRV_udtMIN(u32LocalLwErrDifFilt, 65535);
         Mf_adap_lw_err_dif_filt_uavn1[u8LocalMisf_noCyl] =
            u16LocalLwErrDifFilt;

         MATHSRV_vidSchmittTriggerU16(u16LocalLwErrDifFilt,
                                      u16LocalMf_adap_Threshold_1,
                                      u16LocalMf_adap_Threshold_2,
                                      MATHSRV_FALLING_SCHMITT_TRIGGER,
                                      &MISFDFTLRN_bLwHystOut);
         if (MISFDFTLRN_bLwHystOut != 0)
         {
            Mf_adap_lw_cond_ok_uavb1[u8LocalMisf_noCyl] = 1;

         }
         else
         {
            Mf_adap_lw_cond_ok_uavb1[u8LocalMisf_noCyl] = 0;
         }

         if (  (Mf_adap_lw_cond_ok_uavb1[0] != 0)
            && (Mf_adap_lw_cond_ok_uavb1[1] != 0)
            && (Mf_adap_lw_cond_ok_uavb1[2] != 0)
            && (Mf_adap_lw_cond_ok_uavb1[3] != 0))
         {
            Mf_adap_lw_cond_ok_uavb0 = 1;
         }
         else
         {
            Mf_adap_lw_cond_ok_uavb0 = 0;
         }
         break;

      case 4:
      case 5:
         break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         break;
   }
}
/*************************** end of file **************************************/