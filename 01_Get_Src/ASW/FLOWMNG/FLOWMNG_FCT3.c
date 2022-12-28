/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : FLOWMNG                                                 */
/* !Description     : FLOWMNG Component                                       */
/*                                                                            */
/* !Module          : FLOWMNG                                                 */
/* !Description     : Management of the configurable information flow         */
/*                                                                            */
/* !File            : FLOWMNG_FCT3.C                                          */
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
/*   1 / FLOWMNG_vidCANSeln                                                   */
/*   2 / FLOWMNG_vidTExtMng                                                   */
/*   3 / FLOWMNG_vidTOilMng                                                   */
/*   4 / FLOWMNG_vidInit_EEPROM                                               */
/*   5 / FLOWMNG_vidFirst_DayCtMng                                            */
/*   6 / FLOWMNG_vidDayCtMng_Calc1                                            */
/*   7 / FLOWMNG_vidCtInitUpDate                                              */
/*   8 / FLOWMNG_vidInit_InitUpDate                                           */
/*   9 / FLOWMNG_vidSec_InitUpDate                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT3.C_v        $*/
/* $Revision::   1.19     $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   10 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "Std_Limits.h"
#include "MATHSRV.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidCANSeln                                         */
/* !Description :  Cette stratégie définit quel paramètre CAN doit être pris  */
/*                 en compte en fonction de l’architecture du véhicule,       */
/* !Number      :  FCT3.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Bat_rBattSoC_4F2;                                            */
/*  input uint8 Ext_rBattSoCLoResl;                                           */
/*  input boolean Cf_rBattSoCSeln_C;                                          */
/*  output uint16 Bat_rBattSoC;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidCANSeln(void)
{
   uint8   u8LocalExt_rBattSoCLoResl;
   uint16  u16LocalBat_rBattSoC_4F2;
   uint16  u16LocalBat_rBattSoC;


   VEMS_vidGET(Bat_rBattSoC_4F2,u16LocalBat_rBattSoC_4F2);
   VEMS_vidGET(Ext_rBattSoCLoResl,u8LocalExt_rBattSoCLoResl);

   if (Cf_rBattSoCSeln_C != 0)
   {
      u16LocalBat_rBattSoC = u16LocalBat_rBattSoC_4F2;
   }
   else
   {
      u16LocalBat_rBattSoC = (uint16)(u8LocalExt_rBattSoCLoResl * 10);
   }
   u16LocalBat_rBattSoC = (uint16)MATHSRV_udtMIN(u16LocalBat_rBattSoC, 1000);
   VEMS_vidSET(Bat_rBattSoC, u16LocalBat_rBattSoC);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidTExtMng                                         */
