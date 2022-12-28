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
/* !File            : FLOWMNG_FCT5.C                                          */
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
/*   1 / FLOWMNG_vidDayCtMng_EEPROM                                           */
/*   2 / FLOWMNG_vidTqSel                                                     */
/*   3 / FLOWMNG_vidAltFlowMng_Init                                           */
/*   4 / FLOWMNG_vidAltFlowMng_Processing                                     */
/*   5 / FLOWMNG_vidAlt_Duty_Cycle                                            */
/*   6 / FLOWMNG_vidAlt_Current                                               */
/*   7 / FLOWMNG_vidAlt_ID_Supplier                                           */
/*   8 / FLOWMNG_vidAlt_Voltage                                               */
/*   9 / FLOWMNG_vidAlt_Shut_Off                                              */
/*   10 / FLOWMNG_vidAlt_Load_Time                                            */
/*                                                                            */
/* !Reference   : PTS_DOC_5068508 / 06                                        */
/* !OtherRefs   : VEMS V02 ECU#067763                                         */
/* !OtherRefs   : VEMS V02 ECU#067819                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/FLOWMNG/FLOWMNG_FCT5.C_v        $*/
/* $Revision::   1.18     $$Author::   HHAMLAOU       $$Date::   10 Dec 2013 $*/
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
/* !Function    :  FLOWMNG_vidDayCtMng_EEPROM                                 */
/* !Description :  Fonction sauvegardant la valeur du compteur secondes, jours*/
/*                 et années au powerlatch                                    */
/* !Number      :  FCT5.1                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_018.02                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input uint32 Ext_ctSec;                                                   */
/*  input uint16 Ext_ctDay;                                                   */
/*  input uint8 Ext_ctYr;                                                     */
/*  input uint32 Ext_tiCurVehTmr;                                             */
/*  input uint32 Ext_tiCurVeh2004;                                            */
/*  output uint8 Ext_ctYrPwrl;                                                */
/*  output uint16 Ext_ctDayPwrl;                                              */
/*  output uint32 Ext_ctSecPwrl;                                              */
/*  output uint32 Ext_ctVehPwrl;                                              */
/*  output uint32 Ext_ctVehPwrl2004;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidDayCtMng_EEPROM(void)
{
   uint8  u8LocalExt_ctYr;
   uint16 u16LocalExt_ctDay;
   uint32 u32LocalExt_tiCurVehTmr;
   uint32 u32LocalExt_ctSec;


   VEMS_vidGET(Ext_ctSec, u32LocalExt_ctSec);
   VEMS_vidGET(Ext_ctDay, u16LocalExt_ctDay);
   VEMS_vidGET(Ext_ctYr, u8LocalExt_ctYr);
   VEMS_vidGET(Ext_tiCurVehTmr, u32LocalExt_tiCurVehTmr);

   Ext_ctYrPwrl  = (uint8)MATHSRV_udtMIN(u8LocalExt_ctYr, 101);
   Ext_ctDayPwrl = (uint16)MATHSRV_udtMIN(u16LocalExt_ctDay, 365);
   Ext_ctSecPwrl = MATHSRV_udtMIN(u32LocalExt_ctSec, 586639);
   Ext_ctVehPwrl = MATHSRV_udtMIN(u32LocalExt_tiCurVehTmr, 4294967293UL);
   if (Ext_tiCurVeh2004 > 4294967290UL)
   {
      Ext_ctVehPwrl2004 = 429496729;
   }
   else
   {
      Ext_ctVehPwrl2004 = (Ext_tiCurVeh2004 + 5) / 10;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidTqSel                                           */
