/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : TQACRES                                                 */
/* !Description     : TQACRES Component                                       */
/*                                                                            */
/* !Module          : TQACRES                                                 */
/* !Description     : Réserve de couple climatisation                         */
/*                                                                            */
/* !File            : TQACRES_FCT1.C                                          */
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
/*   1 / TQACRES_vidInitOutput                                                */
/*   2 / TQACRES_vidReserveCoupleClim                                         */
/*   3 / TQACRES_vidAC3                                                       */
/*   4 / TQACRES_vidCondition_reserve_AC3                                     */
/*   5 / TQACRES_vidValeur_reserve_AC3                                        */
/*   6 / TQACRES_vidAC4                                                       */
/*   7 / TQACRES_vidValeur_reserve_AC4                                        */
/*   8 / TQACRES_vidGestion_Type_Clim                                         */
/*   9 / TQACRES_vidPriorite_Fan                                              */
/*   10 / TQACRES_vidCalcul_Reserve                                           */
/*                                                                            */
/* !Reference   : V02 NT 10 04980 / 02                                        */
/* !OtherRefs   : CSMT_CGMT08_0181 / 2.3                                      */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   I:/PROJETS/LIBPSA/LOG/REF/MOD_VEMS/TqStruct/TQACRES/TQACRES_F$*/
/* $Revision::   1.8      $$Author::   mbenfrad       $$Date::   07 Jun 2013 $*/
/* $Author::   mbenfrad                               $$Date::   07 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "TQACRES.h"
#include "TQACRES_L.h"
#include "TQACRES_IM.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidInitOutput                                      */
/* !Description :  Initialisation des sorties au Reset                        */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.HIDRI                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  output uint16 TqRes_tqACRes;                                              */
/*  output boolean TqRes_bDftACSwtOn;                                         */
/*  output boolean TqRes_bFrzAC;                                              */
/*  output uint16 TqRes_tqACResSat_MP;                                        */
/*  output boolean TqRes_bCdnAC3CluAuth_MP;                                   */
/*  output uint16 TQACRES_u16tiResAC3;                                        */
/*  output boolean TQACRES_bTqRes_bCdnACRes_Prev;                             */
/*  output boolean Ext_bACCluAuth_prev;                                       */
/*  output st18 TQACRES_StActual_Status;                                      */
/*  output uint16 TqRes_tiCplAC4Res_MP;                                       */
/*  output uint16 TqRes_tiAcvAC4Res_MP;                                       */
/*  output boolean TqRes_bAcvOptmTqACRes;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidInitOutput(void)
{
   uint16 u16LocalTqRes_tqIdlRes;


   /* Outputs initialization */
   VEMS_vidSET(TqRes_tqACRes, 0);
   VEMS_vidSET(TqRes_bDftACSwtOn, 0);
   VEMS_vidSET(TqRes_bFrzAC, 0);

   /* Slew rate output initialization */
   VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
   TqRes_tqACResSat_MP = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqIdlRes, 1600);

   /* Turn_On_Delay output initilaization */
   TqRes_bCdnAC3CluAuth_MP = 0;
   TQACRES_u16tiResAC3 = 0;

   /* Previous values initialization */
   TQACRES_bTqRes_bCdnACRes_Prev = 0;
   Ext_bACCluAuth_prev = 0;

   /* State Machine output's initialization */
   TQACRES_StActual_Status = HORS_RESERVE;
   TqRes_tiCplAC4Res_MP = 0;
   TqRes_tiAcvAC4Res_MP = 0;

   /* HysPos output initialization */
   TqRes_bAcvOptmTqACRes = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidReserveCoupleClim                               */
/* !Description :  La fonction traite trois types de climatisation : clim 3,  */
/*                 clim 4 et clim 5.  La fonction est activée que si une      */
/*                 climatisation est présente sur le véhicule.                */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_001.02                                     */
/*                 VEMS_R_10_04980_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void TQACRES_vidAC3();                                        */
/*  extf argret void TQACRES_vidAC4();                                        */
/*  extf argret void TQACRES_vidGestion_Type_Clim();                          */
/*  extf argret void TQACRES_vidPriorite_Fan();                               */
/*  extf argret void TQACRES_vidCalcul_Reserve();                             */
/*  input uint8 Ext_stACTypCf;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidReserveCoupleClim(void)
{
   uint8 u8LocalExt_stACTypCf;


   VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);

   if (u8LocalExt_stACTypCf != 0)
   {
      TQACRES_vidAC3();
      TQACRES_vidAC4();
      TQACRES_vidGestion_Type_Clim();
      TQACRES_vidPriorite_Fan();
      TQACRES_vidCalcul_Reserve();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidAC3                                             */