/* !Description :  Fonction qui calcule les température air extérieures       */
/*                 traitée et venant du CAN                                   */
/* !Number      :  FCT3.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_008.02                                     */
/*                 VEMS_R_11_00339_009.02                                     */
/*                 VEMS_R_11_00339_028.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  input boolean Ext_bArchiCf;                                               */
/*  input sint8 TqCmp_tAirEstim;                                              */
/*  input boolean TqCmp_bTAirChk;                                             */
/*  input boolean ISCAN_bF5B2P146Invld;                                       */
/*  input boolean ISCAN_bCopyF5B2Length;                                      */
/*  input sint16 Ext_tAirSideMirrMes_5B2h;                                    */
/*  input sint16 Ext_tAirExtMesFineResl_prev;                                 */
/*  input sint16 Ext_tAirSideMirrMes_7F2h;                                    */
/*  input boolean ISCAN_bCopyF7F2Length;                                      */
/*  input boolean ISCAN_bF7F2P146bisInvld;                                    */
/*  output boolean Ext_bTAirChk;                                              */
/*  output sint16 Ext_tAirExtMesFineResl_prev;                                */
/*  output sint16 Ext_tAirExtMes;                                             */
/*  output sint16 Ext_tAirExtMesFineResl;                                     */
/*  output sint8 Ext_tAir;                                                    */
/*  output sint16 Ext_tAirMesFineResl;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidTExtMng(void)
{
   boolean bLocalTqCmp_bTAirChk;
   boolean bLocalExt_bArchiCf;
   boolean bLocalISCAN_bF5B2P146Invld;
   boolean bLocalISCAN_bCopyF5B2Length;
   boolean bLocalISCAN_bCopyF7F2Length;
   boolean bLocal_AcvF7F2Byp;
   boolean bLocal_Invld_CNTXT_1_5B2_P146;
   boolean bLocal_AcvF5B2Byp;
   boolean bLocal_Invld_BSI_7F2_P146;
   boolean bLocalISCAN_bF7F2P146bisInvld;
   sint8   s8LocalTqCmp_tAirEstim;
   sint8   s8LocalExt_tAir;
   sint16  s16LocalExt_tAirSideMirrMes_5B2h;
   sint16  s16LocalExt_tAirSideMirrMes_7F2h;
   sint16  s16LocalExt_tAirExtMes;
   sint16  s16LocalExt_tAirExtMesFineResl;
   sint16  s16LocalExt_tAirMesFineResl;
   sint16  s16LocalExtMes;
   sint32  s32LocalExt_tAirExtMesFineResl;


   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(TqCmp_tAirEstim, s8LocalTqCmp_tAirEstim);
   VEMS_vidGET(TqCmp_bTAirChk, bLocalTqCmp_bTAirChk);
   VEMS_vidSET(Ext_bTAirChk, bLocalTqCmp_bTAirChk);

   if (bLocalExt_bArchiCf != 0)
   {
      VEMS_vidGET(ISCAN_bF5B2P146Invld, bLocalISCAN_bF5B2P146Invld);
      bLocal_Invld_CNTXT_1_5B2_P146 =
         GDGAR_bGetFRM(FRM_FRM_INVLD_CONTEXTE_1_5B2_P146);
      VEMS_vidGET(ISCAN_bCopyF5B2Length, bLocalISCAN_bCopyF5B2Length);
      bLocal_AcvF5B2Byp = GDGAR_bGetFRM(FRM_FRM_ACVF5B2BYP);
      VEMS_vidGET(Ext_tAirSideMirrMes_5B2h, s16LocalExt_tAirSideMirrMes_5B2h);

      if (  (bLocalISCAN_bF5B2P146Invld != 0)
         || (bLocal_Invld_CNTXT_1_5B2_P146 != 0)
         || (bLocalISCAN_bCopyF5B2Length != 0)
         || (bLocal_AcvF5B2Byp != 0))
      {
         if ( bLocalTqCmp_bTAirChk != 0)
         {
            s16LocalExt_tAirExtMes =
               (sint16)MATHSRV_udtMAX(s8LocalTqCmp_tAirEstim, -50);
            s16LocalExt_tAirExtMesFineResl =
               (sint16)(s8LocalTqCmp_tAirEstim * 10);
            s16LocalExt_tAirExtMesFineResl =
               (sint16)MATHSRV_udtMAX(s16LocalExt_tAirExtMesFineResl, -500);
            s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s8LocalTqCmp_tAirEstim,
                                                      -40,
                                                      100);
            s16LocalExt_tAirMesFineResl =
               (sint16)MATHSRV_udtMAX(s8LocalTqCmp_tAirEstim, -50);
         }
         else
         {
            if (  (bLocal_Invld_CNTXT_1_5B2_P146 != 0)
               ||	(bLocal_AcvF5B2Byp != 0))
            {
               s16LocalExtMes =
                  (sint16)(s16LocalExt_tAirSideMirrMes_5B2h / 2);
               s16LocalExt_tAirExtMes =
                  (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
               s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
               s32LocalExt_tAirExtMesFineResl =
                  (sint32)(s16LocalExt_tAirSideMirrMes_5B2h * 5);
               s16LocalExt_tAirExtMesFineResl =
                  (sint16)MATHSRV_udtCLAMP(s32LocalExt_tAirExtMesFineResl,
                                           -500,
                                           2000);
               s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes,
                                                         -40,
                                                         100);
            }
            else
            {
               s16LocalExtMes =
                  (sint16)(Ext_tAirExtMesFineResl_prev / 10);
               s16LocalExt_tAirExtMes =
                  (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
               s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
               s16LocalExt_tAirExtMesFineResl =
                  (sint16)MATHSRV_udtCLAMP(Ext_tAirExtMesFineResl_prev,
                                           -500,
                                           2000);
               s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes,
                                                         -40,
                                                         100);
            }
         }
      }
      else
      {
         s16LocalExtMes =
            (sint16)(s16LocalExt_tAirSideMirrMes_5B2h / 2);
         s16LocalExt_tAirExtMes =
               (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
         s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
         s32LocalExt_tAirExtMesFineResl =
            (sint32)(s16LocalExt_tAirSideMirrMes_5B2h * 5);
         s16LocalExt_tAirExtMesFineResl =
            (sint16)MATHSRV_udtCLAMP(s32LocalExt_tAirExtMesFineResl,
                                     -500,
                                     2000);
         s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes,
                                                   -40,
                                                   100);
      }
   }
   else
   {
      VEMS_vidGET(Ext_tAirSideMirrMes_7F2h, s16LocalExt_tAirSideMirrMes_7F2h);
      VEMS_vidGET(ISCAN_bCopyF7F2Length, bLocalISCAN_bCopyF7F2Length);
      VEMS_vidGET(ISCAN_bF7F2P146bisInvld, bLocalISCAN_bF7F2P146bisInvld);
      bLocal_Invld_BSI_7F2_P146 = GDGAR_bGetFRM(FRM_FRM_INVLD_BSI_7F2_P146);
      bLocal_AcvF7F2Byp = GDGAR_bGetFRM(FRM_FRM_ACVF7F2BYP);

      if (  (bLocalISCAN_bCopyF7F2Length != 0)
         || (bLocal_Invld_BSI_7F2_P146 != 0)
         || (bLocal_AcvF7F2Byp != 0)
         || (bLocalISCAN_bF7F2P146bisInvld))
      {
         if ( bLocalTqCmp_bTAirChk != 0)
         {
            s16LocalExt_tAirExtMes =
               (sint16)MATHSRV_udtMAX(s8LocalTqCmp_tAirEstim, -50);
            s16LocalExt_tAirExtMesFineResl =
               (sint16)(s8LocalTqCmp_tAirEstim * 10);
            s16LocalExt_tAirExtMesFineResl =
               (sint16)MATHSRV_udtMAX(s16LocalExt_tAirExtMesFineResl, -500);
            s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s8LocalTqCmp_tAirEstim,
                                                      -40,
                                                      100);
            s16LocalExt_tAirMesFineResl =
               (sint16)MATHSRV_udtMAX(s8LocalTqCmp_tAirEstim, -50);
         }
         else
         {
            if (  (bLocal_Invld_BSI_7F2_P146 != 0)
               ||	(bLocal_AcvF7F2Byp != 0))
            {
               s16LocalExtMes =
                  (sint16)(s16LocalExt_tAirSideMirrMes_7F2h / 2);
               s16LocalExt_tAirExtMes =
                  (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
               s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
               s32LocalExt_tAirExtMesFineResl =
                  (sint32)(s16LocalExt_tAirSideMirrMes_7F2h * 5);
               s16LocalExt_tAirExtMesFineResl =
                  (sint16)MATHSRV_udtCLAMP(s32LocalExt_tAirExtMesFineResl,
                                           -500,
                                           2000);
               s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes,
                                                         -40,
                                                         100);
            }
            else
            {
               s16LocalExtMes =
                  (sint16)(Ext_tAirExtMesFineResl_prev / 10);
               s16LocalExt_tAirExtMes =
                  (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
               s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
               s16LocalExt_tAirExtMesFineResl =
                  (sint16)MATHSRV_udtCLAMP(Ext_tAirExtMesFineResl_prev,
                                           -500,
                                           2000);
               s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes,
                                                         -40,
                                                         100);
            }
         }
      }
      else
      {
         s16LocalExtMes =
            (sint16)(s16LocalExt_tAirSideMirrMes_7F2h / 2);
         s16LocalExt_tAirExtMes =
            (sint16)MATHSRV_udtCLAMP(s16LocalExtMes, -50, 200);
         s16LocalExt_tAirMesFineResl = s16LocalExt_tAirExtMes;
         s32LocalExt_tAirExtMesFineResl =
            (sint32)(s16LocalExt_tAirSideMirrMes_7F2h * 5);
         s16LocalExt_tAirExtMesFineResl =
            (sint16)MATHSRV_udtCLAMP(s32LocalExt_tAirExtMesFineResl,
                                     -500,
                                     2000);
         s8LocalExt_tAir = (sint8)MATHSRV_udtCLAMP(s16LocalExtMes, -40, 100);
      }
   }

   Ext_tAirExtMesFineResl_prev = s16LocalExt_tAirExtMesFineResl;
   VEMS_vidSET(Ext_tAirExtMes, s16LocalExt_tAirExtMes);
   VEMS_vidSET(Ext_tAirExtMesFineResl, s16LocalExt_tAirExtMesFineResl);
   VEMS_vidSET(Ext_tAir, s8LocalExt_tAir);
   VEMS_vidSET(Ext_tAirMesFineResl, s16LocalExt_tAirMesFineResl);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidTOilMng                                         */