/* !Description :  Fonction qui specifie la selection du flux pour le torque  */
/*                 C2000                                                      */
/* !Number      :  FCT5.2                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_024.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16channel)boolean;           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stGBxCf;                                                  */
/*  input sint16 Ext_tqCkCAN;                                                 */
/*  input uint32 Eng_nEng;                                                    */
/*  input uint16 TqCnvClu_nEngNorm_C;                                         */
/*  input sint16 TqCnvClu_tqRcvVal_C;                                         */
/*  output sint16 Tra_tqCnvClu;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidTqSel(void)
{
   boolean bLocalFRM_bDft_nEngMv;
   boolean bLocalFRM_bDft_tqCkCAN;
   uint8   u8LocalExt_stGBxCf;
   uint16  u16LocalABS;
   sint16  s16LocalExt_tqCkCAN;
   sint16  s16LocalTra_tqCnvClu;
   uint32  u32LocalEng_nEng;
   uint32  u32LocalEng_nEng0;
   uint32  u32LocalDiv1;
   uint32  u32LocalModulo;
   uint32  u32LocalResidus;
   uint32  u32LocalTest;
   uint32  u32LocalTra_tqCnvClu;
   uint32  u32LocalTra_tqCnvClu2;


   VEMS_vidGET(Ext_stGBxCf, u8LocalExt_stGBxCf);
   bLocalFRM_bDft_nEngMv = GDGAR_bGetFRM(FRM_FRM_DFT_NENGMV);
   bLocalFRM_bDft_tqCkCAN = GDGAR_bGetFRM(FRM_FRM_DFT_TQCKCAN);

   if (  (u8LocalExt_stGBxCf == BVA)
      && (bLocalFRM_bDft_nEngMv == 0)
      && (bLocalFRM_bDft_tqCkCAN == 0))
   {
      VEMS_vidGET(Ext_tqCkCAN, s16LocalExt_tqCkCAN);
      VEMS_vidGET(Eng_nEng, u32LocalEng_nEng);

      u32LocalEng_nEng0 = u32LocalEng_nEng / 128;
      u32LocalModulo = u32LocalEng_nEng % 128;
      u32LocalEng_nEng0 = (  u32LocalEng_nEng0 * 125)
                          + ( ( (u32LocalModulo * 125)
                              + 64)
                             / 128);

      if (  (s16LocalExt_tqCkCAN != 0)
         && (u32LocalEng_nEng0 != 0))
      {
         if (TqCnvClu_nEngNorm_C != 0)
         {

            u32LocalDiv1 = (u32LocalEng_nEng0 / TqCnvClu_nEngNorm_C);
            if (u32LocalDiv1 >= 65536)
            {
               u32LocalTra_tqCnvClu = 32000;
            }
            else
            {
               u16LocalABS = (uint16)MATHSRV_udtABS(s16LocalExt_tqCkCAN);
               u32LocalModulo = (u32LocalEng_nEng0 % TqCnvClu_nEngNorm_C);

               u32LocalResidus = ( u32LocalModulo * (uint32)u16LocalABS)
                               / TqCnvClu_nEngNorm_C;

               u32LocalTra_tqCnvClu = ( u32LocalDiv1
                                      * (uint32)u16LocalABS)
                                    + u32LocalResidus;

               u32LocalTest = (UINT32_MAX / u32LocalEng_nEng0);
               if (u32LocalTra_tqCnvClu < u32LocalTest)
               {
                  u32LocalTra_tqCnvClu = ( u32LocalTra_tqCnvClu
                                         * u32LocalEng_nEng0)
                                       / TqCnvClu_nEngNorm_C;
                  u32LocalTra_tqCnvClu = (u32LocalTra_tqCnvClu + 1) / 2;
               }
               else
               {
                  u32LocalTra_tqCnvClu2 =
                     u32LocalTra_tqCnvClu / TqCnvClu_nEngNorm_C;

                  if (u32LocalTra_tqCnvClu2 < u32LocalTest)
                  {
                     u32LocalModulo =
                        (u32LocalTra_tqCnvClu % TqCnvClu_nEngNorm_C);

                     u32LocalResidus = ( ( u32LocalModulo
                                         * ((u32LocalEng_nEng0 + 260) / 520))
                                       / TqCnvClu_nEngNorm_C) * 520;

                     u32LocalTra_tqCnvClu = ( ( u32LocalTra_tqCnvClu2
                                              * u32LocalEng_nEng0)
                                            + u32LocalResidus)
                                          / 2;
                  }
                  else
                  {
                     u32LocalTra_tqCnvClu = 32000;
                  }
               }
            }
         }
         else
         {
            u32LocalTra_tqCnvClu = 32000;
         }
      }
      else
      {
         u32LocalTra_tqCnvClu = 0;
      }

      s16LocalTra_tqCnvClu =
         (sint16)MATHSRV_udtMIN(u32LocalTra_tqCnvClu, 32000);

      if (s16LocalExt_tqCkCAN < 0)
      {
         s16LocalTra_tqCnvClu = (sint16)((-1) * s16LocalTra_tqCnvClu);
      }
   }
   else
   {
      s16LocalTra_tqCnvClu =
         (sint16)MATHSRV_udtCLAMP(TqCnvClu_tqRcvVal_C, -2000, 2000);

      s16LocalTra_tqCnvClu = (sint16)(s16LocalTra_tqCnvClu * 16);
   }
   VEMS_vidSET(Tra_tqCnvClu, s16LocalTra_tqCnvClu);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAltFlowMng_Init                                 */
