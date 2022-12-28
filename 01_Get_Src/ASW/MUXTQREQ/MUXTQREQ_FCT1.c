/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : MUXTQREQ                                                */
/* !Description     : MUXTQREQ Component                                      */
/*                                                                            */
/* !Module          : MUXTQREQ                                                */
/* !Description     : GESTION DES CONSIGNES DE COUPLE POUR L'INTER-SYSTEMES EN*/
/*                    MODE DEGRADE MOTEUR                                     */
/*                                                                            */
/* !File            : MUXTQREQ_FCT1.C                                         */
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
/*   1 / MUXTQREQ_vidInit                                                     */
/*   2 / MUXTQREQ_vidInitOutput                                               */
/*   3 / MUXTQREQ_vidEngStOpm                                                 */
/*   4 / MUXTQREQ_vidEngSpdLimLoEfc                                           */
/*   5 / MUXTQREQ_vidEngSpdLimHiEfc                                           */
/*   6 / MUXTQREQ_vidTqLimEfc                                                 */
/*                                                                            */
/* !Reference   : V02 NT 11 08258 / 01                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/MUXTQREQ/MUXTQREQ_FCT1.C_v        $*/
/* $Revision::   1.2      $$Author::   achebino       $$Date::   17 Jul 2012 $*/
/* $Author::   achebino                               $$Date::   17 Jul 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "MUXTQREQ.h"
#include "MUXTQREQ_L.h"
#include "MUXTQREQ_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidInit                                           */
/* !Description :  fonction d'intialisation des sorties                       */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  S.Walha                                                    */
/* !Trace_To    :  VEMS_R_11_08258_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output st16 REOM_stEngOpm;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidInit(void)
{
   VEMS_vidSET(REOM_stEngOpm, FONCTIONNEMENT_NOMINAL);
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidInitOutput                                     */
/* !Description :  cette fonction permet d'initialiser les sorties de         */
/*                 l'hystheresis                                              */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  S.Walha                                                    */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean MUXTQREQ_bHysEngHi;                                        */
/*  output boolean MUXTQREQ_bHysEngLo;                                        */
/*  output boolean MUXTQREQ_bHysTqLimEfc;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidInitOutput(void)
{
   MUXTQREQ_bHysEngHi = 0;
   MUXTQREQ_bHysEngLo = 0;
   MUXTQREQ_bHysTqLimEfc = 0;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidEngStOpm                                       */