/* !Description :  Fonction traitant la climatisation de type 3.              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_08_07510_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidCondition_reserve_AC3();                      */
/*  extf argret void TQACRES_vidValeur_reserve_AC3();                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidAC3(void)
{
   TQACRES_vidCondition_reserve_AC3();
   TQACRES_vidValeur_reserve_AC3();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidCondition_reserve_AC3                           */
/* !Description :  La condition Clim 3 est active si Ext_bACCluDem = 1 et     */
/*                 l’embrayage climatisation est non actif. Elle se désactive */
/*                 après une temporisation calibrable si l’embrayage          */
/*                 climatisation est actif, ou si Ext_bACCluDem = 1.          */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Ext_bACCluAuth;                                             */
/*  input boolean Ext_bACCluAuth_prev;                                        */
/*  input uint8 TqRes_tiAC3Res_C;                                             */
/*  input uint16 TQACRES_u16tiResAC3;                                         */
/*  input boolean AC_bACCluDem;                                               */
/*  input boolean TqRes_bCdnAC3CluAuth_MP;                                    */
/*  output uint16 TQACRES_u16tiResAC3;                                        */
/*  output boolean TqRes_bCdnAC3CluAuth_MP;                                   */
/*  output boolean Ext_bACCluAuth_prev;                                       */
/*  output boolean TqRes_bCdnAC3Res;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidCondition_reserve_AC3(void)
{
   boolean bLocal_Ext_bACCluAuth;
   boolean bLocal_AC_bACCluDem;


   VEMS_vidGET(Ext_bACCluAuth, bLocal_Ext_bACCluAuth);
   if (bLocal_Ext_bACCluAuth != 0)
   {
      if (Ext_bACCluAuth_prev == 0)
      {
         TQACRES_u16tiResAC3 = (uint16)(((TqRes_tiAC3Res_C * 25) + 2) / 4);
      }
      else
      {
         if (TQACRES_u16tiResAC3 > 0)
         {
            TQACRES_u16tiResAC3 = (uint16)(TQACRES_u16tiResAC3 - 1);
         }

      }
      if (TQACRES_u16tiResAC3 == 0)
      {
         TqRes_bCdnAC3CluAuth_MP = 1;
      }
      else
      {
         TqRes_bCdnAC3CluAuth_MP = 0;
      }
   }
   else
   {
      TqRes_bCdnAC3CluAuth_MP = 0;
   }

   Ext_bACCluAuth_prev = bLocal_Ext_bACCluAuth;

   VEMS_vidGET(AC_bACCluDem,bLocal_AC_bACCluDem);

   if ( (bLocal_AC_bACCluDem != 0)
      &&(TqRes_bCdnAC3CluAuth_MP == 0))
   {
      TqRes_bCdnAC3Res = 1;
   }
   else
   {
      TqRes_bCdnAC3Res = 0;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidValeur_reserve_AC3                              */
/* !Description :  La réserve de couple Clim 3, varie en fonction de la       */
/*                 pression demandée par le compresseur de climatisation dans */
/*                 une table calibrable.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Ext_pAC;                                                     */
/*  input uint8 TqRes_pAC_A[8];                                               */
/*  input uint16 TqRes_tqAC3Res_T[8];                                         */
/*  output uint16 TqRes_tqAC3Res;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidValeur_reserve_AC3(void)
{
   uint8  u8LocalBkptInput;
   uint16 u16LocalExt_pAC;
   uint16 u16LocalCalcPara;
   uint16 u16LocalTqRes_tqAC3Res;


   VEMS_vidGET(Ext_pAC, u16LocalExt_pAC);
   u16LocalExt_pAC = (uint16)(u16LocalExt_pAC / 125);
   u8LocalBkptInput = (uint8)MATHSRV_udtMIN(u16LocalExt_pAC, 255);
   u16LocalCalcPara =
      MATHSRV_u16CalcParaIncAryU8(TqRes_pAC_A, u8LocalBkptInput, 8);
   u16LocalTqRes_tqAC3Res =
      MATHSRV_u16Interp1d(TqRes_tqAC3Res_T, u16LocalCalcPara);
   TqRes_tqAC3Res = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqAC3Res, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidAC4                                             */