/* !Description :  Fonction qui initialise les variables de sorties sur       */
/*                 évenement de RESET,                                        */
/* !Number      :  FCT5.3                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint16 ElProdMgt_uElProdSp_C;                                       */
/*  output uint8 Ext_rAltCycOp;                                               */
/*  output uint8 Ext_iAltExct;                                                */
/*  output uint8 Ext_idxCtlAltProvIdf;                                        */
/*  output uint16 Ext_uAltBSSSp;                                              */
/*  output uint32 AraMth_ctStaAcv;                                            */
/*  output uint16 Ext_uAltLINSp;                                              */
/*  output boolean Ext_bPrgChBSSDi_nEng;                                      */
/*  output uint8 Ext_stPrgChLINDi_nEng;                                       */
/*  output uint8 Ext_stPrgBSSCh;                                              */
/*  output uint8 Ext_stPrgLINCh;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAltFlowMng_Init(void)
{
   uint16 u16LocalElProdMgt_uElProdSp_C;

   u16LocalElProdMgt_uElProdSp_C =
      (uint16)MATHSRV_udtCLAMP(ElProdMgt_uElProdSp_C, 1060, 1600);
   VEMS_vidSET(Ext_rAltCycOp, 0);
   VEMS_vidSET(Ext_iAltExct, 0);
   VEMS_vidSET(Ext_idxCtlAltProvIdf, OTHER);
   VEMS_vidSET(Ext_uAltBSSSp, 0);
   VEMS_vidSET(AraMth_ctStaAcv, 0);
   VEMS_vidSET(Ext_uAltLINSp, u16LocalElProdMgt_uElProdSp_C);
   VEMS_vidSET(Ext_bPrgChBSSDi_nEng, 1);
   VEMS_vidSET(Ext_stPrgChLINDi_nEng, PRODPRGCHDI_NENG_04);
   VEMS_vidSET(Ext_stPrgBSSCh, EXT_STPRGBSSCH_1);
   VEMS_vidSET(Ext_stPrgLINCh, PRODPRGCH_07);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAltFlowMng_Processing                           */
