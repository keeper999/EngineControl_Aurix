/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TARIDLSTA                                               */
/* !Description     : TARIDLSTA component.                                    */
/*                                                                            */
/* !Module          : TARIDLSTA                                               */
/* !Description     : Consigne de Ralenti Statique                            */
/*                                                                            */
/* !File            : TARIDLSTA_FCT3.C                                        */
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
/*   1 / TARIDLSTA_vidCalc_Idl_tar_ss                                         */
/*   2 / TARIDLSTA_vidCalc_Idl_tar_AT                                         */
/*   3 / TARIDLSTA_vidCalc_spd_gbx_output                                     */
/*   4 / TARIDLSTA_vidCalc_Idl_tar_AT_bas                                     */
/*   5 / TARIDLSTA_vidCalc_Idl_tar_AT_inc                                     */
/*   6 / TARIDLSTA_vidFrze_Idl_tar_AT_eng                                     */
/*   7 / TARIDLSTA_vidCalc_Idl_tar_AT_Cun                                     */
/*   8 / TARIDLSTA_vidCalc_Idl_tar                                            */
/*   9 / TARIDLSTA_vidCalc_idl_target_ext                                     */
/*   10 / TARIDLSTA_vidClc_Idl_tar_vac_pmp                                    */
/*                                                                            */
/* !Reference   : V02 NT 10 08533 / 02                                        */
/* !OtherRefs   : CSMT_CGMT06_2104 / 10.3                                     */
/* !OtherRefs   : VEMS V02 ECU#051848                                         */
/* !OtherRefs   : VEMS V02 ECU#059717                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TARIDLSTA/TARIDLS$*/
/* $Revision::   1.9      $$Author::   mbenfrad       $$Date::   11 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   11 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TARIDLSTA.h"
#include "TARIDLSTA_L.h"
#include "TARIDLSTA_IM.h"
#include "GDGAR.h"
#include "SWFAIL.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_ss                               */
/* !Description :  Fonction qui calcule TqSys_nTarIdlStgPmp: régime de ralenti*/
/*                 requis par la direction assistée (SS).                     */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_019.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_stStgPmpCf;                                               */
/*  input boolean TARIDLSTA_bTurnOffDlyStgPmp;                                */
/*  input boolean Stg_bStgPmpThdMes;                                          */
/*  input uint16 Stg_pStgPmpLnrMes;                                           */
/*  input uint8 TqSys_pThdTarIdlStgPmp_C;                                     */
/*  input boolean TqSys_bAcvTarIdlStgPmp_MP;                                  */
/*  input uint16 TqSys_tiAcvTarIdlStgPmp_C;                                   */
/*  input uint16 TARIDLSTA_u16StgPmpTrnOffDlyCntr;                            */
/*  input uint16 TqSys_nTarIdlStgPmp_C;                                       */
/*  input uint16 TqSys_nIncTarIdlStgPmp_C;                                    */
/*  input sint16 TqSys_nDecTarIdlStgPmp_C;                                    */
/*  input uint16 TqSys_nTarIdlStgPmp;                                         */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TARIDLSTA_bTurnOffDlyStgPmp;                               */
/*  output boolean TqSys_bAcvTarIdlStgPmp_MP;                                 */
/*  output uint16 TARIDLSTA_u16StgPmpTrnOffDlyCntr;                           */
/*  output uint16 TqSys_nTarIdlStgPmp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_ss(void)
{
   boolean bLocalTurnOffDlyStgPmpPrev;
   boolean bLocalAcvTarIdlStgPmpPrev;
   uint8   u8LocalExt_stStgPmpCf;
   uint16  u16LocalStg_pStgPmpLnrMes;
   uint16  u16LocalThdTarIdlStgPmp;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalSlewDec;


   /*TurnOffDelay*/
   VEMS_vidGET(Ext_stStgPmpCf, u8LocalExt_stStgPmpCf);

   bLocalTurnOffDlyStgPmpPrev = TARIDLSTA_bTurnOffDlyStgPmp;
   switch (u8LocalExt_stStgPmpCf)
   {
      case 1:
         VEMS_vidGET(Stg_bStgPmpThdMes, TARIDLSTA_bTurnOffDlyStgPmp);
         break;

      case 2:
         VEMS_vidGET(Stg_pStgPmpLnrMes, u16LocalStg_pStgPmpLnrMes);
         u16LocalThdTarIdlStgPmp = (uint16)(TqSys_pThdTarIdlStgPmp_C * 4);
         if (u16LocalStg_pStgPmpLnrMes >= u16LocalThdTarIdlStgPmp)
         {
            TARIDLSTA_bTurnOffDlyStgPmp = 1;
         }
         else
         {
            TARIDLSTA_bTurnOffDlyStgPmp = 0;
         }
         break;

      default:
         TARIDLSTA_bTurnOffDlyStgPmp = 0;
         break;
   }

   bLocalAcvTarIdlStgPmpPrev = TqSys_bAcvTarIdlStgPmp_MP;
   if (TARIDLSTA_bTurnOffDlyStgPmp != 0)
   {
      TqSys_bAcvTarIdlStgPmp_MP = 1 ;
   }
   else
   {
      if (bLocalTurnOffDlyStgPmpPrev != 0)
      {
         TARIDLSTA_u16StgPmpTrnOffDlyCntr = TqSys_tiAcvTarIdlStgPmp_C ;
      }
      else
      {
         if (TARIDLSTA_u16StgPmpTrnOffDlyCntr > 0)
         {
            TARIDLSTA_u16StgPmpTrnOffDlyCntr =
               (uint16)(TARIDLSTA_u16StgPmpTrnOffDlyCntr - 1);
         }
      }
      if (TARIDLSTA_u16StgPmpTrnOffDlyCntr == 0)
      {
         TqSys_bAcvTarIdlStgPmp_MP = 0 ;
      }
      else
      {
         TqSys_bAcvTarIdlStgPmp_MP = 1 ;
      }
   }

   /*Rate Limiter*/
   if (TqSys_bAcvTarIdlStgPmp_MP != 0)
   {
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(TqSys_nTarIdlStgPmp_C, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlStgPmpPrev != 0)
      || (TqSys_bAcvTarIdlStgPmp_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlStgPmp_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlStgPmp_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlStgPmp,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlStgPmp = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_AT                               */
/* !Description :  Cette sous-fonction fait la synthèse des consignes de      */
/*                 régime de ralenti spécifique à une boite de vitesse        */
/*                 automatique.                                               */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_027.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TARIDLSTA_vidCalc_spd_gbx_output();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_AT_bas();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_AT_inc();                      */
/*  extf argret void TARIDLSTA_vidFrze_Idl_tar_AT_eng();                      */
/*  extf argret void TARIDLSTA_vidCalc_Idl_tar_AT_Cun();                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 TqSys_nTarIdlATBas;                                          */
/*  input uint16 TqSys_nTarIdlATInc;                                          */
/*  input uint16 TqSys_nTarIdlATEgd;                                          */
/*  input uint16 TqSys_nTarIdlATReq;                                          */
/*  output uint16 TqSys_nTarIdlAT;                                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_AT(void)
{
   uint16 u16LocalVar;
   uint16 u16LocalTqSys_nTarIdlAT;


   /*F02_05_01_Calc_speed_gearbox_output*/
   TARIDLSTA_vidCalc_spd_gbx_output();

   /*F02_05_02_Calc_Idle_target_AT_base*/
   TARIDLSTA_vidCalc_Idl_tar_AT_bas();

   /*F02_05_03_Calc_Idle_target_AT_increased*/
   TARIDLSTA_vidCalc_Idl_tar_AT_inc();

   /*F02_05_04_Freeze_Idle_target_AT_engaged*/
   TARIDLSTA_vidFrze_Idl_tar_AT_eng();

   /*F02_05_05_Calc_Idle_target_AT_Cunsumtion*/
   TARIDLSTA_vidCalc_Idl_tar_AT_Cun();

   u16LocalVar = (uint16)MATHSRV_udtMAX(TqSys_nTarIdlATBas, TqSys_nTarIdlATInc);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlATEgd);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlATReq);
   u16LocalTqSys_nTarIdlAT = (uint16)MATHSRV_udtMIN(u16LocalVar, 32000);
   VEMS_vidSET(TqSys_nTarIdlAT, u16LocalTqSys_nTarIdlAT);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_spd_gbx_output                           */
