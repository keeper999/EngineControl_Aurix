/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MISFWINADP                                              */
/* !Description     : MISFWINADP Component                                    */
/*                                                                            */
/* !Module          : MISFWINADP                                              */
/* !Description     : Correction des fenêtres d’acquisition par un adaptatif  */
/*                                                                            */
/* !File            : MISFWINADP_FCT1.C                                       */
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
/*   1 / MISFWINADP_vidInitOutput                                             */
/*   2 / MISFWINADP_vidConditionActiv                                         */
/*   3 / MISFWINADP_vidCorrectedWindow                                        */
/*   4 / MISFWINADP_vidCorrectWin_Interp                                      */
/*   5 / MISFWINADP_vidCorrectWin_Calc                                        */
/*                                                                            */
/* !Reference   : V02 NT 09 00776 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/MISF/MISFWINADP/MISFWINADP_FCT1.c_$*/
/* $Revision::   1.2      $$Author::   fsanchez2      $$Date::   15 Apr 2010 $*/
/* $Author::   fsanchez2                              $$Date::   15 Apr 2010 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MISFWINADP.h"
#include "MISFWINADP_L.h"
#include "MISFWINADP_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidInitOutput                                   */
/* !Description :  initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Misf_bAcvWinAdp;                                           */
/*  output uint32 Misf_tiDlyLongWinAdp;                                       */
/*  output uint32 Misf_tiDlyExpWinAdp;                                        */
/*  output uint32 Misf_tiDlyTDCWinAdp;                                        */
/*  output uint32 Misf_tiDlyBdcWinAdp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidInitOutput(void)
{
   VEMS_vidSET(Misf_bAcvWinAdp, 0);
   VEMS_vidSET(Misf_tiDlyLongWinAdp, 0);
   VEMS_vidSET(Misf_tiDlyExpWinAdp, 0);
   VEMS_vidSET(Misf_tiDlyTDCWinAdp, 0);
   VEMS_vidSET(Misf_tiDlyBdcWinAdp, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidConditionActiv                               */
/* !Description :  Cette stratégie permet de corriger la durée de chaque      */
/*                 fenêtre  d’acquisition à l’aide des valeurs                */
/*                 d’adaptatifs,suite à la stratégie d’apprentissage des      */
/*                 défauts géométriques de la cible moteur.                   */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Regime_moteur;                                               */
/*  input uint16 MF_N_MIN_ACQ;                                                */
/*  output boolean Misf_bAcvWinAdp;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidConditionActiv(void)
{
   boolean bLocalInhMisfWinAdp;
   uint16  u16LocalRegime_moteur;


   VEMS_vidGET(Regime_moteur, u16LocalRegime_moteur);
   bLocalInhMisfWinAdp = GDGAR_bGetFRM(FRM_FRM_INHMISFWINADP);

   if (u16LocalRegime_moteur >= MF_N_MIN_ACQ)
   {
      if (bLocalInhMisfWinAdp == 0)
      {
         VEMS_vidSET(Misf_bAcvWinAdp, 1);
      }
      else
      {
         VEMS_vidSET(Misf_bAcvWinAdp, 0);
      }
   }
   else
   {
      VEMS_vidSET(Misf_bAcvWinAdp, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidCorrectedWindow                              */