/* !Description :  Cette fonction traite : Gneric Duty cycle, Generic         */
/*                 excitation current, Generic identifier supplier, Voltage   */
/*                 request, Shut off value dependant of crankshaft speed,     */
/*                 Progressive load  time                                     */
/* !Number      :  FCT5.4                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/* !Trace_To    :  VEMS_R_11_00339_025.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void FLOWMNG_vidAlt_Duty_Cycle();                             */
/*  extf argret void FLOWMNG_vidAlt_Current();                                */
/*  extf argret void FLOWMNG_vidAlt_ID_Supplier();                            */
/*  extf argret void FLOWMNG_vidAlt_Voltage();                                */
/*  extf argret void FLOWMNG_vidAlt_Shut_Off();                               */
/*  extf argret void FLOWMNG_vidAlt_Load_Time();                              */
/*  extf argret void FLOWMNG_vidAlt_Cpt_Dem_Redem();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAltFlowMng_Processing(void)
{
   FLOWMNG_vidAlt_Duty_Cycle();
   FLOWMNG_vidAlt_Current();
   FLOWMNG_vidAlt_ID_Supplier();
   FLOWMNG_vidAlt_Voltage();
   FLOWMNG_vidAlt_Shut_Off();
   FLOWMNG_vidAlt_Load_Time();
   FLOWMNG_vidAlt_Cpt_Dem_Redem();
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Duty_Cycle                                  */
/* !Description :  Fonction qui determine le duty cycle de l'aternateur       */
/*                 dependament de son type et des types de communication BSS  */
/*                 et LIN,                                                    */
/* !Number      :  FCT5.5                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_rAltCycOpStd;                                             */
/*  input uint8 Ext_rCtlAltBSSCycOp;                                          */
/*  input uint8 Ext_rCtlAltLINCycOp;                                          */
/*  input uint8 Ext_rRvAltCycOp;                                              */
/*  input uint8 Ext_rAltCycOp;                                                */
/*  output uint8 Ext_rAltCycOp;                                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Duty_Cycle(void)
{
   uint8  u8LocalExt_stEIProdCf;
   uint8  u8LocalExt_stDrivAltMgt_Cf;
   uint8  u8LocalExt_rAltCycOpStd;
   uint8  u8LocalExt_rCtlAltBSSCycOp;
   uint8  u8LocalExt_rCtlAltLINCycOp;
   uint8  u8LocalExt_rRvAltCycOp;
   uint8  u8LocalExt_rAltCycOp;
   uint16 u16LocalExt_rAltCycOp_Mult;
   uint16 u16LocalExt_rRvAltCycOp;

   VEMS_vidGET(Ext_stElProdCf, u8LocalExt_stEIProdCf);
   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   VEMS_vidGET(Ext_rAltCycOpStd, u8LocalExt_rAltCycOpStd);
   VEMS_vidGET(Ext_rCtlAltBSSCycOp, u8LocalExt_rCtlAltBSSCycOp);
   VEMS_vidGET(Ext_rCtlAltLINCycOp, u8LocalExt_rCtlAltLINCycOp);
   VEMS_vidGET(Ext_rRvAltCycOp, u8LocalExt_rRvAltCycOp);

   if (  (u8LocalExt_stEIProdCf == EIPRODCF_ALTSTD)
      && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_NOSUBNET))
   {
      u8LocalExt_rAltCycOp =
         (uint8)MATHSRV_udtMIN(u8LocalExt_rAltCycOpStd, 100);
      VEMS_vidSET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
   }
   else
   {
      if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
      {
         u16LocalExt_rAltCycOp_Mult =
            (uint16)(u8LocalExt_rCtlAltBSSCycOp * 100);
         u16LocalExt_rAltCycOp_Mult = (uint16)(u16LocalExt_rAltCycOp_Mult / 31);
         u8LocalExt_rAltCycOp =
            (uint8)MATHSRV_udtMIN(u16LocalExt_rAltCycOp_Mult, 100);
         VEMS_vidSET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
      }
      else
      {
         if (   (u8LocalExt_stEIProdCf == EIPRODCF_ALTDRV)
            && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
         {
            u8LocalExt_rAltCycOp =
               (uint8)MATHSRV_udtMIN(u8LocalExt_rCtlAltLINCycOp, 100);
            VEMS_vidSET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
         }
         else
         {
            if (   (u8LocalExt_stEIProdCf == EIPRODCF_ALTRV)
               && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
            {
               u16LocalExt_rRvAltCycOp = (uint16)(u8LocalExt_rRvAltCycOp * 143);
               u16LocalExt_rRvAltCycOp = (uint16)(u16LocalExt_rRvAltCycOp / 10);
               u8LocalExt_rAltCycOp =
                  (uint8)MATHSRV_udtMIN(u16LocalExt_rRvAltCycOp, 100);
               VEMS_vidSET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
            }
            else
            {
               VEMS_vidGET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
               u8LocalExt_rAltCycOp =
                  (uint8)MATHSRV_udtMIN(u8LocalExt_rAltCycOp, 100);
               VEMS_vidSET(Ext_rAltCycOp, u8LocalExt_rAltCycOp);
            }
         }
      }
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Current                                     */
/* !Description :  Fonction qui determine le courant d'exitation de           */
/*                 l'alternateur dependament du type de l'alternateur et des  */
/*                 types de communication BSS et LIN                          */
/* !Number      :  FCT5.6                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_iCtlAltBSSExct;                                           */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint8 Ext_iCtlAltLINExct;                                           */
/*  input uint8 Ext_iRvAltExct;                                               */
/*  input uint8 Ext_iAltExct;                                                 */
/*  output uint8 Ext_iAltExct;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Current(void)
{
   uint8  u8LocalExt_stEIProdCf;
   uint8  u8LocalExt_stDrivAltMgt_Cf;
   uint8  u8LocalExt_iCtlAltBSSExct;
   uint8  u8LocalExt_iCtlAltLINExct;
   uint8  u8LocalExt_iRvAltExct;
   uint8  u8LocalExt_iAltExct;
   uint16 u16LocalExt_iAltExct;

   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);

   if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
   {
      VEMS_vidGET(Ext_iCtlAltBSSExct, u8LocalExt_iCtlAltBSSExct);
      u16LocalExt_iAltExct =(uint16)((u8LocalExt_iCtlAltBSSExct * 5) / 4);
      u8LocalExt_iAltExct = (uint8)MATHSRV_udtMIN(u16LocalExt_iAltExct, 254);
   }
   else
   {
      VEMS_vidGET(Ext_stElProdCf, u8LocalExt_stEIProdCf);
      if (  (u8LocalExt_stEIProdCf == EIPRODCF_ALTDRV)
         && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
      {
         VEMS_vidGET(Ext_iCtlAltLINExct, u8LocalExt_iCtlAltLINExct);
         u16LocalExt_iAltExct = (uint16)((u8LocalExt_iCtlAltLINExct * 5) / 4);
         u8LocalExt_iAltExct = (uint8)MATHSRV_udtMIN(u16LocalExt_iAltExct, 254);
      }
      else
      {
         if (  (u8LocalExt_stEIProdCf == EIPRODCF_ALTRV)
            && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
         {
            VEMS_vidGET(Ext_iRvAltExct, u8LocalExt_iRvAltExct);
            u8LocalExt_iAltExct =
               (uint8)MATHSRV_udtMIN(u8LocalExt_iRvAltExct, 254);
         }
         else
         {
            VEMS_vidGET(Ext_iAltExct, u8LocalExt_iAltExct);
            u8LocalExt_iAltExct =
               (uint8)MATHSRV_udtMIN(u8LocalExt_iAltExct, 254);
         }
      }
   }
   VEMS_vidSET(Ext_iAltExct, u8LocalExt_iAltExct);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_ID_Supplier                                 */