/* !Description :  cette fonction permet la synthèse des différentes          */
/*                 activations de modes dégradés. Lorsque plusieurs sont      */
/*                 actifs simultanément, seul le plus contraignant est pris en*/
/*                 compte.                                                    */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  S.Walha                                                    */
/* !Trace_To    :  VEMS_R_11_08258_004.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  extf argret void MUXTQREQ_vidEngSpdLimLoEfc();                            */
/*  extf argret void MUXTQREQ_vidEngSpdLimHiEfc();                            */
/*  extf argret void MUXTQREQ_vidTqLimEfc();                                  */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Ext_bCdnEngSpdLimLoEfc;                                     */
/*  input boolean Ext_bCdnEngSpdLimHiEfc;                                     */
/*  input boolean Ext_bCdnTqLimEfc;                                           */
/*  output st10 REOM_stEngOpm;                                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidEngStOpm(void)
{
   boolean bLocalEngSpdLimHiIntv;
   boolean bLocalEngSpdLimLoIntv;
   boolean bLocalAcvIrvLihPed;
   boolean bLocalAcvRvVstLihPed;
   boolean bLocalAcvRvLihPed;
   boolean bLocalAcvTqLim;


   bLocalAcvIrvLihPed = GDGAR_bGetFRM(FRM_FRM_ACVIRVLIHPED);
   bLocalAcvRvVstLihPed = GDGAR_bGetFRM(FRM_FRM_ACVRVVSTLIHPED);
   bLocalAcvRvLihPed = GDGAR_bGetFRM(FRM_FRM_ACVRVLIHPED);
   bLocalEngSpdLimLoIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMLOINTV);
   bLocalEngSpdLimHiIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMHIINTV);
   bLocalAcvTqLim = GDGAR_bGetFRM(FRM_FRM_ACVTQLIM);

   MUXTQREQ_vidEngSpdLimLoEfc();
   MUXTQREQ_vidEngSpdLimHiEfc();
   MUXTQREQ_vidTqLimEfc();

   if (  (bLocalEngSpdLimHiIntv != 0)
      || (bLocalEngSpdLimLoIntv != 0)
      || (bLocalAcvIrvLihPed != 0)
      || (bLocalAcvRvVstLihPed != 0)
      || (bLocalAcvRvLihPed != 0)
      || (bLocalAcvTqLim != 0))
   {
      if (  (bLocalAcvIrvLihPed != 0)
         || (bLocalAcvRvVstLihPed != 0)
         || (bLocalAcvRvLihPed != 0))
      {
         VEMS_vidSET(REOM_stEngOpm, REGUL_REGIME);
      }
      else
      {
         if (bLocalEngSpdLimLoIntv != 0)
         {
            if (Ext_bCdnEngSpdLimLoEfc != 0)
            {
               VEMS_vidSET(REOM_stEngOpm, LIM_REGIME_SEV_EFFECTIVE);
            }
            else
            {
               VEMS_vidSET(REOM_stEngOpm, LIM_REGIME_SEV);
            }
         }
         else
         {
            if (bLocalEngSpdLimHiIntv != 0)
            {
               if (Ext_bCdnEngSpdLimHiEfc != 0)
               {
                  VEMS_vidSET(REOM_stEngOpm, LIM_REGIME_EFFECTIVE);
               }
               else
               {
                  VEMS_vidSET(REOM_stEngOpm, LIM_REGIME);
               }
            }
            else
            {
               if (Ext_bCdnTqLimEfc != 0)
               {
                  VEMS_vidSET(REOM_stEngOpm, LIM_CPLE_EFFECTIVE);
               }
               else
               {
                  VEMS_vidSET(REOM_stEngOpm, LIM_CPLE);
               }
            }
         }
      }
   }
   else
   {
      VEMS_vidSET(REOM_stEngOpm, FONCTIONNEMENT_NOMINAL);
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidEngSpdLimLoEfc                                 */
/* !Description :  dans cette fonction on  teste les conditions pour la       */
/*                 limitation de régime sévère.                               */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  S.Walha                                                    */
/* !Trace_To    :  VEMS_R_11_08258_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint8 CoPt_noGearCord_Sfty;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 CoPt_noGearCord_Sfty_AX[8];                                   */
/*  input uint8 EngSt_EngSpdLimLoThd_T[8];                                    */
/*  input sint16 Ext_nEngSpdLimLoOfs_C;                                       */
/*  input boolean MUXTQREQ_bHysEngLo;                                         */
/*  output boolean MUXTQREQ_bHysEngLo;                                        */
/*  output boolean Ext_bCdnEngSpdLimLoEfc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidEngSpdLimLoEfc(void)
{
   boolean bLocalEngSpdLimLoIntv;
   uint8   u8LocalCoPt_noGearCord;
   uint16  u16LocalCoPtPara;
   uint16  u16LocalinterpLimLoThd;
   uint16  u16LocalExt_nEng;
   sint32  s32LocalThreshold1;
   sint32  s32LocalThreshold2;


   VEMS_vidGET(CoPt_noGearCord_Sfty, u8LocalCoPt_noGearCord);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalEngSpdLimLoIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMLOINTV);

   u16LocalCoPtPara = MATHSRV_u16CalcParaIncAryU8(CoPt_noGearCord_Sfty_AX,
                                                  u8LocalCoPt_noGearCord,
                                                  8);
   u16LocalinterpLimLoThd = MATHSRV_u8Interp1d(EngSt_EngSpdLimLoThd_T,
                                                u16LocalCoPtPara);
   s32LocalThreshold1 = (u16LocalinterpLimLoThd * 32) - Ext_nEngSpdLimLoOfs_C;
   s32LocalThreshold2 = (u16LocalinterpLimLoThd * 32) + Ext_nEngSpdLimLoOfs_C;
   if (MUXTQREQ_bHysEngLo == 0)
   {
      if (u16LocalExt_nEng >= s32LocalThreshold2)
      {
         MUXTQREQ_bHysEngLo = 1;
      }
      else
      {
         MUXTQREQ_bHysEngLo = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32LocalThreshold1)
      {
         MUXTQREQ_bHysEngLo = 0;
      }
      else
      {
         MUXTQREQ_bHysEngLo = 1;
      }
   }
   if (  (bLocalEngSpdLimLoIntv != 0)
      && (MUXTQREQ_bHysEngLo != 0))
   {
      Ext_bCdnEngSpdLimLoEfc = 1;
   }
   else
   {
      Ext_bCdnEngSpdLimLoEfc = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidEngSpdLimHiEfc                                 */
/* !Description :  dans cette fonction On teste ici les conditions pour la    */
/*                 limitation de régime.                                      */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  S.Walha                                                    */
/* !Trace_To    :  VEMS_R_11_08258_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input uint8 CoPt_noGearCord_Sfty;                                         */
/*  input uint16 Ext_nEng;                                                    */
/*  input uint8 CoPt_noGearCord_Sfty_AX[8];                                   */
/*  input uint8 EngSt_EngSpdLimHiThd_T[8];                                    */
/*  input sint16 Ext_nEngSpdLimHiOfs_C;                                       */
/*  input boolean MUXTQREQ_bHysEngHi;                                         */
/*  output boolean MUXTQREQ_bHysEngHi;                                        */
/*  output boolean Ext_bCdnEngSpdLimHiEfc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidEngSpdLimHiEfc(void)
{
   boolean bLocalEngSpdLimHiIntv;
   uint8   u8LocalCoPt_noGearCord;
   uint16  u16LocalCoPtPara;
   uint16  u16LocalinterpLimHiThd;
   uint16  u16LocalExt_nEng;
   sint32  s32LocalThreshold2;
   sint32  s32LocalThreshold1;


   VEMS_vidGET(CoPt_noGearCord_Sfty, u8LocalCoPt_noGearCord);
   VEMS_vidGET(Ext_nEng, u16LocalExt_nEng);
   bLocalEngSpdLimHiIntv = GDGAR_bGetFRM(FRM_FRM_ENGSPDLIMHIINTV);

   u16LocalCoPtPara = MATHSRV_u16CalcParaIncAryU8(CoPt_noGearCord_Sfty_AX,
                                                  u8LocalCoPt_noGearCord,
                                                  8);
   u16LocalinterpLimHiThd = MATHSRV_u8Interp1d(EngSt_EngSpdLimHiThd_T,
                                               u16LocalCoPtPara);
   s32LocalThreshold1 = (u16LocalinterpLimHiThd * 32) - Ext_nEngSpdLimHiOfs_C;
   s32LocalThreshold2 = (u16LocalinterpLimHiThd * 32) + Ext_nEngSpdLimHiOfs_C;
   if (MUXTQREQ_bHysEngHi == 0)
   {
      if (u16LocalExt_nEng >= s32LocalThreshold2)
      {
         MUXTQREQ_bHysEngHi = 1;
      }
      else
      {
         MUXTQREQ_bHysEngHi = 0;
      }
   }
   else
   {
      if (u16LocalExt_nEng <= s32LocalThreshold1)
      {
         MUXTQREQ_bHysEngHi = 0;
      }
      else
      {
         MUXTQREQ_bHysEngHi = 1;
      }
   }
   if (  (bLocalEngSpdLimHiIntv != 0)
      && (MUXTQREQ_bHysEngHi != 0))
   {
      Ext_bCdnEngSpdLimHiEfc = 1;
   }
   else
   {
      Ext_bCdnEngSpdLimHiEfc = 0;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  MUXTQREQ_vidTqLimEfc                                       */
/* !Description :  Dans cette fonction On teste ici les conditions pour la    */
/*                 limitation de couple.                                      */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  S.Walha                                                    */
/* !Trace_To    :  VEMS_R_11_08258_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_bGetFRM(argin uint16 u16IndexFRM)boolean;          */
/*  input sint16 TqSys_tqCkEngReal;                                           */
/*  input sint16 EngLim_tqIdcRed;                                             */
/*  input sint16 Ext_tqLimOfs_C;                                              */
/*  input boolean MUXTQREQ_bHysTqLimEfc;                                      */
/*  output boolean MUXTQREQ_bHysTqLimEfc;                                     */
/*  output boolean Ext_bCdnTqLimEfc;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void MUXTQREQ_vidTqLimEfc(void)
{
   boolean bLocalAcvTqLim;
   sint16  s16LocalTqSys_tqCkEngReal;
   sint16  s16LocalEngLim_tqIdcRed;
   sint32  s32LocalThreshold2;
   sint32  s32LocalThreshold1;


   VEMS_vidGET(TqSys_tqCkEngReal, s16LocalTqSys_tqCkEngReal);
   VEMS_vidGET(EngLim_tqIdcRed, s16LocalEngLim_tqIdcRed);
   bLocalAcvTqLim = GDGAR_bGetFRM(FRM_FRM_ACVTQLIM);

   s32LocalThreshold1 = s16LocalEngLim_tqIdcRed - (Ext_tqLimOfs_C * 16 );
   s32LocalThreshold2 = s16LocalEngLim_tqIdcRed + (Ext_tqLimOfs_C * 16 );
   if (MUXTQREQ_bHysTqLimEfc == 0)
   {
      if (s16LocalTqSys_tqCkEngReal >= s32LocalThreshold2)
      {
         MUXTQREQ_bHysTqLimEfc = 1;
      }
      else
      {
         MUXTQREQ_bHysTqLimEfc = 0;
      }
   }
   else
   {
      if (s16LocalTqSys_tqCkEngReal <= s32LocalThreshold1)
      {
         MUXTQREQ_bHysTqLimEfc = 0;
      }
      else
      {
         MUXTQREQ_bHysTqLimEfc = 1;
      }
   }
   if (  (bLocalAcvTqLim != 0)
      && (MUXTQREQ_bHysTqLimEfc != 0))
   {
      Ext_bCdnTqLimEfc = 1;
   }
   else
   {
      Ext_bCdnTqLimEfc = 0;
   }
}
/******************************* end of file **********************************/