/* !Description :  Dans ce bloc, on vient sélectionner l’information          */
/*                 nécessaire pour calculer le régime en sortie de boîte. Soit*/
/*                 à partir de l’information régime moyen roue avant          */
/*                 Ext_nAvrFrntWhlCAN, soit à partir de la vitesse véhicule   */
/*                 Veh_spdVeh.                                                */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqSys_nGBxDftTarIdl_C;                                       */
/*  input boolean Ext_bCf_nAvrFrntWhl;                                        */
/*  input uint16 Ext_nAvrFrntWhl;                                             */
/*  input uint16 TqSys_facFrntWhlGBxOut_C;                                    */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint16 TqSys_facSpdVehGBxOut_C;                                     */
/*  output uint16 TqSys_nGBxOut;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_spd_gbx_output(void)
{
   boolean bLocalAcvNGBxDftTarIdl;
   boolean bLocalExt_bCf_nAvrFrntWhl;
   uint16  u16LocalVeh_spdVeh;
   uint16  u16LocalExt_nAvrFrntWhl;
   uint32  u32LocalTqSys_nGBxOut;


   bLocalAcvNGBxDftTarIdl = GDGAR_bGetFRM(FRM_FRM_ACVNGBXDFTTARIDL);
   if (bLocalAcvNGBxDftTarIdl != 0)
   {
      u32LocalTqSys_nGBxOut = (uint32)(TqSys_nGBxDftTarIdl_C * 4);
   }
   else
   {
      VEMS_vidGET(Ext_bCf_nAvrFrntWhl, bLocalExt_bCf_nAvrFrntWhl);
      if (bLocalExt_bCf_nAvrFrntWhl != 0)
      {
         VEMS_vidGET(Ext_nAvrFrntWhl, u16LocalExt_nAvrFrntWhl);
         u32LocalTqSys_nGBxOut = ( ( ( u16LocalExt_nAvrFrntWhl
                                     * TqSys_facFrntWhlGBxOut_C)
                                   + 3125)
                                 / 6250);
      }
      else
      {
         VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
         u32LocalTqSys_nGBxOut = ( ( (uint32)( u16LocalVeh_spdVeh
                                             * TqSys_facSpdVehGBxOut_C)
                                   + 1600)
                                 / 3200);
      }
   }
   TqSys_nGBxOut = (uint16)MATHSRV_udtMIN(u32LocalTqSys_nGBxOut, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_AT_bas                           */