/* !Description :  Fonction qui traite l'identificateur du fournisseur de     */
/*                 l'alternateur en fonction du type de l'aternateur et des   */
/*                 types de communication BSS et LIN                          */
/* !Number      :  FCT5.7                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_idxCtlAltBSSProvIdf;                                      */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint8 Ext_idxCtlAltLINProvIdf;                                      */
/*  input uint8 Ext_idxCtlAltProvIdf;                                         */
/*  output uint8 Ext_idxCtlAltProvIdf;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_ID_Supplier(void)
{
   uint8 u8LocalExt_stDrivAltMgt_Cf;
   uint8 u8LocalExt_idxCtlAltBSSProvIdf;
   uint8 u8LocalExt_stEIProdCf;
   uint8 u8LocalExt_idxCtlAltLINProvIdf;
   uint8 u8LocalExt_idxCtlAltProvIdf;

   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);

   if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
   {
      VEMS_vidGET(Ext_idxCtlAltBSSProvIdf, u8LocalExt_idxCtlAltBSSProvIdf);
      u8LocalExt_idxCtlAltProvIdf =
         (uint8)MATHSRV_udtMIN(u8LocalExt_idxCtlAltBSSProvIdf, 7);
   }
   else
   {
      VEMS_vidGET(Ext_stElProdCf, u8LocalExt_stEIProdCf);
      if (  (u8LocalExt_stEIProdCf == EIPRODCF_ALTDRV)
         && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
      {
         VEMS_vidGET(Ext_idxCtlAltLINProvIdf, u8LocalExt_idxCtlAltLINProvIdf);
         u8LocalExt_idxCtlAltProvIdf =
            (uint8)MATHSRV_udtMIN(u8LocalExt_idxCtlAltLINProvIdf, 7);
      }
      else
      {
         VEMS_vidGET(Ext_idxCtlAltProvIdf, u8LocalExt_idxCtlAltProvIdf);
         u8LocalExt_idxCtlAltProvIdf =
            (uint8)MATHSRV_udtMIN(u8LocalExt_idxCtlAltProvIdf, 7);
      }
   }
   VEMS_vidSET(Ext_idxCtlAltProvIdf, u8LocalExt_idxCtlAltProvIdf);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Voltage                                     */