/* !Description :  Fonction traitant la climatisation de type 4               */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void TQACRES_vidCondition_reserve_AC4();                      */
/*  extf argret void TQACRES_vidValeur_reserve_AC4();                         */
/*  input uint8 TqRes_tiAC4Res_C;                                             */
/*  input uint8 TqRes_tiAC4ResTmpMax_C;                                       */
/*  output uint16 TqRes_tiAC4Res;                                             */
/*  output uint16 TqRes_tiAC4ResTmpMax;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidAC4(void)
{
   uint16 u16LocalTqRes_tiAC4Res;
   uint16 u16LocalTqRes_tiAC4ResTmpMax;


   u16LocalTqRes_tiAC4Res = (uint16)(((TqRes_tiAC4Res_C * 25) + 2) / 4);
   TqRes_tiAC4Res = (uint16)MATHSRV_udtMIN(u16LocalTqRes_tiAC4Res, 1500);

   u16LocalTqRes_tiAC4ResTmpMax = (uint16)( ( (TqRes_tiAC4ResTmpMax_C * 25)
                                              + 2)
                                          / 4);
   TqRes_tiAC4ResTmpMax =
      (uint16)MATHSRV_udtMIN(u16LocalTqRes_tiAC4ResTmpMax, 1500);

   TQACRES_vidCondition_reserve_AC4();
   TQACRES_vidValeur_reserve_AC4();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidValeur_reserve_AC4                              */
/* !Description :  La réserve de couple Clim 4 varie en fonction d’une table  */
/*                 de couple calibrables issue du calcul suivant : Couple =   */
/*                 30/pi*AC_pwrAC/Eng_nCkFil                                  */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_008.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input uint8 AC_pwrAC;                                                     */
/*  input uint8 TqRes_pwrACSftyACRes_C;                                       */
/*  input uint16 TqRes_tqAC4Res_A[8];                                         */
/*  input uint16 TqRes_tqAC4Raw_MP;                                           */
/*  input uint16 TqRes_tqAC4Res_T[8];                                         */
/*  output uint16 TqRes_tqAC4Raw_MP;                                          */
/*  output uint16 TqRes_tqAC4Res;                                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidValeur_reserve_AC4(void)
{
   uint8  u8Local_AC_pwrAC;
   uint8  u8LocalNum;
   uint16 u16LocalDen;
   uint16 u16Local_Eng_nCkFil;
   uint16 u16Local_CalcPara;
   uint16 u16Local_Interp;
   uint32 u32Local_tqAC4Res_MP;


   VEMS_vidGET(Eng_nCkFil, u16Local_Eng_nCkFil);
   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);

   u8LocalNum = (uint8)MATHSRV_udtMAX(u8Local_AC_pwrAC, TqRes_pwrACSftyACRes_C);
   u16LocalDen = (uint16)MATHSRV_udtMAX(u16Local_Eng_nCkFil, 1200);
   /* pi = 355/113 */
   u32Local_tqAC4Res_MP = (uint32)(u8LocalNum * 5424000)
                       / (uint32)(u16LocalDen * 355);
   TqRes_tqAC4Raw_MP = (uint16)u32Local_tqAC4Res_MP;

   u16Local_CalcPara =
   MATHSRV_u16CalcParaIncAryU16(TqRes_tqAC4Res_A, TqRes_tqAC4Raw_MP, 8);

   u16Local_Interp = MATHSRV_u16Interp1d(TqRes_tqAC4Res_T, u16Local_CalcPara);
   TqRes_tqAC4Res = (uint16)MATHSRV_udtMIN(u16Local_Interp, 1600);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidGestion_Type_Clim                               */
