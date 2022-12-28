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
/* !File            : FLOWMNG_FCT4.C                                          */
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
/*   1 / FLOWMNG_vidDay_InitUpDate                                            */
/*   2 / FLOWMNG_vidYr_InitUpDate                                             */
/*   3 / FLOWMNG_vidCtInitUpDate2004                                          */
/*   4 / FLOWMNG_vidDayCtMng                                                  */
/*   5 / FLOWMNG_vidDayCtMng_Calc2                                            */
/*   6 / FLOWMNG_vidInit_UpDate                                               */
/*   7 / FLOWMNG_vidSec_UpDate                                                */
/*   8 / FLOWMNG_vidDay_UpDate                                                */
/*   9 / FLOWMNG_vidYr_UpDate                                                 */
/*   10 / FLOWMNG_vidUpDate2004                                               */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT4.C_v        $*/
/* $Revision::   1.18     $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   10 Dec 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "STD_LIMITS.h"
#include "MATHSRV.h"
#include "FLOWMNG.h"
#include "FLOWMNG_L.h"
#include "FLOWMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDay_InitUpDate                                  */
/* !Description :  Fonction d'initilaisation du compteur jour                 */
/* !Number      :  FCT4.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 FLOWMNG_u16Ext_ctDay;                                        */
/*  input uint16 Ext_ctDayPwrl;                                               */
/*  input uint16 TiCt_ctDayInYr_C;                                            */
/*  input uint16 Ext_ctDayTot;                                                */
/*  output uint16 Ext_ctDayTot;                                               */
/*  output uint8 FLOWMNG_u8Ext_ctYr;                                          */
/*  output uint16 Ext_ctDay;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDay_InitUpDate(void)
{
   uint16 u16LocalDiv;
   uint16 u16Localdiff;
   uint32 u32Localsomme;
   uint32 u32LocalMult;


   u32Localsomme = (uint32)(FLOWMNG_u16Ext_ctDay + Ext_ctDayPwrl);
   Ext_ctDayTot = (uint16)MATHSRV_udtMIN(u32Localsomme, 5000);
   if (TiCt_ctDayInYr_C != 0)
   {
      u16LocalDiv = (uint16)(Ext_ctDayTot /  TiCt_ctDayInYr_C);
   }
   else
   {
      u16LocalDiv = 65535;
   }
   FLOWMNG_u8Ext_ctYr = (uint8)MATHSRV_udtMIN(u16LocalDiv, 14);
   u32LocalMult = (uint32)(TiCt_ctDayInYr_C * u16LocalDiv);
   u16Localdiff = (uint16)(Ext_ctDayTot - u32LocalMult);
   /*QAC Msg(3:3382):  error couldn't happen:Ext_ctDayTot > u32LocalMult */
   u16Localdiff = (uint16)MATHSRV_udtMIN(u16Localdiff, 365);
   VEMS_vidSET(Ext_ctDay, u16Localdiff);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidYr_InitUpDate                                   */
/* !Description :  Fonction initilaisation compteur année                     */
/* !Number      :  FCT4.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 FLOWMNG_u8Ext_ctYr;                                           */
/*  input uint8 Ext_ctYrPwrl;                                                 */
/*  output uint8 Ext_ctYr;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidYr_InitUpDate(void)
{
   uint8  u8LocalExt_ctYr;
   uint16 u16Localmod;


   u16Localmod = (uint16)(Ext_ctYrPwrl + (FLOWMNG_u8Ext_ctYr % 13));
   u8LocalExt_ctYr = (uint8)MATHSRV_udtMIN(u16Localmod, 100);
   VEMS_vidSET(Ext_ctYr, u8LocalExt_ctYr);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidCtInitUpDate2004                                */