/* !Description :  Fonction qui détermine le voltage de l'alternateur en      */
/*                 fonction des deux types de communication BSS et LIN,       */
/* !Number      :  FCT5.8                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint16 ElProdMgt_uElProdSp;                                         */
/*  input uint16 ElProdMgt_uElProdSp_C;                                       */
/*  input uint16 Ext_uAltBSSSp;                                               */
/*  input uint16 Ext_uAltLINSp;                                               */
/*  output uint16 Ext_uAltBSSSp;                                              */
/*  output uint16 Ext_uAltLINSp;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Voltage(void)
{
   uint8  u8LocalExt_stDrivAltMgt_Cf;
   uint16 u16LocalElProdMgt_uElProdSp;
   uint16 u16LocalExt_stEIProdCf;
   uint16 u16LocalExt_uAltBSSSp;
   uint16 u16LocalExt_uAltLINSp;
   uint32 u32LocalSum1;
   uint32 u32LocalSum2;

   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   VEMS_vidGET(Ext_stElProdCf, u16LocalExt_stEIProdCf);
   VEMS_vidGET(ElProdMgt_uElProdSp, u16LocalElProdMgt_uElProdSp);
   if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
   {
      u32LocalSum1 = u16LocalElProdMgt_uElProdSp * 25;
      u32LocalSum2 = ElProdMgt_uElProdSp_C * 32;
      if (u32LocalSum1 > u32LocalSum2)
      {

         u16LocalExt_uAltBSSSp = (uint16)( ( ( u32LocalSum1
                                             - u32LocalSum2)
                                           + 16)
                                         / 32);
      }
      else
      {
         u16LocalExt_uAltBSSSp = 0;
      }
   }
   else
   {
      VEMS_vidGET(Ext_uAltBSSSp, u16LocalExt_uAltBSSSp);
   }
   u16LocalExt_uAltBSSSp = (uint16)MATHSRV_udtMIN(u16LocalExt_uAltBSSSp, 540);
   VEMS_vidSET(Ext_uAltBSSSp, u16LocalExt_uAltBSSSp);

   if (  (u16LocalExt_stEIProdCf == EIPRODCF_ALTDRV)
      && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
   {
      u16LocalExt_uAltLINSp = (uint16)((u16LocalElProdMgt_uElProdSp * 25) / 32);
      u16LocalExt_uAltLINSp =
         (uint16)MATHSRV_udtCLAMP(u16LocalExt_uAltLINSp, 1060, 1600);
   }
   else
   {
      VEMS_vidGET(Ext_uAltLINSp, u16LocalExt_uAltLINSp);
      u16LocalExt_uAltLINSp =
         (uint16)MATHSRV_udtCLAMP(u16LocalExt_uAltLINSp, 1060, 1600);
   }
   VEMS_vidSET(Ext_uAltLINSp, u16LocalExt_uAltLINSp);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Shut_Off                                    */