/* !Description :  Si le flux Eng_tOilEstim est produit par une fonction      */
/*                 d'estimation alors Ext_tOil est égal  Eng_tOilEstim        */
/* !Number      :  FCT3.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_010.02                                     */
/*                 VEMS_R_11_00339_011.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stOilTCf;                                                 */
/*  input sint16 Ext_tOilMes;                                                 */
/*  input boolean Eng_bTOilChk;                                               */
/*  input sint16 Eng_tOilEstim;                                               */
/*  input sint16 Ext_tOilDft;                                                 */
/*  output sint16 Ext_tOil;                                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidTOilMng(void)
{
   boolean bLocalEng_bTOilChk;
   uint8   u8LocalExt_stOilTCf;
   sint16  s16LocalExt_tOil;
   sint16  s16LocalExt_tOilMes;
   sint16  s16LocalEng_tOilEstim;


   VEMS_vidGET(Ext_stOilTCf, u8LocalExt_stOilTCf);
   if (u8LocalExt_stOilTCf == 0)
   {
      VEMS_vidGET(Ext_tOilMes, s16LocalExt_tOilMes);
      s16LocalExt_tOil = (sint16)((s16LocalExt_tOilMes * 2) / 5);
   }
   else
   {
      VEMS_vidGET(Eng_bTOilChk, bLocalEng_bTOilChk);
      if (bLocalEng_bTOilChk != 0)
      {
         VEMS_vidGET(Eng_tOilEstim, s16LocalEng_tOilEstim);
         s16LocalExt_tOil = s16LocalEng_tOilEstim;
      }
      else
      {
         s16LocalExt_tOil = Ext_tOilDft;
      }
   }
   s16LocalExt_tOil = (sint16)MATHSRV_udtCLAMP(s16LocalExt_tOil, -200, 800);
   VEMS_vidSET(Ext_tOil, s16LocalExt_tOil);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidInit_EEPROM                                     */