/* !Description :  La fonction gestion type clim est prévue pour trois types  */
/*                 de clim : clim 3, clim 4 et clim 5. En cas d’absence de    */
/*                 clim la condition clim et réserve de couple clim sont      */
/*                 forcés à la valeur nulle.                                  */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_009.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stACTypCf;                                                */
/*  input boolean TqRes_bCdnAC3Res;                                           */
/*  input uint16 TqRes_tqAC3Res;                                              */
/*  input boolean TqRes_bCdnAC4Res;                                           */
/*  input uint16 TqRes_tqAC4Res;                                              */
/*  input boolean TqRes_bDftAC4SwtOn;                                         */
/*  input boolean TqRes_bCdnAC5Res;                                           */
/*  input uint16 TqRes_tqAC5Res;                                              */
/*  output boolean TqRes_bCdnACRes;                                           */
/*  output uint16 TqRes_tqACResRaw;                                           */
/*  output boolean TqRes_bDftACSwtOn;                                         */
/*  output boolean TqRes_bDftAC4SwtOn;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidGestion_Type_Clim(void)
{
   boolean bLocalTqRes_bCdnAC5Res;
   uint8   u8LocalExt_stACTypCf;
   uint16  u16LocalTqRes_tqAC5Res;


   VEMS_vidGET(Ext_stACTypCf, u8LocalExt_stACTypCf);
   u8LocalExt_stACTypCf = (uint8)MATHSRV_udtMIN(u8LocalExt_stACTypCf, 4);

   switch (u8LocalExt_stACTypCf)
   {
      case 0:
         TqRes_bCdnACRes = 0;
         TqRes_tqACResRaw = 0;
         VEMS_vidSET(TqRes_bDftACSwtOn, 0);
      break;

      case 1:
         TqRes_bCdnACRes = TqRes_bCdnAC3Res;
         TqRes_tqACResRaw = (uint16)MATHSRV_udtMIN(TqRes_tqAC3Res, 1600);
         VEMS_vidSET(TqRes_bDftACSwtOn, 0);
      break;

      case 2:
         TqRes_bCdnACRes = TqRes_bCdnAC4Res;
         TqRes_tqACResRaw = (uint16)MATHSRV_udtMIN(TqRes_tqAC4Res, 1600);
         VEMS_vidSET(TqRes_bDftACSwtOn, TqRes_bDftAC4SwtOn);
      break;

      case 3:
         VEMS_vidGET(TqRes_bCdnAC5Res, bLocalTqRes_bCdnAC5Res);
         VEMS_vidGET(TqRes_tqAC5Res, u16LocalTqRes_tqAC5Res);
         TqRes_bCdnACRes = bLocalTqRes_bCdnAC5Res;
         TqRes_tqACResRaw =
            (uint16)MATHSRV_udtMIN(u16LocalTqRes_tqAC5Res, 1600);
         VEMS_vidSET(TqRes_bDftACSwtOn, 0);
      break;

      default:
         TqRes_bCdnACRes = 0;
         TqRes_tqACResRaw = 0;
         VEMS_vidSET(TqRes_bDftACSwtOn, 0);
      break;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidPriorite_Fan                                    */
/* !Description :  Le groupe moto ventilateur est priorité par rapport à la   */
/*                 climatisation dans certains cas.                           */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_010.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 AC_pwrAC;                                                     */
/*  input uint8 TqRes_pwrACThrFrzAC_C;                                        */
/*  input uint16 TqRes_nEngThrFrzAC_C;                                        */
/*  input uint16 Eng_nCkFil;                                                  */
/*  input boolean TqRes_bCdnFanRes;                                           */
/*  input boolean TqRes_bAuthFrzAC_C;                                         */
/*  input boolean TqRes_bCdnACRes;                                            */
/*  input boolean TqRes_bCdnPwrFrzAC_MP;                                      */
/*  input boolean TqRes_bCdnNEngFrzAC_MP;                                     */
/*  output boolean TqRes_bCdnPwrFrzAC_MP;                                     */
/*  output boolean TqRes_bCdnNEngFrzAC_MP;                                    */
/*  output boolean TqRes_bFrzAC;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidPriorite_Fan(void)
{
   boolean bLocal_TqRes_bCdnFanRes;
   uint8   u8Local_AC_pwrAC;
   uint16  u16Local_Eng_nCkFil;
   uint32  u32LocalnEngThrFrzAC;


   VEMS_vidGET(AC_pwrAC, u8Local_AC_pwrAC);
   if (u8Local_AC_pwrAC > TqRes_pwrACThrFrzAC_C)
   {
      TqRes_bCdnPwrFrzAC_MP = 1;
   }
   else
   {
      TqRes_bCdnPwrFrzAC_MP = 0;
   }

   u32LocalnEngThrFrzAC = (uint32)(4 * TqRes_nEngThrFrzAC_C);
   VEMS_vidGET(Eng_nCkFil, u16Local_Eng_nCkFil);
   if (u16Local_Eng_nCkFil < u32LocalnEngThrFrzAC)
   {
      TqRes_bCdnNEngFrzAC_MP = 1;
   }
   else
   {
      TqRes_bCdnNEngFrzAC_MP = 0;
   }

   VEMS_vidGET(TqRes_bCdnFanRes, bLocal_TqRes_bCdnFanRes);
   if ( (TqRes_bAuthFrzAC_C != 0)
      &&(bLocal_TqRes_bCdnFanRes != 0)
      &&(TqRes_bCdnACRes != 0)
      &&(TqRes_bCdnPwrFrzAC_MP != 0)
      &&(TqRes_bCdnNEngFrzAC_MP != 0))
   {
      VEMS_vidSET(TqRes_bFrzAC, 1);
   }
   else
   {
      VEMS_vidSET(TqRes_bFrzAC, 0);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  TQACRES_vidCalcul_Reserve                                  */