/* !Description :  Fonction qui détermine la valeur de d'arrêt de             */
/*                 l'alternateur en fonction de BSS et LIN et détermine la    */
/*                 sortie Ext_stPrgChLINDi_nEng en fonction de la vitesse du  */
/*                 vilbroquin                                                 */
/* !Number      :  FCT5.9                                                     */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 ElProdMgt_stProdPrgChDi_nEng;                                 */
/*  input uint8 Ext_stElProdCf;                                               */
/*  output boolean Ext_bPrgChBSSDi_nEng;                                      */
/*  output uint8 Ext_stPrgChLINDi_nEng;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Shut_Off(void)
{

   boolean bLocalExt_bPrgChBSSDi_nEng;
   uint8   u8LocalExt_stDrivAltMgt_Cf;
   uint8   u8LocalElProMgt_stProPgChDi_nEng;
   uint16  u16LocalExt_stEIProdCf;

   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   VEMS_vidGET(ElProdMgt_stProdPrgChDi_nEng, u8LocalElProMgt_stProPgChDi_nEng);
   VEMS_vidGET(Ext_stElProdCf, u16LocalExt_stEIProdCf);

   if (  (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
      && (u8LocalElProMgt_stProPgChDi_nEng == PRODPRGCHDI_NENG_15))
   {
      bLocalExt_bPrgChBSSDi_nEng = 0;
      VEMS_vidSET(Ext_bPrgChBSSDi_nEng, bLocalExt_bPrgChBSSDi_nEng);
   }
   else
   {
      if (  (u8LocalElProMgt_stProPgChDi_nEng != PRODPRGCHDI_NENG_15)
         && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS))
      {
         bLocalExt_bPrgChBSSDi_nEng = 1;
         VEMS_vidSET(Ext_bPrgChBSSDi_nEng, bLocalExt_bPrgChBSSDi_nEng);
      }
   }

   if (  (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN)
      && (u16LocalExt_stEIProdCf == EIPRODCF_ALTDRV))
   {
      VEMS_vidSET(Ext_stPrgChLINDi_nEng, u8LocalElProMgt_stProPgChDi_nEng);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  FLOWMNG_vidAlt_Load_Time                                   */
/* !Description :  Fonction qui traite le temps de chargement progressive de  */
/*                 l'alternateur en fonction du type de l'alternateur et des  */
/*                 types de communication BSS et LIN,                         */
/* !Number      :  FCT5.10                                                    */
/* !Author      :  A.BEN ZAYED                                                */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void FLOWMNG_vidAlt_Bss_Load_Time();                          */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Ext_stDrivAltMgt_Cf;                                          */
/*  input uint8 Ext_stElProdCf;                                               */
/*  input uint8 ElProdMgt_stProdPrgCh;                                        */
/*  output uint8 Ext_stPrgLINCh;                                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void FLOWMNG_vidAlt_Load_Time(void)
{
   uint8  u8LocalExt_stDrivAltMgt_Cf;
   uint8  u8LocalElProdMgt_stProdPrgCh;
   uint8  u8LocalExt_stPrgLINCh;
   uint16 u16LocalExt_stEIProdCf;

   VEMS_vidGET(Ext_stDrivAltMgt_Cf, u8LocalExt_stDrivAltMgt_Cf);
   VEMS_vidGET(Ext_stElProdCf, u16LocalExt_stEIProdCf);

   if (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_BSS)
   {
      FLOWMNG_vidAlt_Bss_Load_Time();
   }
   if (  (u16LocalExt_stEIProdCf == EIPRODCF_ALTDRV)
      && (u8LocalExt_stDrivAltMgt_Cf == DRIVALTMGT_LIN))
   {
      VEMS_vidGET(ElProdMgt_stProdPrgCh, u8LocalElProdMgt_stProdPrgCh);
      u8LocalExt_stPrgLINCh = u8LocalElProdMgt_stProdPrgCh;
      VEMS_vidSET(Ext_stPrgLINCh, u8LocalExt_stPrgLINCh);
   }
}
/*------------------------------- end of file --------------------------------*/