/* !Description :  Fonction d'initialisation des variables memoire à chaque   */
/*                 connexion/deconnexion                                      */
/* !Number      :  FCT3.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_014.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean FlowMng_bFirstTiCntMng;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidInit_EEPROM(void)
{
   FlowMng_bFirstTiCntMng = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidFirst_DayCtMng                                  */
/* !Description :  Fonction qui fais incrémenter le compteur temporel à chaque*/
/*                 récepton de la trame 552.                                  */
/* !Number      :  FCT3.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  PTS_R_5068508_001.01                                       */
/*                 VEMS_R_11_00339_027.01                                     */
/*                 VEMS_R_11_00339_029.01                                     */
/*                 VEMS_R_11_00339_030.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDayCtMng_Calc1();                             */
/*  input boolean FlowMng_bFirstTiCntMng;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidFirst_DayCtMng(void)
{
   if (FlowMng_bFirstTiCntMng == 0)
   {
      FLOWMNG_vidDayCtMng_Calc1();
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDayCtMng_Calc1                                  */
/* !Description :  Fonction qui appelle les deux macro de calcule de nombre de*/
/*                 jours et d'années                                          */
/* !Number      :  FCT3.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_CtCoBatt();                                      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidCtInitUpDate();                               */
/*  extf argret void FLOWMNG_vidCtInitUpDate2004();                           */
/*  input boolean Ext_bdftCoBatt;                                             */
/*  input uint32 Ext_ctVehPwrl;                                               */
/*  input uint32 Ext_ctSecPwrl;                                               */
/*  input uint8 Ext_ctYrPwrl;                                                 */
/*  input uint16 Ext_ctDayPwrl;                                               */
/*  input boolean ISCAN_bN32F552bisP325NotAvl;                                */
/*  input boolean ISCAN_bF552bisP325Invld;                                    */
/*  input uint32 FLOWMNG_u32TiCtctSecStopEng_Prev;                            */
/*  input uint32 FLOWMNG_u32Ext_ctSec_Prev;                                   */
/*  input uint16 FLOWMNG_u16Ext_ctDay_Prev;                                   */
/*  input uint8 FLOWMNG_u8Ext_ctYr_Prev;                                      */
/*  input uint32 FLOWMNG_u32Ext_ctSecEngStop_Prev;                            */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint32 Ext_ctSecEngStop;                                            */
/*  input uint32 TiCt_ctSecStopEng;                                           */
/*  input boolean Ext_bArchiCf;                                               */
/*  input uint32 Ext_ctSecCAN;                                                */
/*  input uint16 Ext_ctDayCAN;                                                */
/*  input uint8 Ext_ctYrCAN;                                                  */
/*  input uint32 Ext_ctSecEngStop2004;                                        */
/*  output uint32 Ext_ctVehPwrl;                                              */
/*  output uint8 Ext_ctYrPwrl;                                                */
/*  output uint16 Ext_ctDayPwrl;                                              */
/*  output uint32 Ext_ctSecPwrl;                                              */
/*  output uint32 TiCt_ctSecStopEng;                                          */
/*  output uint32 Ext_ctSec;                                                  */
/*  output uint16 Ext_ctDay;                                                  */
/*  output uint8 Ext_ctYr;                                                    */
/*  output uint32 Ext_ctSecEngStop;                                           */
/*  output uint32 FLOWMNG_u32TiCtctSecStopEng_Prev;                           */
/*  output uint8 FLOWMNG_u8Ext_ctYr_Prev;                                     */
/*  output uint16 FLOWMNG_u16Ext_ctDay_Prev;                                  */
/*  output uint32 FLOWMNG_u32Ext_ctSec_Prev;                                  */
/*  output uint32 FLOWMNG_u32Ext_ctSecEngStop_Prev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDayCtMng_Calc1(void)
{
   boolean bLocalExt_bArchiCf;
   boolean bLocalISCAN_N32F552bisP325NotAvl;
   boolean bLocalISCAN_bF552bisP325Invld;
   uint8   u8LocalExt_ctYrCAN;
   uint8   u8LocalExt_ctYr;
   uint8   u8LocalExt_ctYr_switch1;
   uint16  u16LocalExt_ctDayCAN;
   uint16  u16LocalExt_ctDay;
   uint16  u16LocalExt_ctDay_switch1;
   uint32  u32LocalExt_ctSecCAN;
   uint32  u32LocalExt_ctSec;
   uint32  u32LocalExt_ctSec_switch1;
   uint32  u32LocalExt_ctSecEngStop;
   uint32  u32LocalExt_ctSecEngStop_switch1;
   uint32  u32LocalExt_ctVehPwrl;
   uint32  u32LocalExt_ctSecPwrl;
   uint32  u32LocalTiCt_ctSecStopEng;


   FLOWMNG_CtCoBatt();
   if (Ext_bdftCoBatt != 0)
   {
      VEMS_vidSET(Ext_ctVehPwrl, 0);
      Ext_ctYrPwrl = 0;
      Ext_ctDayPwrl = 0;
      VEMS_vidSET(Ext_ctSecPwrl, 0);
   }
   else
   {
      VEMS_vidGET(Ext_ctVehPwrl, u32LocalExt_ctVehPwrl);
      u32LocalExt_ctVehPwrl =
         MATHSRV_udtMIN(u32LocalExt_ctVehPwrl, 4294967293UL);
      VEMS_vidGET(Ext_ctSecPwrl, u32LocalExt_ctSecPwrl);
      u32LocalExt_ctSecPwrl = MATHSRV_udtMIN(u32LocalExt_ctSecPwrl, 586639);

      VEMS_vidSET(Ext_ctVehPwrl, u32LocalExt_ctVehPwrl);
      Ext_ctYrPwrl = (uint8)MATHSRV_udtMIN(Ext_ctYrPwrl, 101);
      Ext_ctDayPwrl = (uint16)MATHSRV_udtMIN(Ext_ctDayPwrl, 365);
      VEMS_vidSET(Ext_ctSecPwrl, u32LocalExt_ctSecPwrl);
   }

   FLOWMNG_vidCtInitUpDate();
   FLOWMNG_vidCtInitUpDate2004();

   VEMS_vidGET(ISCAN_bN32F552bisP325NotAvl, bLocalISCAN_N32F552bisP325NotAvl);
   VEMS_vidGET(ISCAN_bF552bisP325Invld, bLocalISCAN_bF552bisP325Invld);
   if (  (bLocalISCAN_N32F552bisP325NotAvl != 0)
      || (bLocalISCAN_bF552bisP325Invld != 0))
   {
      u32LocalTiCt_ctSecStopEng =
         MATHSRV_udtMIN(FLOWMNG_u32TiCtctSecStopEng_Prev, 4294967293UL);
      u32LocalExt_ctSec_switch1 =
         MATHSRV_udtMIN(FLOWMNG_u32Ext_ctSec_Prev, 586639);
      u16LocalExt_ctDay_switch1 =
         (uint16)MATHSRV_udtMIN(FLOWMNG_u16Ext_ctDay_Prev, 365);
      u8LocalExt_ctYr_switch1 =
         (uint8)MATHSRV_udtMIN(FLOWMNG_u8Ext_ctYr_Prev, 100);
      u32LocalExt_ctSecEngStop_switch1 =
         MATHSRV_udtMIN(FLOWMNG_u32Ext_ctSecEngStop_Prev, 429496729UL);
   }
   else
   {
      VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
      VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
      VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
      VEMS_vidGET(Ext_ctSecEngStop, u32LocalExt_ctSecEngStop);
      VEMS_vidGET(TiCt_ctSecStopEng, u32LocalTiCt_ctSecStopEng);
      u32LocalTiCt_ctSecStopEng =
         MATHSRV_udtMIN(u32LocalTiCt_ctSecStopEng, 4294967293UL);
      u32LocalExt_ctSec_switch1 = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
      u16LocalExt_ctDay_switch1 =
         (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
      u8LocalExt_ctYr_switch1 =
         (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
      u32LocalExt_ctSecEngStop_switch1 =
         MATHSRV_udtMIN(u32LocalExt_ctSecEngStop, 429496729UL);
   }
   VEMS_vidSET(TiCt_ctSecStopEng, u32LocalTiCt_ctSecStopEng);
   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   if (bLocalExt_bArchiCf == 0)
   {
      VEMS_vidGET(Ext_ctSecCAN, u32LocalExt_ctSecCAN);
      VEMS_vidGET(Ext_ctDayCAN, u16LocalExt_ctDayCAN);
      VEMS_vidGET(Ext_ctYrCAN, u8LocalExt_ctYrCAN);

      u32LocalExt_ctSec = MATHSRV_udtMIN(u32LocalExt_ctSecCAN, 586639);
      u16LocalExt_ctDay =
         (uint16)MATHSRV_udtMIN(u16LocalExt_ctDayCAN, 365);
      u8LocalExt_ctYr =
         (uint8)MATHSRV_udtMIN(u8LocalExt_ctYrCAN, 100);
      u32LocalExt_ctSecEngStop =
         MATHSRV_udtMIN(Ext_ctSecEngStop2004, 429496729UL);
   }
   else
   {
      u32LocalExt_ctSec = u32LocalExt_ctSec_switch1;
      u16LocalExt_ctDay = u16LocalExt_ctDay_switch1;
      u8LocalExt_ctYr = u8LocalExt_ctYr_switch1;
      u32LocalExt_ctSecEngStop = u32LocalExt_ctSecEngStop_switch1;
   }
   VEMS_vidSET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidSET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidSET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidSET(Ext_ctSecEngStop, u32LocalExt_ctSecEngStop);

   FLOWMNG_u32TiCtctSecStopEng_Prev  = u32LocalTiCt_ctSecStopEng;
   FLOWMNG_u8Ext_ctYr_Prev = u8LocalExt_ctYr_switch1;
   FLOWMNG_u16Ext_ctDay_Prev = u16LocalExt_ctDay_switch1;
   FLOWMNG_u32Ext_ctSec_Prev = u32LocalExt_ctSec_switch1;
   FLOWMNG_u32Ext_ctSecEngStop_Prev = u32LocalExt_ctSecEngStop_switch1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidCtInitUpDate                                    */