/* !Description :  Selon le n° du cylindre on détermine sur quel demi- tour de*/
/*                 la cible moteur est scruté le misfire et par  conséquent   */
/*                 nous pouvons ajouter l’adaptatif correspondant.            */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MISFWINADP_vidCorrectWin_Interp();                       */
/*  extf argret void MISFWINADP_vidCorrectWin_Calc();                         */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Misf_bAcvWinAdp;                                            */
/*  input boolean Mf_win_1_uavb0;                                             */
/*  input uint32 Misf_tiDlyLongWin;                                           */
/*  input uint32 Misf_tiDlyExpWin;                                            */
/*  input uint32 Misf_tiDlyTDCWin;                                            */
/*  input uint32 Misf_tiDlyBdcWin;                                            */
/*  output uint32 Misf_tiDlyLongWinAdp;                                       */
/*  output uint32 Misf_tiDlyExpWinAdp;                                        */
/*  output uint32 Misf_tiDlyTDCWinAdp;                                        */
/*  output uint32 Misf_tiDlyBdcWinAdp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidCorrectedWindow(void)
{
   boolean bLocalMisf_bAcvWinAdp;
   boolean bLocalMf_win_1_uavb0;
   uint32  u32LocalMisf_tiDlyLongWin;
   uint32  u32LocalMisf_tiDlyExpWin;
   uint32  u32LocalMisf_tiDlyTDCWin;
   uint32  u32LocalMisf_tiDlyBdcWin;
   uint32  u32LocalMisf_tiDlyLong;
   uint32  u32LocalMisf_tiDlyExp;
   uint32  u32LocalMisf_tiDlyTDC;
   uint32  u32LocalMisf_tiDlyBdc;


   VEMS_vidGET(Misf_bAcvWinAdp, bLocalMisf_bAcvWinAdp);
   VEMS_vidGET(Mf_win_1_uavb0, bLocalMf_win_1_uavb0);
   VEMS_vidGET(Misf_tiDlyLongWin, u32LocalMisf_tiDlyLongWin);
   VEMS_vidGET(Misf_tiDlyExpWin, u32LocalMisf_tiDlyExpWin);
   VEMS_vidGET(Misf_tiDlyTDCWin, u32LocalMisf_tiDlyTDCWin);
   VEMS_vidGET(Misf_tiDlyBdcWin, u32LocalMisf_tiDlyBdcWin);


   if ( (bLocalMisf_bAcvWinAdp != 0)
      &&(bLocalMf_win_1_uavb0 == 0) )
   {
      MISFWINADP_vidCorrectWin_Interp();
      MISFWINADP_vidCorrectWin_Calc();
   }
   else
   {
      u32LocalMisf_tiDlyLong = MATHSRV_udtMIN(u32LocalMisf_tiDlyLongWin,
                                                 200000);
      u32LocalMisf_tiDlyExp = MATHSRV_udtMIN(u32LocalMisf_tiDlyExpWin,
                                                100000);
      u32LocalMisf_tiDlyTDC = MATHSRV_udtMIN(u32LocalMisf_tiDlyTDCWin,
                                                100000);
      u32LocalMisf_tiDlyBdc = MATHSRV_udtMIN(u32LocalMisf_tiDlyBdcWin,
                                                100000);
      VEMS_vidSET(Misf_tiDlyLongWinAdp, u32LocalMisf_tiDlyLong);
      VEMS_vidSET(Misf_tiDlyExpWinAdp, u32LocalMisf_tiDlyExp);
      VEMS_vidSET(Misf_tiDlyTDCWinAdp, u32LocalMisf_tiDlyTDC);
      VEMS_vidSET(Misf_tiDlyBdcWinAdp, u32LocalMisf_tiDlyBdc);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidCorrectWin_Interp                            */