/* !Description :  La consigne minimale de ralenti BVA est déterminée en      */
/*                 fonction des conditions de la chaine de traction : si on   */
/*                 est à vide ou en entrainé, si le convertisseur de couple   */
/*                 est fermé ou ouvert, et suivant le régime de rotation de   */
/*                 l’arbre en sortie de boite.                                */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_020.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqSys_nGBxOutThdLo_C;                                        */
/*  input uint16 TqSys_nGBxOut;                                               */
/*  input uint16 TqSys_nGBxOutThdHi_C;                                        */
/*  input uint8 CoPt_stCnvCluFil;                                             */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean TqSys_bAcvTarIdlATBas_MP;                                   */
/*  input uint16 TqSys_nGBxOut_A[12];                                         */
/*  input boolean TARIDLSTA_bPosHysGBxOut;                                    */
/*  input uint16 TqSys_nTarIdlATBas1_M[8][12];                                */
/*  input uint16 TqSys_nTarIdlATBas2_M[8][12];                                */
/*  input uint16 TqSys_nIncTarIdlATBas_C;                                     */
/*  input sint16 TqSys_nDecTarIdlATBas_C;                                     */
/*  input uint16 TqSys_nTarIdlATBas;                                          */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TARIDLSTA_bPosHysGBxOut;                                   */
/*  output boolean TqSys_bAcvTarIdlATBas_MP;                                  */
/*  output uint16 TqSys_nTarIdlATBas;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_AT_bas(void)
{
   boolean bLocalAcvTarIdlATBasPrev;
   uint8   u8LocalCoPt_stCnvCluFil;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   uint32  u32LocalPosHysHigh;
   uint32  u32LocalPosHysLow;
   sint16  s16LocalSlewDec;


   /*PosHys*/
   u32LocalPosHysLow = (uint32)(TqSys_nGBxOutThdLo_C * 4);
   if (TqSys_nGBxOut <= u32LocalPosHysLow)
   {
      TARIDLSTA_bPosHysGBxOut = 0;
   }
   else
   {
      u32LocalPosHysHigh = (uint32)(TqSys_nGBxOutThdHi_C * 4);
      if (TqSys_nGBxOut >= u32LocalPosHysHigh)
      {
         TARIDLSTA_bPosHysGBxOut = 1;
      }
   }

   /*Rate Limiter*/
   VEMS_vidGET(CoPt_stCnvCluFil, u8LocalCoPt_stCnvCluFil);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   bLocalAcvTarIdlATBasPrev = TqSys_bAcvTarIdlATBas_MP;

   if (  (u8LocalCoPt_stCnvCluFil != 2)
      && (u8LocalCoPt_noEgdGearCord != 0))
   {
      TqSys_bAcvTarIdlATBas_MP = 1;

      u16LocalParaX = (uint16)MATHSRV_udtMIN(u8LocalCoPt_noEgdGearCord, 7);
      u16LocalParaX = (uint16)(u16LocalParaX * 256);

      u16LocalParaY = (uint16)(TqSys_nGBxOut / 4);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqSys_nGBxOut_A,
                                                   u16LocalParaY,
                                                   12);

      if (TARIDLSTA_bPosHysGBxOut == 0)
      {
         u16LocalSlewInput = MATHSRV_u16Interp2d(&TqSys_nTarIdlATBas1_M[0][0],
                                                 u16LocalParaX,
                                                 u16LocalParaY,
                                                 12);
      }
      else
      {
         u16LocalSlewInput = MATHSRV_u16Interp2d(&TqSys_nTarIdlATBas2_M[0][0],
                                                 u16LocalParaX,
                                                 u16LocalParaY,
                                                 12);
      }
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      TqSys_bAcvTarIdlATBas_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlATBasPrev != 0)
      || (TqSys_bAcvTarIdlATBas_MP == 0))
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlATBas_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlATBas_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlATBas,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlATBas = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_AT_inc                           */
/* !Description :  La consigne de régime de ralenti accélérée est activée sur */
/*                 une demande de la BVA.                                     */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_021.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean CoPt_bTarIdlInc;                                            */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean TqSys_bAcvTarIdlATInc_MP;                                   */
/*  input uint16 TqSys_nGBxOut;                                               */
/*  input uint16 TqSys_nGBxOut_A[12];                                         */
/*  input uint16 TqSys_nTarIdlATInc_M[8][12];                                 */
/*  input sint16 TqSys_nDecTarIdlATInc_C;                                     */
/*  input uint16 TqSys_nTarIdlATInc;                                          */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TqSys_bAcvTarIdlATInc_MP;                                  */
/*  output uint16 TqSys_nTarIdlATInc;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_AT_inc(void)
{
   boolean bLocalCoPt_bTarIdlInc;
   boolean bLocalAcvTarIdlATIncPrev;
   uint8   u8LocalCoPt_noEgdGearCord;
   uint16  u16LocalParaX;
   uint16  u16LocalParaY;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   sint16  s16LocalSlewDec;


   /*Rate Limiter*/
   VEMS_vidGET(CoPt_bTarIdlInc, bLocalCoPt_bTarIdlInc);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);
   bLocalAcvTarIdlATIncPrev = TqSys_bAcvTarIdlATInc_MP;

   if (  (bLocalCoPt_bTarIdlInc != 0)
      && (  (u8LocalCoPt_noEgdGearCord == 1)
         || (u8LocalCoPt_noEgdGearCord == 2)))
   {
      TqSys_bAcvTarIdlATInc_MP = 1;

      u16LocalParaX = (uint16)(u8LocalCoPt_noEgdGearCord * 256);
      u16LocalParaY = (uint16)(TqSys_nGBxOut / 4);
      u16LocalParaY = MATHSRV_u16CalcParaIncAryU16(TqSys_nGBxOut_A,
                                                   u16LocalParaY,
                                                   12);

      u16LocalSlewInput = MATHSRV_u16Interp2d(&TqSys_nTarIdlATInc_M[0][0],
                                              u16LocalParaX,
                                              u16LocalParaY,
                                              12);

      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
   }
   else
   {
      TqSys_bAcvTarIdlATInc_MP = 0;
      u16LocalSlewInput = 0;
   }

   if (  (bLocalAcvTarIdlATIncPrev != 0)
      || (TqSys_bAcvTarIdlATInc_MP == 0))
   {
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlATInc_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlATInc,
                                                 u16LocalSlewInput,
                                                 800,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlATInc = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidFrze_Idl_tar_AT_eng                           */
/* !Description :  Lorsque l’on détecte un engagement (c'est-à-dire           */
/*                 TqSys_bDragRed passe à 2), on fige la consigne de ralenti  */
/*                 de base à la dernière valeur calculée, pendant une durée   */
/*                 calibrable.                                                */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_022.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 CoPt_stDragRed;                                               */
/*  input boolean TARIDLSTA_bTurnOffDlyRisingEdge;                            */
/*  input uint8 TARIDLSTA_u8DragRedPrev;                                      */
/*  input uint16 TqSys_tiAcvTarIdlATEgd_C;                                    */
/*  input uint16 TARIDLSTA_u16ATEngTrnOffDlyCntr;                             */
/*  input boolean TqSys_bAcvTarIdlATEgd_MP;                                   */
/*  input uint16 TqSys_nTarIdlNorm;                                           */
/*  input sint16 TqSys_nDecTarIdlATEgd_C;                                     */
/*  input uint16 TqSys_nTarIdlATEgd;                                          */
/*  output boolean TARIDLSTA_bTurnOffDlyRisingEdge;                           */
/*  output boolean TqSys_bAcvTarIdlATEgd_MP;                                  */
/*  output uint16 TARIDLSTA_u16ATEngTrnOffDlyCntr;                            */
/*  output uint16 TqSys_nTarIdlATEgd;                                         */
/*  output uint8 TARIDLSTA_u8DragRedPrev;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidFrze_Idl_tar_AT_eng(void)
{
   boolean bLocalTurnOffDlyRisingEdgePrev;
   uint8   u8LocalCoPt_stDragRed;
   uint16  u16LocalSlewOutput;
   uint16  u16LocalSlewDec;
   sint16  s16LocalSlewDec;


   /*TurnOffDelay*/
   VEMS_vidGET(CoPt_stDragRed, u8LocalCoPt_stDragRed);
   bLocalTurnOffDlyRisingEdgePrev = TARIDLSTA_bTurnOffDlyRisingEdge;

   if (  (u8LocalCoPt_stDragRed == 2)
      && (TARIDLSTA_u8DragRedPrev != 2))
   {
      TARIDLSTA_bTurnOffDlyRisingEdge = 1;
   }
   else
   {
      TARIDLSTA_bTurnOffDlyRisingEdge = 0;
   }

   if (TARIDLSTA_bTurnOffDlyRisingEdge != 0)
   {
      TqSys_bAcvTarIdlATEgd_MP = 1 ;
   }
   else
   {
      if (bLocalTurnOffDlyRisingEdgePrev != 0)
      {
         TARIDLSTA_u16ATEngTrnOffDlyCntr = TqSys_tiAcvTarIdlATEgd_C ;
      }
      else
      {
         if (TARIDLSTA_u16ATEngTrnOffDlyCntr > 0)
         {
            TARIDLSTA_u16ATEngTrnOffDlyCntr =
               (uint16)(TARIDLSTA_u16ATEngTrnOffDlyCntr - 1);
         }
      }
      if (TARIDLSTA_u16ATEngTrnOffDlyCntr == 0)
      {
         TqSys_bAcvTarIdlATEgd_MP = 0 ;
      }
      else
      {
         TqSys_bAcvTarIdlATEgd_MP = 1 ;
      }
   }

   if (TqSys_bAcvTarIdlATEgd_MP != 0)
   {
      u16LocalSlewOutput = TqSys_nTarIdlNorm;
   }
   else
   {
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlATEgd_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlATEgd,
                                                 0,
                                                 800,
                                                 u16LocalSlewDec);
   }
   TqSys_nTarIdlATEgd = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
   TARIDLSTA_u8DragRedPrev = u8LocalCoPt_stDragRed;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar_AT_Cun                           */