/* !Description :  Fonction contenant toutes les fonctions de mise à jour     */
/*                 compteurs                                                  */
/* !Number      :  FCT3.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidInit_InitUpDate();                            */
/*  extf argret void FLOWMNG_vidSec_InitUpDate();                             */
/*  extf argret void FLOWMNG_vidDay_InitUpDate();                             */
/*  extf argret void FLOWMNG_vidYr_InitUpDate();                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidCtInitUpDate(void)
{
   FLOWMNG_vidInit_InitUpDate();
   FLOWMNG_vidSec_InitUpDate();
   FLOWMNG_vidDay_InitUpDate();
   FLOWMNG_vidYr_InitUpDate();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidInit_InitUpDate                                 */
/* !Description :  Fonctions d'initialisation des compteurs avant mise à jour */
/* !Number      :  FCT3.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint32 Ext_ctVehPwrl;                                               */
/*  input uint8 TiCt_ctTiUSec_C;                                              */
/*  output uint32 TiCt_ctSecEng;                                              */
/*  output uint32 TiCt_ctSecStopEng;                                          */
/*  output uint32 Ext_ctSecEngStop;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidInit_InitUpDate(void)
{
   uint32 u32LocalExt_tiCurVehTmr;
   uint32 u32LocalSortie;
   uint32 u32LocalTiCt_ctSecStopEng;
   uint32 u32LocalExt_ctSecEngStop;


   VEMS_vidGET(Ext_tiCurVehTmr, u32LocalExt_tiCurVehTmr);
   if (u32LocalExt_tiCurVehTmr >= Ext_ctVehPwrl)
   {
      u32LocalSortie = (u32LocalExt_tiCurVehTmr - Ext_ctVehPwrl);
   }
   else
   {
      u32LocalSortie = (Ext_ctVehPwrl - u32LocalExt_tiCurVehTmr);
      if (u32LocalSortie > 4294967293UL)
      {
         u32LocalSortie = 0;
      }
      else
      {
         u32LocalSortie = (4294967293UL - u32LocalSortie);
      }
   }
   u32LocalTiCt_ctSecStopEng = MATHSRV_udtMIN(u32LocalSortie, 4294967293UL);
   TiCt_ctSecEng = u32LocalTiCt_ctSecStopEng;
   VEMS_vidSET(TiCt_ctSecStopEng, u32LocalTiCt_ctSecStopEng);
   if (TiCt_ctTiUSec_C != 0)
   {
      u32LocalExt_ctSecEngStop = (u32LocalSortie / TiCt_ctTiUSec_C);
      u32LocalExt_ctSecEngStop = MATHSRV_udtMIN(u32LocalExt_ctSecEngStop,
                                                429496729);
   }
   else
   {
      u32LocalExt_ctSecEngStop = 429496729;
   }
   VEMS_vidSET(Ext_ctSecEngStop, u32LocalExt_ctSecEngStop);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidSec_InitUpDate                                  */