/* !Description :  calcul d'interpolation                                     */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidGET1DArray(argin, argin, argio);                             */
/*  extf MATHSRV_u16CalcParaIncAryU8(????);                                   */
/*  extf MATHSRV_u16Interp1d(????);                                           */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input uint8 Misf_noCyl;                                                   */
/*  input uint8 Regime_moteur_32;                                             */
/*  input sint16 Misf_prm_tiDlyLongWinLrnCyl2[9];                             */
/*  input sint16 Misf_prm_tiDlyLongWinLrnCyl3[9];                             */
/*  input sint16 Misf_prm_tiDlyLongWinLrnCyl4[9];                             */
/*  input sint16 Misf_prm_tiDlyExpWinLrnCyl2[9];                              */
/*  input sint16 Misf_prm_tiDlyExpWinLrnCyl3[9];                              */
/*  input sint16 Misf_prm_tiDlyExpWinLrnCyl4[9];                              */
/*  input sint16 Misf_prm_tiDlyTDCWinLrnCyl2[9];                              */
/*  input sint16 Misf_prm_tiDlyTDCWinLrnCyl3[9];                              */
/*  input sint16 Misf_prm_tiDlyTDCWinLrnCyl4[9];                              */
/*  input sint16 Misf_prm_tiDlyBdcWinLrnCyl2[9];                              */
/*  input sint16 Misf_prm_tiDlyBdcWinLrnCyl3[9];                              */
/*  input sint16 Misf_prm_tiDlyBdcWinLrnCyl4[9];                              */
/*  input uint8 Mf_adap_n_bkpt_uacn1[9];                                      */
/*  output uint16 MISFWINADP_u16InterpTab[4];                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidCorrectWin_Interp(void)
{
   uint8   u8LocalRegime_moteur_32;
   uint8   u8LocalMisf_noCyl;
   uint8   u8LocalIndex;
   uint16  u16LocalParaX;
   uint16  u16LocalMisf_DlyLongWinLrnCyl2[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyLongWinLrnCyl3[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyLongWinLrnCyl4[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyExpWinLrnCyl2[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyExpWinLrnCyl3[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyExpWinLrnCyl4[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyTDCWinLrnCyl2[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyTDCWinLrnCyl3[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyTDCWinLrnCyl4[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyBdcWinLrnCyl2[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyBdcWinLrnCyl3[MISFWINADP_u8TabLenth];
   uint16  u16LocalMisf_DlyBdcWinLrnCyl4[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyLongWinLrnCyl2[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyLongWinLrnCyl3[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyLongWinLrnCyl4[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyExpWinLrnCyl2[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyExpWinLrnCyl3[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyExpWinLrnCyl4[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyTDCWinLrnCyl2[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyTDCWinLrnCyl3[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyTDCWinLrnCyl4[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyBdcWinLrnCyl2[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyBdcWinLrnCyl3[MISFWINADP_u8TabLenth];
   sint16  s16LocalMisf_DlyBdcWinLrnCyl4[MISFWINADP_u8TabLenth];

   VEMS_vidGET(Misf_noCyl, u8LocalMisf_noCyl);
   VEMS_vidGET(Regime_moteur_32, u8LocalRegime_moteur_32);

   VEMS_vidGET1DArray(Misf_prm_tiDlyLongWinLrnCyl2,
                      9,
                      s16LocalMisf_DlyLongWinLrnCyl2);
   VEMS_vidGET1DArray(Misf_prm_tiDlyLongWinLrnCyl3,
                      9,
                      s16LocalMisf_DlyLongWinLrnCyl3);
   VEMS_vidGET1DArray(Misf_prm_tiDlyLongWinLrnCyl4,
                      9,
                      s16LocalMisf_DlyLongWinLrnCyl4);
   VEMS_vidGET1DArray(Misf_prm_tiDlyExpWinLrnCyl2,
                      9,
                      s16LocalMisf_DlyExpWinLrnCyl2);
   VEMS_vidGET1DArray(Misf_prm_tiDlyExpWinLrnCyl3,
                      9,
                      s16LocalMisf_DlyExpWinLrnCyl3);
   VEMS_vidGET1DArray(Misf_prm_tiDlyExpWinLrnCyl4,
                      9,
                      s16LocalMisf_DlyExpWinLrnCyl4);
   VEMS_vidGET1DArray(Misf_prm_tiDlyTDCWinLrnCyl2,
                      9,
                      s16LocalMisf_DlyTDCWinLrnCyl2);
   VEMS_vidGET1DArray(Misf_prm_tiDlyTDCWinLrnCyl3,
                      9,
                      s16LocalMisf_DlyTDCWinLrnCyl3);
   VEMS_vidGET1DArray(Misf_prm_tiDlyTDCWinLrnCyl4,
                      9,
                      s16LocalMisf_DlyTDCWinLrnCyl4);
   VEMS_vidGET1DArray(Misf_prm_tiDlyBdcWinLrnCyl2,
                      9,
                      s16LocalMisf_DlyBdcWinLrnCyl2);
   VEMS_vidGET1DArray(Misf_prm_tiDlyBdcWinLrnCyl3,
                      9,
                      s16LocalMisf_DlyBdcWinLrnCyl3);
   VEMS_vidGET1DArray(Misf_prm_tiDlyBdcWinLrnCyl4,
                      9,
                      s16LocalMisf_DlyBdcWinLrnCyl4);

   for (u8LocalIndex = 0; u8LocalIndex < MISFWINADP_u8TabLenth; u8LocalIndex++)
   {
      u16LocalMisf_DlyLongWinLrnCyl2[u8LocalIndex]
            = (uint16)(s16LocalMisf_DlyLongWinLrnCyl2[u8LocalIndex] + 32768);
      u16LocalMisf_DlyLongWinLrnCyl3[u8LocalIndex]
            = (uint16)(s16LocalMisf_DlyLongWinLrnCyl3[u8LocalIndex] + 32768);
      u16LocalMisf_DlyLongWinLrnCyl4[u8LocalIndex]
            = (uint16)(s16LocalMisf_DlyLongWinLrnCyl4[u8LocalIndex] + 32768);
      u16LocalMisf_DlyExpWinLrnCyl2[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyExpWinLrnCyl2[u8LocalIndex] + 32768);
      u16LocalMisf_DlyExpWinLrnCyl3[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyExpWinLrnCyl3[u8LocalIndex] + 32768);
      u16LocalMisf_DlyExpWinLrnCyl4[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyExpWinLrnCyl4[u8LocalIndex] + 32768);
      u16LocalMisf_DlyTDCWinLrnCyl2[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyTDCWinLrnCyl2[u8LocalIndex] + 32768);
      u16LocalMisf_DlyTDCWinLrnCyl3[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyTDCWinLrnCyl3[u8LocalIndex] + 32768);
      u16LocalMisf_DlyTDCWinLrnCyl4[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyTDCWinLrnCyl4[u8LocalIndex] + 32768);
      u16LocalMisf_DlyBdcWinLrnCyl2[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyBdcWinLrnCyl2[u8LocalIndex] + 32768);
      u16LocalMisf_DlyBdcWinLrnCyl3[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyBdcWinLrnCyl3[u8LocalIndex] + 32768);
      u16LocalMisf_DlyBdcWinLrnCyl4[u8LocalIndex]
            =  (uint16)(s16LocalMisf_DlyBdcWinLrnCyl4[u8LocalIndex] + 32768);
   }

   u16LocalParaX =
      MATHSRV_u16CalcParaIncAryU8(Mf_adap_n_bkpt_uacn1,
                                  u8LocalRegime_moteur_32,
                                  9);

   switch (u8LocalMisf_noCyl)
   {
      case 0:
         MISFWINADP_u16InterpTab[0] = 32768;
         MISFWINADP_u16InterpTab[1] = 32768;
         MISFWINADP_u16InterpTab[2] = 32768;
         MISFWINADP_u16InterpTab[3] = 32768;
      break;
      case 1:
         MISFWINADP_u16InterpTab[0] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyLongWinLrnCyl2[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[1] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyExpWinLrnCyl2[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[2] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyTDCWinLrnCyl2[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[3] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyBdcWinLrnCyl2[0],
                                u16LocalParaX);
      break;
      case 2:
         MISFWINADP_u16InterpTab[0] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyLongWinLrnCyl3[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[1] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyExpWinLrnCyl3[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[2] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyTDCWinLrnCyl3[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[3] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyBdcWinLrnCyl3[0],
                                u16LocalParaX);
      break;
      case 3:
         MISFWINADP_u16InterpTab[0] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyLongWinLrnCyl4[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[1] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyExpWinLrnCyl4[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[2] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyTDCWinLrnCyl4[0],
                                u16LocalParaX);
         MISFWINADP_u16InterpTab[3] =
            MATHSRV_u16Interp1d(&u16LocalMisf_DlyBdcWinLrnCyl4[0],
                                u16LocalParaX);
      break;
      case 4:
      case 5:
         MISFWINADP_u16InterpTab[0] = 32768;
         MISFWINADP_u16InterpTab[1] = 32768;
         MISFWINADP_u16InterpTab[2] = 32768;
         MISFWINADP_u16InterpTab[3] = 32768;
      break;

      default:
         SWFAIL_vidSoftwareErrorHook();
         MISFWINADP_u16InterpTab[0] = 32768;
         MISFWINADP_u16InterpTab[1] = 32768;
         MISFWINADP_u16InterpTab[2] = 32768;
         MISFWINADP_u16InterpTab[3] = 32768;
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MISFWINADP_vidCorrectWin_Calc                              */
/* !Description :  calcul des variables (Misf_tiDlyLongWinAdp,Misf_tiDlyExpWinAdp,Misf_tiDlyTDCWinAdp,Misf_tiDlyBdcWinAdp)*/
/* !Number      :  FCT1.5                                                     */
/* !Author      :  Oussama.HIDRI                                              */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Misf_tiDlyLongWin;                                           */
/*  input uint32 Misf_tiDlyExpWin;                                            */
/*  input uint32 Misf_tiDlyTDCWin;                                            */
/*  input uint32 Misf_tiDlyBdcWin;                                            */
/*  input uint16 MISFWINADP_u16InterpTab[4];                                  */
/*  output uint32 Misf_tiDlyLongWinAdp;                                       */
/*  output uint32 Misf_tiDlyExpWinAdp;                                        */
/*  output uint32 Misf_tiDlyTDCWinAdp;                                        */
/*  output uint32 Misf_tiDlyBdcWinAdp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MISFWINADP_vidCorrectWin_Calc(void)
{
   sint16  s16Localcalc;
   sint16  s16Localcalc_Lsb;
   sint16  s16Localcalc_Msb;
   uint32  u32LocalMisf_tiDlyLongWin;
   uint32  u32LocalMisf_tiDlyExpWin;
   uint32  u32LocalMisf_tiDlyTDCWin;
   uint32  u32LocalMisf_tiDlyBdcWin;
   uint32  u32LocalCalc;
   uint32  u32LocalMisf_tiDlyLongWinAdp;
   uint32  u32LocalMisf_tiDlyExpWinAdp;
   uint32  u32LocalMisf_tiDlyTDCWinAdp;
   uint32  u32LocalMisf_tiDlyBdcWinAdp;
   sint32  s32Localcalc;
   sint32  s32Localcalc_Lsb;
   sint32  s32Localcalc_Msb;


   VEMS_vidGET(Misf_tiDlyLongWin, u32LocalMisf_tiDlyLongWin);
   VEMS_vidGET(Misf_tiDlyExpWin, u32LocalMisf_tiDlyExpWin);
   VEMS_vidGET(Misf_tiDlyTDCWin, u32LocalMisf_tiDlyTDCWin);
   VEMS_vidGET(Misf_tiDlyBdcWin, u32LocalMisf_tiDlyBdcWin);


   /* calcul Misf_tiDlyLongWinAdp */
   s16Localcalc = (sint16)(MISFWINADP_u16InterpTab[0] - 32768);
   s16Localcalc_Lsb = (sint16)(u32LocalMisf_tiDlyLongWin & 0x7FFF);
   s16Localcalc_Msb = (sint16)(u32LocalMisf_tiDlyLongWin / 32768);

   s32Localcalc_Lsb = (sint32)( ( ( s16Localcalc_Lsb * s16Localcalc)
                                  + 2097152)
                                / 4194304);
   s32Localcalc_Msb = (sint32)(s16Localcalc_Msb * s16Localcalc)/128;
   s32Localcalc = (s32Localcalc_Msb + s32Localcalc_Lsb);

   u32LocalCalc = (uint32)( ( s32Localcalc
                            + (sint32) u32LocalMisf_tiDlyLongWin));
   u32LocalMisf_tiDlyLongWinAdp = MATHSRV_udtMIN(u32LocalCalc, 200000);
   VEMS_vidSET(Misf_tiDlyLongWinAdp, u32LocalMisf_tiDlyLongWinAdp);


   /* calcul Misf_tiDlyExpWinAdp */
   s16Localcalc = (sint16)(MISFWINADP_u16InterpTab[1] - 32768);
   s16Localcalc_Lsb = (sint16)(u32LocalMisf_tiDlyExpWin & 0x7FFF);
   s16Localcalc_Msb = (sint16)(u32LocalMisf_tiDlyExpWin / 32768);

   s32Localcalc_Lsb = (sint32)( ( ( s16Localcalc_Lsb * s16Localcalc)
                                + 2097152)
                              / 4194304);
   s32Localcalc_Msb = (sint32)(s16Localcalc_Msb * s16Localcalc)/128;
   s32Localcalc = (s32Localcalc_Msb + s32Localcalc_Lsb);

   u32LocalCalc = (uint32)( ( s32Localcalc
                            + (sint32)u32LocalMisf_tiDlyExpWin));
   u32LocalMisf_tiDlyExpWinAdp = MATHSRV_udtMIN(u32LocalCalc, 100000);
   VEMS_vidSET(Misf_tiDlyExpWinAdp, u32LocalMisf_tiDlyExpWinAdp);

   /* calcul Misf_tiDlyTDCWinAdp */
   s16Localcalc = (sint16)(MISFWINADP_u16InterpTab[2] - 32768);
   s16Localcalc_Lsb = (sint16)(u32LocalMisf_tiDlyTDCWin & 0x7FFF);
   s16Localcalc_Msb = (sint16)(u32LocalMisf_tiDlyTDCWin / 32768);

   s32Localcalc_Lsb = (sint32)( ( s16Localcalc_Lsb * s16Localcalc)
                                 + 2097152)
                               / 4194304;
   s32Localcalc_Msb = (sint32)(s16Localcalc_Msb * s16Localcalc)/128;
   s32Localcalc = (s32Localcalc_Msb + s32Localcalc_Lsb);

   u32LocalCalc = (uint32)( ( s32Localcalc
                            + (sint32)u32LocalMisf_tiDlyTDCWin));
   u32LocalMisf_tiDlyTDCWinAdp = MATHSRV_udtMIN(u32LocalCalc, 100000);
   VEMS_vidSET(Misf_tiDlyTDCWinAdp, u32LocalMisf_tiDlyTDCWinAdp);

   /* calcul Misf_tiDlyBdcWinAdp */
   s16Localcalc = (sint16)(MISFWINADP_u16InterpTab[3] - 32768);
   s16Localcalc_Lsb = (sint16)(u32LocalMisf_tiDlyBdcWin & 0x7FFF);
   s16Localcalc_Msb = (sint16)(u32LocalMisf_tiDlyBdcWin / 32768);

   s32Localcalc_Lsb = (sint32)( ( s16Localcalc_Lsb * s16Localcalc)
                                + 2097152)
                              / 4194304;
   s32Localcalc_Msb = (sint32)(s16Localcalc_Msb * s16Localcalc)/128;
   s32Localcalc = (s32Localcalc_Msb + s32Localcalc_Lsb);

   u32LocalCalc = (uint32)( ( s32Localcalc
                            + (sint32) u32LocalMisf_tiDlyBdcWin));
   u32LocalMisf_tiDlyBdcWinAdp = MATHSRV_udtMIN(u32LocalCalc, 100000);
   VEMS_vidSET(Misf_tiDlyBdcWinAdp, u32LocalMisf_tiDlyBdcWinAdp);
}
/*------------------------------- end of file --------------------------------*/