/* !Description :  La fonction Demande de régime de consigne de ralenti BVA   */
/*                 détermine le besoin en consommation d'une boite de vitesse */
/*                 automatique en termes de régime de ralenti de consigne.    */
/*                 L’activation se fait via un seuil de vitesse et d’un       */
/*                 booléen calibrable.                                        */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_023.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input uint8 CoPt_noEgdGearCord;                                           */
/*  input boolean TqSys_bAcvNIdlATReq_C;                                      */
/*  input uint8 TqSys_spdVehThdAcvNIdlATReq_C;                                */
/*  input boolean TARIDLSTA_bATCunFlipFlopOut;                                */
/*  input uint8 TqSys_spdVehNIdlATReq_A[10];                                  */
/*  input uint16 TqSys_nIdlATReq_T[10];                                       */
/*  output boolean TARIDLSTA_bATCunFlipFlopOut;                               */
/*  output uint16 TqSys_nTarIdlATReq;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar_AT_Cun(void)
{
   uint16 u16LocalVeh_spdVeh;
   uint16 u16LocalSpdVehThd;
   uint16 u16LocalParaY;
   uint16 u16LocalInterp;
   uint8  u8LocalCoPt_noEgdGearCord;
   uint8  u8LocalVeh_spdVeh;


   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   VEMS_vidGET(CoPt_noEgdGearCord, u8LocalCoPt_noEgdGearCord);

   /*Bascule RS*/
   if (TqSys_bAcvNIdlATReq_C != 0)
   {
      TARIDLSTA_bATCunFlipFlopOut = 0;
   }
   else
   {
      u16LocalSpdVehThd = (uint16)(TqSys_spdVehThdAcvNIdlATReq_C * 64);
      if (u16LocalVeh_spdVeh >= u16LocalSpdVehThd)
      {
         TARIDLSTA_bATCunFlipFlopOut = 1;
      }
   }

   if (  (u8LocalCoPt_noEgdGearCord == 0)
      && (TARIDLSTA_bATCunFlipFlopOut != 0))
   {
      u16LocalVeh_spdVeh = (uint16)MATHSRV_udtMIN(u16LocalVeh_spdVeh, 15968);
      u8LocalVeh_spdVeh = (uint8)((u16LocalVeh_spdVeh + 32) / 64);

      u16LocalParaY = MATHSRV_u16CalcParaIncAryU8(TqSys_spdVehNIdlATReq_A,
                                                   u8LocalVeh_spdVeh,
                                                   10);

      u16LocalInterp = MATHSRV_u16Interp1d(&TqSys_nIdlATReq_T[0],
                                              u16LocalParaY);

      u16LocalInterp = (uint16)MATHSRV_udtMIN(u16LocalInterp, 8000);
      TqSys_nTarIdlATReq = (uint16)(u16LocalInterp * 4);
   }
   else
   {
      TqSys_nTarIdlATReq = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_Idl_tar                                  */
/* !Description :  Ce bloc calcule la consigne de régime de ralenti à partir  */
/*                 de tous les besoins moteurs, boite de vitesse, accessoires */
/*                 et safety.                                                 */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_024.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 CoPt_nTarIdl;                                                */
/*  input uint16 TqSys_nTarIdlCus;                                            */
/*  input uint16 TqSys_nTarIdlDft;                                            */
/*  input uint16 TqSys_nTarIdlEng;                                            */
/*  input uint16 TqSys_nTarIdlNorm;                                           */
/*  input boolean TqSys_bTqSysAcv;                                            */
/*  input uint16 TqSys_nIncMaxTarIdl_C;                                       */
/*  input sint16 TqSys_nDecMaxTarIdl_C;                                       */
/*  input uint16 TqSys_nTarIdlSfty;                                           */
/*  input uint16 TqSys_nTarIdlAT;                                             */
/*  input uint16 TqSys_nTarIdlGBxMin;                                         */
/*  input uint16 TqSys_nTarIdlGBxMax;                                         */
/*  input uint16 TqSys_nTarIdlMin_C;                                          */
/*  input uint16 TqSys_nTarIdlMax_C;                                          */
/*  output uint16 TqSys_nTarIdlSfty;                                          */
/*  output uint16 TqSys_nTarIdlFil;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_Idl_tar(void)
{
   boolean bLocalTqSys_bTqSysAcv;
   uint16  u16LocalCoPt_nTarIdl;
   uint16  u16LocalVar;
   uint16  u16LocalVarmax;
   uint16  u16LocalTqSys_nTarIdlAT;
   uint16  u16LocalSlewOutput;
   uint16  u16LocalTqSys_nTarIdlGBxMin;
   uint16  u16LocalTqSys_nTarIdlGBxMax;
   uint16  u16LocalTqSys_nTarIdlFil;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewInput;
   sint16  s16LocalSlewDec;
   uint32  u32LocalSatMin;
   uint32  u32LocalSatMax;


   VEMS_vidGET(CoPt_nTarIdl, u16LocalCoPt_nTarIdl);
   u16LocalVar = (uint16)MATHSRV_udtMAX(TqSys_nTarIdlCus, u16LocalCoPt_nTarIdl);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlDft);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlEng);
   u16LocalVar = (uint16)MATHSRV_udtMAX(u16LocalVar, TqSys_nTarIdlNorm);
   u16LocalSlewInput = u16LocalVar;


   /*ratelimiter*/
   VEMS_vidGET(TqSys_bTqSysAcv, bLocalTqSys_bTqSysAcv);
   if (bLocalTqSys_bTqSysAcv != 0)
   {
      u16LocalSlewInc = (uint16)((TqSys_nIncMaxTarIdl_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecMaxTarIdl_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      VEMS_vidGET(TqSys_nTarIdlSfty, u16LocalSlewOutput);
      u16LocalSlewOutput = MATHSRV_u16SlewFilter(u16LocalSlewOutput,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = u16LocalSlewInput;
   }

   u16LocalSlewOutput = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
   VEMS_vidSET(TqSys_nTarIdlSfty, u16LocalSlewOutput);
   VEMS_vidGET(TqSys_nTarIdlAT, u16LocalTqSys_nTarIdlAT);
   u16LocalVarmax = (uint16)MATHSRV_udtMAX(u16LocalTqSys_nTarIdlAT,
                                           u16LocalSlewOutput);

   /*1st Saturation*/
   VEMS_vidGET(TqSys_nTarIdlGBxMin, u16LocalTqSys_nTarIdlGBxMin);
   VEMS_vidGET(TqSys_nTarIdlGBxMax, u16LocalTqSys_nTarIdlGBxMax);
   u16LocalVarmax = (uint16)MATHSRV_udtCLAMP(u16LocalVarmax,
                                             u16LocalTqSys_nTarIdlGBxMin,
                                             u16LocalTqSys_nTarIdlGBxMax);

   /*2nd Saturation*/
   u32LocalSatMin = TqSys_nTarIdlMin_C * 4;
   u32LocalSatMax = TqSys_nTarIdlMax_C * 4;
   u16LocalTqSys_nTarIdlFil = (uint16)MATHSRV_udtCLAMP(u16LocalVarmax,
                                                       u32LocalSatMin,
                                                       u32LocalSatMax);

   u16LocalTqSys_nTarIdlFil = (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlFil,
                                                     32000);
   VEMS_vidSET(TqSys_nTarIdlFil, u16LocalTqSys_nTarIdlFil);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidCalc_idl_target_ext                           */
/* !Description :  La consigne de ralenti finale est la consigne de ralenti   */
/*                 calculée précédemment ou bien une consigne issue d’une     */
/*                 fonction externe.                                          */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_025.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void SWFAIL_vidSoftwareErrorHook();                           */
/*  input boolean TqSys_bTqSysAcv;                                            */
/*  input boolean TARIDLSTA_bIdlTarExtRisingEdge;                             */
/*  input uint16 TqSys_nTarIdl;                                               */
/*  input boolean TqSys_bIniNTarIdlStrt_C;                                    */
/*  input uint16 TqSys_nTarIdlStrt;                                           */
/*  input uint8 Afts_stBypTarIdl;                                             */
/*  input sint16 Afts_nBypTarIdl;                                             */
/*  input uint16 TqSys_nTarIdlFil;                                            */
/*  input uint16 TqSys_nTarIdlCVCReq;                                         */
/*  input uint8 CoPTSt_stEng;                                                 */
/*  input uint32 EOM_tiEngRun;                                                */
/*  input uint16 TqSys_tiStrtDlyTarIdlTakeOff_C;                              */
/*  input uint16 TqSys_nOfsTotTakeOff;                                        */
/*  input boolean Afts_bAcvHybMod_nTarIdl;                                    */
/*  input uint16 Afts_nTarIdlHybMod;                                          */
/*  input boolean Afts_bAcvVlvActTest_nTarIdl;                                */
/*  input uint16 Afts_nTarIdlVlvActTest;                                      */
/*  input boolean AirMon_bEnaIdlCtlAftsDiag;                                  */
/*  input uint16 AirMon_nEngAftsDiag;                                         */
/*  input boolean FEI_bAcvNEngFEIAftsByp;                                     */
/*  input uint16 FEI_nEngFEIAftsReq;                                          */
/*  input boolean NORIA_bNEngAftsReq;                                         */
/*  input uint16 NORIA_nEngAftsSp;                                            */
/*  input boolean PFlt_bAcvNTarIdlRgnAfts;                                    */
/*  input uint16 PFlt_nTarIdlRgnAftsReq;                                      */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output uint16 TqSys_nTarIdlPrev;                                          */
/*  output boolean TARIDLSTA_bIdlTarExtRisingEdge;                            */
/*  output uint16 TqSys_nTarIdl;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidCalc_idl_target_ext(void)
{
   boolean bLocalTqSys_bTqSysAcv;
   boolean blocalRisingEdgePrev;
   boolean bLocalAfts_bAcvHybMod_nTarIdl;
   boolean bLocalAfts_bAcvVlvActTest_TarIdl;
   boolean bLocalAirMon_bEnaIdlCtlAftsDiag;
   boolean bLocalFEI_bAcvNEngFEIAftsByp;
   boolean bLocalPFlt_bAcvNTarIdlRgnAfts;
   boolean bLocalNORIA_bNEngAftsReq;
   boolean bLocalTest;
   uint8   u8LocalCoPTSt_stEng;
   uint8   u8LocalAfts_stBypTarIdl;
   uint16  u16LocalTqSys_nTarIdlStrt;
   uint16  u16LocalAfts_nTarIdlHybMod;
   uint16  u16LocalAfts_nTarIdlVlvActTest;
   uint16  u16LocalAirMon_nEngAftsDiag;
   uint16  u16LocalFEI_nEngFEIAftsReq;
   uint16  u16LocalPFlt_nTarIdlRgnAftsReq;
   uint16  u16LocalTqSys_nTarIdlFil;
   uint16  u16LocalTqSys_nTarIdlCVCR;
   uint16  u16LocalTqSys_nOfsTotTakeOff;
   uint16  u16LocalTqSys_nTarIdl;
   uint16  u16LocalNORIA_nEngAftsSp;
   sint16  s16LocalAfts_nBypTarIdl;
   uint32  u32LocalSwitchOut;
   uint32  u32LocalEOM_tiEngRun;
   sint32  s32LocalTqSys_nTarIdl;


   bLocalTest = 0;
   VEMS_vidGET(TqSys_bTqSysAcv, bLocalTqSys_bTqSysAcv);
   blocalRisingEdgePrev = TARIDLSTA_bIdlTarExtRisingEdge;
   VEMS_vidGET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   TqSys_nTarIdlPrev = (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdl, 32000);

   if (  (bLocalTqSys_bTqSysAcv != 0)
      && (TqSys_bIniNTarIdlStrt_C != 0))
   {
      TARIDLSTA_bIdlTarExtRisingEdge = 1;
   }
   else
   {
      TARIDLSTA_bIdlTarExtRisingEdge = 0;
   }

   if (  (blocalRisingEdgePrev == 0)
      && (TARIDLSTA_bIdlTarExtRisingEdge != 0))
   {
      VEMS_vidGET(TqSys_nTarIdlStrt, u16LocalTqSys_nTarIdlStrt);
      u16LocalTqSys_nTarIdlStrt =
         (uint16)MATHSRV_udtMIN(u16LocalTqSys_nTarIdlStrt, 8000);
      u16LocalTqSys_nTarIdl = (uint16)(u16LocalTqSys_nTarIdlStrt * 4);
      VEMS_vidSET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
   }
   else
   {
      VEMS_vidGET(Afts_stBypTarIdl, u8LocalAfts_stBypTarIdl);
      VEMS_vidGET(Afts_nBypTarIdl, s16LocalAfts_nBypTarIdl);
      switch (u8LocalAfts_stBypTarIdl)
      {
         case 0:
         case 2:
            VEMS_vidGET(TqSys_nTarIdlFil, u16LocalTqSys_nTarIdlFil);
            VEMS_vidGET(TqSys_nTarIdlCVCReq, u16LocalTqSys_nTarIdlCVCR);
            VEMS_vidGET(CoPTSt_stEng, u8LocalCoPTSt_stEng);
            VEMS_vidGET(EOM_tiEngRun, u32LocalEOM_tiEngRun);

            u32LocalSwitchOut =
               (uint32)MATHSRV_udtMAX(u16LocalTqSys_nTarIdlFil,
                                      u16LocalTqSys_nTarIdlCVCR);

            u32LocalEOM_tiEngRun = MATHSRV_udtMIN(u32LocalEOM_tiEngRun, 656);
            u32LocalEOM_tiEngRun = u32LocalEOM_tiEngRun * 100;

            if (  (u8LocalCoPTSt_stEng == 5)
               && ( u32LocalEOM_tiEngRun > TqSys_tiStrtDlyTarIdlTakeOff_C))
            {
               VEMS_vidGET(TqSys_nOfsTotTakeOff, u16LocalTqSys_nOfsTotTakeOff);
               u32LocalSwitchOut = ( u32LocalSwitchOut
                                   + u16LocalTqSys_nOfsTotTakeOff);
            }

            VEMS_vidGET(Afts_bAcvHybMod_nTarIdl, bLocalAfts_bAcvHybMod_nTarIdl);
            if (bLocalAfts_bAcvHybMod_nTarIdl != 0)
            {
               VEMS_vidGET(Afts_nTarIdlHybMod, u16LocalAfts_nTarIdlHybMod);
               u32LocalSwitchOut = (uint32)(u16LocalAfts_nTarIdlHybMod * 4);
            }
            else
            {
               VEMS_vidGET(Afts_bAcvVlvActTest_nTarIdl,
                           bLocalAfts_bAcvVlvActTest_TarIdl);
               if (bLocalAfts_bAcvVlvActTest_TarIdl != 0)
               {
                  VEMS_vidGET(Afts_nTarIdlVlvActTest,
                              u16LocalAfts_nTarIdlVlvActTest);
                  u32LocalSwitchOut =
                     (uint32)(u16LocalAfts_nTarIdlVlvActTest * 4);
               }
               else
               {
                  VEMS_vidGET(AirMon_bEnaIdlCtlAftsDiag,
                              bLocalAirMon_bEnaIdlCtlAftsDiag);
                  if (bLocalAirMon_bEnaIdlCtlAftsDiag != 0)
                  {
                     VEMS_vidGET(AirMon_nEngAftsDiag,
                                 u16LocalAirMon_nEngAftsDiag);
                     u32LocalSwitchOut = u16LocalAirMon_nEngAftsDiag * 4;
                  }
                  else
                  {
                     VEMS_vidGET(FEI_bAcvNEngFEIAftsByp,
                                 bLocalFEI_bAcvNEngFEIAftsByp);
                     if (bLocalFEI_bAcvNEngFEIAftsByp != 0)
                     {
                        VEMS_vidGET(FEI_nEngFEIAftsReq,
                                    u16LocalFEI_nEngFEIAftsReq);
                        u32LocalSwitchOut = u16LocalFEI_nEngFEIAftsReq * 4;
                     }
                     else
                     {
                        bLocalTest = 1;
                     }
                  }
               }
            }
            if (bLocalTest != 0)
            {
               VEMS_vidGET(NORIA_bNEngAftsReq, bLocalNORIA_bNEngAftsReq);
               if (bLocalNORIA_bNEngAftsReq != 0)
               {
                  VEMS_vidGET(NORIA_nEngAftsSp, u16LocalNORIA_nEngAftsSp);
                  u32LocalSwitchOut = u16LocalNORIA_nEngAftsSp * 2;
               }
               else
               {
                  VEMS_vidGET(PFlt_bAcvNTarIdlRgnAfts,
                              bLocalPFlt_bAcvNTarIdlRgnAfts);
                  if (bLocalPFlt_bAcvNTarIdlRgnAfts != 0)
                  {
                     VEMS_vidGET(PFlt_nTarIdlRgnAftsReq,
                                 u16LocalPFlt_nTarIdlRgnAftsReq);
                     u32LocalSwitchOut = u16LocalPFlt_nTarIdlRgnAftsReq;
                  }
               }
            }

         if (u8LocalAfts_stBypTarIdl == 0)
         {
            s32LocalTqSys_nTarIdl = (sint32)u32LocalSwitchOut;
         }
         else
         {
            s32LocalTqSys_nTarIdl = ( (sint32)u32LocalSwitchOut
                                    + s16LocalAfts_nBypTarIdl);
         }
         u16LocalTqSys_nTarIdl =
            (uint16)MATHSRV_udtCLAMP(s32LocalTqSys_nTarIdl, 0, 32000);
         VEMS_vidSET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
            break;

         case 1:
               u16LocalTqSys_nTarIdl =
                  (uint16)MATHSRV_udtCLAMP(s16LocalAfts_nBypTarIdl, 0, 32000);
               VEMS_vidSET(TqSys_nTarIdl, u16LocalTqSys_nTarIdl);
            break;

         default:
            VEMS_vidSET(TqSys_nTarIdl, TqSys_nTarIdlPrev);
            SWFAIL_vidSoftwareErrorHook();
            break;
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TARIDLSTA_vidClc_Idl_tar_vac_pmp                           */
/* !Description :  Dans ce Bloc, TqSys_nTarIdlVacPmp est un régime de ralenti */
/*                 qui est demandé lorsque la pression mastervac est trop     */
/*                 faible pour assurer un freinage afin d’éviter des          */
/*                 phénomènes d’oscillations de la consigne de ralenti.       */
/* !Number      :  FCT3.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_R_10_08533_026.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input boolean TARIDLSTA_bEnableRateLimiter;                               */
/*  input uint16 Ext_pAirExtMes;                                              */
/*  input uint8 TqSys_facPAirTarIdlVacPmp_C;                                  */
/*  input uint8 TqSys_pAirOfsTarIdlVacPmp_C;                                  */
/*  input uint8 TqSys_spdVehTarIdlVacPmp_C;                                   */
/*  input uint16 Ext_pBrkAsi;                                                 */
/*  input uint16 Veh_spdVeh;                                                  */
/*  input boolean TqSys_bAcvTarIdlVacPmp_MP;                                  */
/*  input uint16 TqSys_nTarIdlVacPmpDft_C;                                    */
/*  input uint16 TqSys_nTarIdlVacPmp_C;                                       */
/*  input uint16 TqSys_nIncTarIdlVacPmp_C;                                    */
/*  input sint16 TqSys_nDecTarIdlVacPmp_C;                                    */
/*  input uint16 TqSys_nTarIdlVacPmp;                                         */
/*  input uint16 TqSys_nTarIdlPrev;                                           */
/*  output boolean TqSys_bAcvTarIdlVacPmp_MP;                                 */
/*  output boolean TARIDLSTA_bEnableRateLimiter;                              */
/*  output uint16 TqSys_nTarIdlVacPmp;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TARIDLSTA_vidClc_Idl_tar_vac_pmp(void)
{
   boolean bLocalAcvTarIdlVacPmpDft;
   boolean bLocalEnablerateLimiterPrev;
   uint16  u16LocalExt_pBrkAsi;
   uint16  u16LocalExt_pAirExtMes;
   uint16  u16LocalSlewInput;
   uint16  u16LocalSlewInc;
   uint16  u16LocalSlewDec;
   uint16  u16LocalSlewOutput;
   uint16  u16Localcalc3;
   uint16  u16LocalVeh_spdVeh;
   sint16  s16LocalSlewDec;
   uint32  u32Localcalc1;
   uint32  u32Localcalc4;
   sint32  s32Localcalc2;


   bLocalEnablerateLimiterPrev = TARIDLSTA_bEnableRateLimiter;
   /*Bascule RS*/
   VEMS_vidGET(Ext_pAirExtMes, u16LocalExt_pAirExtMes);
   u32Localcalc1 = TqSys_facPAirTarIdlVacPmp_C * u16LocalExt_pAirExtMes;
   s32Localcalc2 = (sint32)( u32Localcalc1
                           - (uint32)(200 * TqSys_pAirOfsTarIdlVacPmp_C));
   u16Localcalc3 = (uint16)(TqSys_spdVehTarIdlVacPmp_C * 64);
   VEMS_vidGET(Ext_pBrkAsi, u16LocalExt_pBrkAsi);
   u32Localcalc4 = (uint32)(u16LocalExt_pBrkAsi * 200);
   VEMS_vidGET(Veh_spdVeh, u16LocalVeh_spdVeh);
   if (  (u16LocalVeh_spdVeh >= u16Localcalc3)
      && (s32Localcalc2 > (sint32)u32Localcalc4))
   {
      TqSys_bAcvTarIdlVacPmp_MP = 0;
   }
   else
   {
      if (u32Localcalc1 < u32Localcalc4)
      {
         TqSys_bAcvTarIdlVacPmp_MP = 1;
      }
   }

   /*Rate limiter*/
   bLocalAcvTarIdlVacPmpDft = GDGAR_bGetFRM(FRM_FRM_ACVTARIDLVACPMPDFT);
   if (  (bLocalAcvTarIdlVacPmpDft != 0)
      || (TqSys_bAcvTarIdlVacPmp_MP != 0))
   {
      TARIDLSTA_bEnableRateLimiter = 1;
   }
   else
   {
      TARIDLSTA_bEnableRateLimiter = 0;
   }

   if (  (bLocalEnablerateLimiterPrev != 0)
      || (TARIDLSTA_bEnableRateLimiter == 0))
   {
      if (bLocalAcvTarIdlVacPmpDft != 0)
      {
         u16LocalSlewInput = TqSys_nTarIdlVacPmpDft_C;
      }
      else
      {
         if (TqSys_bAcvTarIdlVacPmp_MP != 0)
         {
            u16LocalSlewInput = TqSys_nTarIdlVacPmp_C;
         }
         else
         {
            u16LocalSlewInput = 0;
         }
      }
      u16LocalSlewInput = (uint16)MATHSRV_udtMIN(u16LocalSlewInput, 8000);
      u16LocalSlewInput = (uint16)(u16LocalSlewInput * 4);
      u16LocalSlewInc = (uint16)((TqSys_nIncTarIdlVacPmp_C + 12) / 25);
      s16LocalSlewDec = (sint16)MATHSRV_udtMIN(TqSys_nDecTarIdlVacPmp_C, 0);
      u16LocalSlewDec = (uint16)((((-1) * s16LocalSlewDec) + 12) / 25);

      u16LocalSlewOutput = MATHSRV_u16SlewFilter(TqSys_nTarIdlVacPmp,
                                                 u16LocalSlewInput,
                                                 u16LocalSlewInc,
                                                 u16LocalSlewDec);
   }
   else
   {
      u16LocalSlewOutput = TqSys_nTarIdlPrev;
   }
   TqSys_nTarIdlVacPmp = (uint16)MATHSRV_udtMIN(u16LocalSlewOutput, 32000);
}
/*-------------------------------- End of file -------------------------------*/