/* !Description :  Fonction d'initialisation du compteur des secondes         */
/* !Number      :  FCT3.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_ctSecPwrl;                                               */
/*  input uint8 TiCt_ctTiUSec_C;                                              */
/*  input uint32 TiCt_ctSecEng;                                               */
/*  input uint32 Tict_nbSec;                                                  */
/*  input uint32 TiCt_ctSecInDay_C;                                           */
/*  input uint32 Ext_ctSecTot;                                                */
/*  output uint32 Tict_nbSec;                                                 */
/*  output uint32 Ext_ctSecTot;                                               */
/*  output uint16 FLOWMNG_u16Ext_ctDay;                                       */
/*  output uint8 FLOWMNG_u8Ext_ctInt;                                         */
/*  output uint32 Ext_ctSec;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidSec_InitUpDate(void)
{
   uint32 u32LocalExt_ctSecPwrl;
   uint32 u32LocalDiv;
   uint32 u32LocalExt_ctSec;
   uint32 u32LocalMult;
   uint32 u32LocalTict_nbSec;
   uint32 u32Localdiff;
   uint32 u32Localout1;


   VEMS_vidGET(Ext_ctSecPwrl, u32LocalExt_ctSecPwrl);
   if (TiCt_ctTiUSec_C > 0)
   {
      u32LocalTict_nbSec = TiCt_ctSecEng / TiCt_ctTiUSec_C;
      Tict_nbSec = MATHSRV_udtMIN(u32LocalTict_nbSec, 429496729);
   }
   else
   {
      Tict_nbSec = 429496729;
   }
   u32LocalMult = Tict_nbSec * TiCt_ctTiUSec_C;
   if (u32LocalMult < TiCt_ctSecEng)
   {
      u32Localout1 = (TiCt_ctSecEng - u32LocalMult);
   }
   else
   {
      u32Localout1 = 0;
   }

   if (u32LocalExt_ctSecPwrl < 429496729)
   {
      u32Localdiff = 429496729 - Tict_nbSec;
      if (u32LocalExt_ctSecPwrl < u32Localdiff)
      {
         Ext_ctSecTot = (u32LocalExt_ctSecPwrl + Tict_nbSec);
      }
      else
      {
         Ext_ctSecTot = 429496729;
      }
   }
   else
   {
      Ext_ctSecTot = 429496729;
   }
   if (TiCt_ctSecInDay_C != 0)
   {
      u32LocalDiv = (Ext_ctSecTot / TiCt_ctSecInDay_C);
      FLOWMNG_u16Ext_ctDay = (uint16)MATHSRV_udtMIN(u32LocalDiv, 5000);
      u32LocalExt_ctSec = (Ext_ctSecTot - (TiCt_ctSecInDay_C * u32LocalDiv));
   }
   else
   {
      FLOWMNG_u16Ext_ctDay = 5000;
      u32LocalExt_ctSec = Ext_ctSecTot;
   }

   FLOWMNG_u8Ext_ctInt = (uint8)MATHSRV_udtMIN(u32Localout1, 10);
   u32LocalExt_ctSec = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   VEMS_vidSET(Ext_ctSec, u32LocalExt_ctSec);
}
/*------------------------------- end of file --------------------------------*/