/* !Description :  La réserve de couple climatisation est le maximum entre la */
/*                 valeur 0 et la soustraction de la réserve de couple        */
/*                 demandée et le couple compensé.                            */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.HIDRI                                                    */
/* !Trace_To    :  VEMS_R_10_04980_011.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16Channel)boolean;           */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean TqRes_bCdnACRes;                                            */
/*  input uint16 TqRes_tqACResRaw;                                            */
/*  input uint16 TqRes_tqDftValACRes_C;                                       */
/*  input uint16 TqRes_tqIncMaxACRes_C;                                       */
/*  input sint16 TqRes_tqDecMaxACRes_C;                                       */
/*  input boolean TQACRES_bTqRes_bCdnACRes_Prev;                              */
/*  input uint16 TqRes_tqACResSat_MP;                                         */
/*  input uint16 TqRes_tqIdlRes;                                              */
/*  input uint16 TqCmp_tqACLoss;                                              */
/*  output uint16 TqRes_tqACResSat_MP;                                        */
/*  output uint16 TqRes_tqACRes;                                              */
/*  output boolean TQACRES_bTqRes_bCdnACRes_Prev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void TQACRES_vidCalcul_Reserve(void)
{
   boolean bLocalAcvTqACResDftVal;
   uint16  u16LocalFilterInput;
   uint16  u16LocalFilterIncValue;
   uint16  u16LocalFilterDecValue;
   uint16  u16LocaltqACResSat_MP;
   uint16  u16LocalTqRes_tqIdlRes;
   uint16  u16LocalTqCmp_tqACLoss;
   uint16  u16LocalTqRes_tqACRes;
   sint16  s16LocalFilterDecValue;
   sint32  s32LocalDiff;


   bLocalAcvTqACResDftVal = GDGAR_bGetFRM(FRM_FRM_ACVTQACRESDFTVAL);
   if (TqRes_bCdnACRes != 0)
   {
      if (bLocalAcvTqACResDftVal == 0)
      {
         u16LocalFilterInput = TqRes_tqACResRaw;
      }
      else
      {
         u16LocalFilterInput = TqRes_tqDftValACRes_C;
      }
   }
   else
   {
      u16LocalFilterInput = 0;
   }

   u16LocalFilterIncValue = (uint16)(TqRes_tqIncMaxACRes_C / 25);
   s16LocalFilterDecValue = (sint16)((TqRes_tqDecMaxACRes_C * (-1)) / 25);
   u16LocalFilterDecValue = (uint16)MATHSRV_udtMAX(s16LocalFilterDecValue, 0);

   if (  (TqRes_bCdnACRes == 0)
      || (TQACRES_bTqRes_bCdnACRes_Prev != 0))
   {
      u16LocaltqACResSat_MP = MATHSRV_u16SlewFilter(TqRes_tqACResSat_MP,
                                                    u16LocalFilterInput,
                                                    u16LocalFilterIncValue,
                                                    u16LocalFilterDecValue);
   }
   else
   {
      VEMS_vidGET(TqRes_tqIdlRes, u16LocalTqRes_tqIdlRes);
      u16LocaltqACResSat_MP = u16LocalTqRes_tqIdlRes;
   }
   TqRes_tqACResSat_MP = (uint16)MATHSRV_udtMIN(u16LocaltqACResSat_MP, 1600);

   VEMS_vidGET(TqCmp_tqACLoss, u16LocalTqCmp_tqACLoss);
   s32LocalDiff = (sint32)(TqRes_tqACResSat_MP - u16LocalTqCmp_tqACLoss);
   u16LocalTqRes_tqACRes = (uint16)MATHSRV_udtMAX(s32LocalDiff, 0);

   VEMS_vidSET(TqRes_tqACRes, u16LocalTqRes_tqACRes);
   TQACRES_bTqRes_bCdnACRes_Prev = TqRes_bCdnACRes;
}
/*------------------------------- end of file --------------------------------*/