/* !Description :  Fonction qui mesure le temps d'arrêt Ext_ctSecEngStop2004. */
/* !Number      :  FCT4.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_ctYrCAN;                                                  */
/*  input uint16 Ext_ctDayCAN;                                                */
/*  input uint32 Ext_ctSecCAN;                                                */
/*  input uint16 TiCt_ctDayInYr_C;                                            */
/*  input uint32 TiCt_ctSecInDay_C;                                           */
/*  input uint32 Ext_ctVehPwrl2004;                                           */
/*  output uint32 Ext_tiCurVeh2004;                                           */
/*  output uint32 Ext_ctSecEngStop2004;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidCtInitUpDate2004(void)
{
   uint8  u8LocalExt_ctYrCAN;
   uint16 u16LocalExt_ctDayCAN;
   uint32 u32LocalExt_ctSecCAN;
   uint32 u32LocalMult1;
   uint32 u32LocalMult2;
   uint32 u32Localsomme;
   uint32 u32LocalMod;
   uint32 u32LocalDenum;
   uint32 u32LocalExtctSecEngStop2004;
   uint32 u32LocalTest;


   VEMS_vidGET(Ext_ctYrCAN, u8LocalExt_ctYrCAN);
   VEMS_vidGET(Ext_ctDayCAN, u16LocalExt_ctDayCAN);
   VEMS_vidGET(Ext_ctSecCAN, u32LocalExt_ctSecCAN);
   /*premiere multiplication*/
   if (  (TiCt_ctDayInYr_C == 0)
      || (TiCt_ctSecInDay_C == 0)
      || (u8LocalExt_ctYrCAN == 0))
   {
      u32LocalMult1 = 0;
   }
   else
   {
      u32LocalDenum = (uint32)(u8LocalExt_ctYrCAN * TiCt_ctDayInYr_C);
      u32LocalTest = UINT32_MAX / u32LocalDenum;
      if (TiCt_ctSecInDay_C > u32LocalTest)
      {
         u32LocalMult1 = UINT32_MAX;
      }
      else
      {
         u32LocalMult1 = u32LocalDenum * TiCt_ctSecInDay_C;
      }
   }
   /*deuxieme multiplication*/
   if (  (TiCt_ctSecInDay_C == 0)
      || (u16LocalExt_ctDayCAN == 0))
   {
      u32LocalMult2 = 0;
   }
   else
   {
      u32LocalTest = UINT32_MAX / ((uint32)u16LocalExt_ctDayCAN);
      if (TiCt_ctSecInDay_C > u32LocalTest)
      {
         u32LocalMult2 = UINT32_MAX;
      }
      else
      {
         u32LocalMult2 = TiCt_ctSecInDay_C * (uint32)u16LocalExt_ctDayCAN;
      }
   }
   /*Sommation*/
   u32LocalTest = UINT32_MAX - u32LocalMult2;
   if (u32LocalMult1 > u32LocalTest)
   {
      u32Localsomme = UINT32_MAX;
   }
   else
   {
      u32Localsomme = u32LocalMult1 + u32LocalMult2;
      /*ERROR QAC Msg(3:3382) couldn't happen:
         this part of code is protected by the if test*/
      u32LocalTest = UINT32_MAX - u32LocalExt_ctSecCAN;
      if (u32Localsomme > u32LocalTest)
      {
         u32Localsomme = UINT32_MAX;
      }
      else
      {
         u32Localsomme = u32Localsomme + u32LocalExt_ctSecCAN;
      }
   }
   /*Modulo*/
   u32LocalMod = u32Localsomme % 429496729UL;
   Ext_tiCurVeh2004 = (u32LocalMod * 10);
   if (u32LocalMod > Ext_ctVehPwrl2004)
   {
      Ext_ctSecEngStop2004 = u32LocalMod - Ext_ctVehPwrl2004;
   }
   else
   {
      u32LocalExtctSecEngStop2004 = Ext_ctVehPwrl2004 - u32LocalMod;
      if (u32LocalExtctSecEngStop2004 > 429496729)
      {
         Ext_ctSecEngStop2004 = 0;
      }
      else
      {
         Ext_ctSecEngStop2004 = (u32LocalMod - Ext_ctVehPwrl2004) + 429496729;
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDayCtMng                                        */
/* !Description :  Cette fonction gère la sélection des flux compteur temporel*/
/*                 ou des paramètres seconde, jour, année.                    */
/* !Number      :  FCT4.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_012.01                                     */
/*                 VEMS_R_11_00339_013.01                                     */
/*                 VEMS_R_11_00339_017.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidDayCtMng_Calc2();                             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean FlowMng_bFirstTiCntMng;                                     */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  output uint32 Ext_tiCurVeh_prev;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDayCtMng(void)
{
   uint32 u32LocalExt_tiCurVehTmr;

   if (FlowMng_bFirstTiCntMng != 0)
   {
      FLOWMNG_vidDayCtMng_Calc2();
   }

   VEMS_vidGET(Ext_tiCurVehTmr, u32LocalExt_tiCurVehTmr);
   Ext_tiCurVeh_prev = MATHSRV_udtMIN(u32LocalExt_tiCurVehTmr, 4294967293UL);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDayCtMng_Calc2                                  */
/* !Description :  Fonction of day Contrôle Management Calculation            */
/* !Number      :  FCT4.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidInit_UpDate();                                */
/*  extf argret void FLOWMNG_vidUpDate2004();                                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidSec_UpDate();                                 */
/*  extf argret void FLOWMNG_vidDay_UpDate();                                 */
/*  extf argret void FLOWMNG_vidYr_UpDate();                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bArchiCf;                                               */
/*  input boolean ISCAN_bN32F552bisP325NotAvl;                                */
/*  input boolean ISCAN_bF552bisP325Invld;                                    */
/*  input uint32 FLOWMNG_u32Ext_ctSec_Prev_2;                                 */
/*  input uint16 FLOWMNG_u16Ext_ctDay_Prev_2;                                 */
/*  input uint8 FLOWMNG_u8Ext_ctYr_Prev_2;                                    */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint32 Ext_ctSecCAN;                                                */
/*  input uint16 Ext_ctDayCAN;                                                */
/*  input uint8 Ext_ctYrCAN;                                                  */
/*  output uint8 Ext_ctYr;                                                    */
/*  output uint16 Ext_ctDay;                                                  */
/*  output uint32 Ext_ctSec;                                                  */
/*  output uint8 FLOWMNG_u8Ext_ctYr_Prev_2;                                   */
/*  output uint16 FLOWMNG_u16Ext_ctDay_Prev_2;                                */
/*  output uint32 FLOWMNG_u32Ext_ctSec_Prev_2;                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDayCtMng_Calc2(void)
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


   FLOWMNG_vidInit_UpDate();
   FLOWMNG_vidUpDate2004();

   VEMS_vidGET(Ext_bArchiCf, bLocalExt_bArchiCf);
   VEMS_vidGET(ISCAN_bN32F552bisP325NotAvl,
                     bLocalISCAN_N32F552bisP325NotAvl);
   VEMS_vidGET(ISCAN_bF552bisP325Invld, bLocalISCAN_bF552bisP325Invld);
   if (  (bLocalISCAN_N32F552bisP325NotAvl != 0)
      || (bLocalISCAN_bF552bisP325Invld != 0))
   {
      u32LocalExt_ctSec_switch1 =
         MATHSRV_udtMIN(FLOWMNG_u32Ext_ctSec_Prev_2, 586639);
      u16LocalExt_ctDay_switch1 =
         (uint16)MATHSRV_udtMIN(FLOWMNG_u16Ext_ctDay_Prev_2, 365);
      u8LocalExt_ctYr_switch1 =
         (uint8)MATHSRV_udtMIN(FLOWMNG_u8Ext_ctYr_Prev_2, 100);
   }
   else
   {
      FLOWMNG_vidSec_UpDate();
      FLOWMNG_vidDay_UpDate();
      FLOWMNG_vidYr_UpDate();
      VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
      VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
      VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
      u32LocalExt_ctSec_switch1 = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
      u16LocalExt_ctDay_switch1 =
         (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
      u8LocalExt_ctYr_switch1 =
         (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 100);
   }

   if (bLocalExt_bArchiCf == 0)
   {
      VEMS_vidGET(Ext_ctSecCAN, u32LocalExt_ctSecCAN);
      VEMS_vidGET(Ext_ctDayCAN, u16LocalExt_ctDayCAN);
      VEMS_vidGET(Ext_ctYrCAN, u8LocalExt_ctYrCAN);

      u32LocalExt_ctSec = MATHSRV_udtMIN(u32LocalExt_ctSecCAN, 586639);
      u16LocalExt_ctDay =
         (uint16)MATHSRV_udtMIN(u16LocalExt_ctDayCAN, 365);
      u8LocalExt_ctYr = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYrCAN, 100);
   }
   else
   {
      u32LocalExt_ctSec = u32LocalExt_ctSec_switch1;
      u16LocalExt_ctDay = u16LocalExt_ctDay_switch1;
      u8LocalExt_ctYr = u8LocalExt_ctYr_switch1;
   }
   VEMS_vidSET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidSET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidSET(Ext_ctSec, u32LocalExt_ctSec);
   FLOWMNG_u8Ext_ctYr_Prev_2 = u8LocalExt_ctYr_switch1;
   FLOWMNG_u16Ext_ctDay_Prev_2 = u16LocalExt_ctDay_switch1;
   FLOWMNG_u32Ext_ctSec_Prev_2 = u32LocalExt_ctSec_switch1;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidInit_UpDate                                     */
/* !Description :  Fonction qui initialise le compteur du dixième de seconde  */
/*                 d'arrêt moteur.                                            */
/* !Number      :  FCT4.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint32 Ext_tiCurVeh_prev;                                           */
/*  input uint8 FLOWMNG_u8Ext_ctInt;                                          */
/*  input uint8 FLOWMNG_u8Ext_ctInt_prev;                                     */
/*  input uint32 TiCt_tiDelta;                                                */
/*  output uint32 TiCt_tiDelta;                                               */
/*  output uint8 FLOWMNG_u8Ext_ctInt_prev;                                    */
/*  output uint32 TiCt_ctSecEng;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidInit_UpDate(void)
{
   uint32 u32LocalExt_tiCurVehTmr;
   uint32 u32LocalOut;
   uint32 u32Localtest;
   uint32 u32LocalTiCt_tiDelta;


   VEMS_vidGET(Ext_tiCurVehTmr, u32LocalExt_tiCurVehTmr);
   if (u32LocalExt_tiCurVehTmr > Ext_tiCurVeh_prev)
   {
      u32LocalTiCt_tiDelta = u32LocalExt_tiCurVehTmr - Ext_tiCurVeh_prev;
      TiCt_tiDelta = MATHSRV_udtMIN(u32LocalTiCt_tiDelta, 4294967293UL);
   }
   else
   {
      TiCt_tiDelta = 0;
   }
   FLOWMNG_u8Ext_ctInt_prev = (uint8)MATHSRV_udtMIN(FLOWMNG_u8Ext_ctInt, 10);
   u32Localtest = (UINT32_MAX - (uint32)FLOWMNG_u8Ext_ctInt_prev);
   if (TiCt_tiDelta > u32Localtest)
   {
      u32LocalOut = UINT32_MAX;
   }
   else
   {
      u32LocalOut = TiCt_tiDelta + FLOWMNG_u8Ext_ctInt_prev;
      /*ERROR QAC Msg(3:3382) couldn't happen:
         this part of code is protected by the if test*/
   }
   TiCt_ctSecEng = MATHSRV_udtMIN(u32LocalOut, 4294967293UL);

}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidSec_UpDate                                      */
/* !Description :  Fonction qui let a jour le compteur des dix première       */
/*                 millisecondes après arrêt moteur                           */
/* !Number      :  FCT4.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint8 TiCt_ctTiUSec_C;                                              */
/*  input uint32 TiCt_ctSecEng;                                               */
/*  input uint32 Tict_nbSec;                                                  */
/*  input uint32 TiCt_ctSecInDay_C;                                           */
/*  input uint32 Ext_ctSecTot;                                                */
/*  output uint32 Tict_nbSec;                                                 */
/*  output uint32 Ext_ctSecTot;                                               */
/*  output uint8 FLOWMNG_u8Ext_ctInt;                                         */
/*  output uint16 FLOWMNG_u16Ext_ctDay;                                       */
/*  output uint32 Ext_ctSec;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidSec_UpDate(void)
{
   uint32 u32Localout1;
   uint32 u32LocalMult;
   uint32 u32LocalExt_ctDay;
   uint32 u32LocalExt_ctSec;
   uint32 u32LocalTict_nbSec;
   uint32 u32LocalExt_ctSec_prev;
   uint32 u32Localtest;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec_prev);
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
   if (u32LocalExt_ctSec_prev < 429496729)
   {
      u32Localtest = 429496729 - Tict_nbSec;
      if (u32LocalExt_ctSec_prev < u32Localtest)
      {
         Ext_ctSecTot = (u32LocalExt_ctSec_prev + Tict_nbSec);
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
   if (TiCt_ctSecInDay_C > 0)
   {
      u32LocalExt_ctDay = Ext_ctSecTot / TiCt_ctSecInDay_C;
      u32LocalExt_ctSec =
         Ext_ctSecTot - (TiCt_ctSecInDay_C * u32LocalExt_ctDay);
   }
   else
   {
      u32LocalExt_ctDay = 5000;
      u32LocalExt_ctSec = Ext_ctSecTot;
   }

   u32LocalExt_ctSec = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639UL);
   FLOWMNG_u8Ext_ctInt = (uint8)MATHSRV_udtMIN(u32Localout1, 10);
   FLOWMNG_u16Ext_ctDay = (uint16)MATHSRV_udtMIN(u32LocalExt_ctDay, 5000);
   VEMS_vidSET(Ext_ctSec, u32LocalExt_ctSec);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidDay_UpDate                                      */
/* !Description :  Fonction qui met à jour le compteur des secondes           */
/* !Number      :  FCT4.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint16 FLOWMNG_u16Ext_ctDay;                                        */
/*  input uint16 TiCt_ctDayInYr_C;                                            */
/*  input uint16 Ext_ctDayTot;                                                */
/*  output uint16 Ext_ctDayTot;                                               */
/*  output uint8 FLOWMNG_u8Ext_ctYr;                                          */
/*  output uint16 Ext_ctDay;                                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDay_UpDate(void)
{
   uint16 u16LocalDiv;
   uint16 u16Localsoustract;
   uint16 u16LocalExt_ctDay_prev;
   uint32 u32LocalSomme;
   uint32 u32LocalMult;


   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay_prev);
   u32LocalSomme = u16LocalExt_ctDay_prev + FLOWMNG_u16Ext_ctDay;
   Ext_ctDayTot = (uint16)MATHSRV_udtMIN(u32LocalSomme, 5000);
   if (TiCt_ctDayInYr_C != 0)
   {
      u16LocalDiv = (uint16)(Ext_ctDayTot / TiCt_ctDayInYr_C);
   }
   else
   {
      u16LocalDiv = 65535;
   }
   FLOWMNG_u8Ext_ctYr = (uint8)MATHSRV_udtMIN(u16LocalDiv, 14);
   u32LocalMult = (uint32)(u16LocalDiv * TiCt_ctDayInYr_C);
   u16Localsoustract = (uint16)(Ext_ctDayTot - u32LocalMult);
   /*QAC Msg(3:3382):  error couldn't happen:Ext_ctDayTot > u32LocalMult */
   u16Localsoustract = (uint16)MATHSRV_udtMIN(u16Localsoustract, 365);
   VEMS_vidSET(Ext_ctDay, u16Localsoustract);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidYr_UpDate                                       */
/* !Description :  Fonction qui met à jour les compteurs jour et année.       */
/* !Number      :  FCT4.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint8 FLOWMNG_u8Ext_ctYr;                                           */
/*  output uint8 Ext_ctYr;                                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidYr_UpDate(void)
{
   uint8  u8LocalMod;
   uint8  u8LocalOut;
   uint16 u16LocalOut;


   VEMS_vidGET(Ext_ctYr, u8LocalOut);
   u8LocalMod = (uint8)(FLOWMNG_u8Ext_ctYr % 13);
   u16LocalOut = (uint16)(u8LocalMod + u8LocalOut);
   u8LocalOut = (uint8)MATHSRV_udtMIN(u16LocalOut, 100);
   VEMS_vidSET(Ext_ctYr, u8LocalOut);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidUpDate2004                                      */
/* !Description :  Foncton de mise à jour du compteur Ext_tiCurVeh2004        */
/* !Number      :  FCT4.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint8 Ext_ctYrCAN;                                                  */
/*  input uint16 Ext_ctDayCAN;                                                */
/*  input uint32 Ext_ctSecCAN;                                                */
/*  input uint16 TiCt_ctDayInYr_C;                                            */
/*  input uint32 TiCt_ctSecInDay_C;                                           */
/*  output uint32 Ext_tiCurVeh2004;                                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidUpDate2004(void)
{
   uint8  u8LocalExt_ctYrCAN;
   uint16 u16LocalExt_ctDayCAN;
   uint32 u32LocalExt_ctSecCAN;
   uint32 u32LocalMult1;
   uint32 u32LocalMult2;
   uint32 u32LocalSomme;
   uint32 u32LocalMod;
   uint32 u32Localtest1;
   uint32 u32Localtest3;
   uint32 u32Localtest4;
   uint32 u32Localtest5;
   uint32 u32LocalDenum;

   VEMS_vidGET(Ext_ctYrCAN, u8LocalExt_ctYrCAN);
   VEMS_vidGET(Ext_ctDayCAN, u16LocalExt_ctDayCAN);
   VEMS_vidGET(Ext_ctSecCAN, u32LocalExt_ctSecCAN);
   if (   (TiCt_ctDayInYr_C != 0)
       && (TiCt_ctSecInDay_C != 0 )
       && (u8LocalExt_ctYrCAN != 0))
   {
      u32LocalDenum = (uint32)(u8LocalExt_ctYrCAN * TiCt_ctDayInYr_C);
      u32Localtest1 = UINT32_MAX / u32LocalDenum;
      if (TiCt_ctSecInDay_C >= u32Localtest1)
      {
         u32LocalMult1 = UINT32_MAX;
      }
      else
      {
         u32LocalMult1 = TiCt_ctSecInDay_C * u32LocalDenum;
      }
   }
   else
   {
      u32LocalMult1 = 0;
   }
   if (  (u16LocalExt_ctDayCAN != 0)
      && (TiCt_ctSecInDay_C != 0))
   {
      u32Localtest3 = (UINT32_MAX / (uint32)u16LocalExt_ctDayCAN);
      if (TiCt_ctSecInDay_C >= u32Localtest3)
      {
         u32LocalMult2 = UINT32_MAX;
      }
      else
      {
         u32LocalMult2 = u16LocalExt_ctDayCAN * TiCt_ctSecInDay_C;
      }
   }
   else
   {
      u32LocalMult2 = 0;
   }
   u32Localtest4 = (UINT32_MAX - u32LocalMult2);
   if (u32LocalMult1 >= u32Localtest4)
   {
      u32LocalSomme = UINT32_MAX;
   }
   else
   {
      u32LocalSomme = u32LocalMult1 + u32LocalMult2;
      /*ERROR QAC Msg(3:3382) couldn't happen:
         this part of code is protected by the if test*/
      u32Localtest5 = UINT32_MAX - u32LocalExt_ctSecCAN;
      if (u32LocalSomme >= u32Localtest5)
      {
         u32LocalSomme = UINT32_MAX;
      }
      else
      {
         u32LocalSomme = (u32LocalSomme + u32LocalExt_ctSecCAN);
      }
   }
   u32LocalMod = (u32LocalSomme % 429496729UL);
   Ext_tiCurVeh2004 = (u32LocalMod * 10);
}
/*------------------------------- end of file --------------------------------*/