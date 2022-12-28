/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : INFOCRASH                                               */
/* !Description     : INFOCRASH Component                                     */
/*                                                                            */
/* !Module          : INFOCRASH                                               */
/* !Description     : Traitement Information Crash Véhicule                   */
/*                                                                            */
/* !File            : INFOCRASH_FCT1.C                                        */
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
/*   1 / INFOCRASH_vidInit                                                    */
/*   2 / INFOCRASH_vidInitOutput                                              */
/*   3 / INFOCRASH_vidConfirmInfoCrash                                        */
/*   4 / INFOCRASH_vidEndConfirmCrash                                         */
/*   5 / INFOCRASH_vidInhOrAuthInfoCrash                                      */
/*                                                                            */
/* !Reference   : V02 NT 08 07842 / 03                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/RLY/INFOCRASH/INFOCRASH_FCT1.C_v$*/
/* $Revision::   1.1      $$Author::   HHAMLAOU       $$Date::   17 Jun 2013 $*/
/* $Author::   HHAMLAOU                               $$Date::   17 Jun 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.H"
#include "STD_LIMITS.H"
#include "MATHSRV.H"
#include "VEMS.h"
#include "INFOCRASH.H"
#include "INFOCRASH_L.H"
#include "INFOCRASH_IM.H"


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INFOCRASH_vidInit                                          */
/* !Description :  Fonction d'initialisation des sorties au reset             */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_07842_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Crash_fps_confirmed;                                       */
/*  output boolean Crash_fps_detected;                                        */
/*  output uint8 Confirm_crash_count;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INFOCRASH_vidInit(void)
{
   VEMS_vidSET(Crash_fps_confirmed, 0);
   VEMS_vidSET(Crash_fps_detected, 0);
   Confirm_crash_count = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INFOCRASH_vidInitOutput                                    */
/* !Description :  Fonction d'initialisation des sorties au reset             */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Crash_fps_mux;                                              */
/*  output boolean Ext_bVehCollWarnFil;                                       */
/*  output boolean INFOCRASH_bCrashMuxPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/

/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INFOCRASH_vidInitOutput(void)
{
   boolean bLocalCrashFpsMux;


   VEMS_vidSET(Ext_bVehCollWarnFil, 0);
   VEMS_vidGET(Crash_fps_mux, bLocalCrashFpsMux);
   INFOCRASH_bCrashMuxPrev = bLocalCrashFpsMux;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INFOCRASH_vidConfirmInfoCrash                              */
/* !Description :  Dès que l’information CRASH est détectée le compteur       */
/*                 RlyPwr_confirm_crash_count est incrémenté à chaque         */
/*                 réception de trame 4C8h, lorsque le compteur atteint le    */
/*                 seuil max de confirmation, l’information crash devient     */
/*                 confirmée.                                                 */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_07842_003.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Crash_fps_mux;                                              */
/*  input uint8 Step_inc_crash_counter;                                       */
/*  input uint8 Confirm_crash_count;                                          */
/*  output uint8 Confirm_crash_count;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INFOCRASH_vidConfirmInfoCrash(void)
{
   uint16  u16LocalSum;
   boolean bLocalCrashFpsMux;

   VEMS_vidGET(Crash_fps_mux,bLocalCrashFpsMux);

   if (bLocalCrashFpsMux != 0)
   {
      u16LocalSum = (uint16)(Step_inc_crash_counter + Confirm_crash_count);
      Confirm_crash_count = (uint8)(MATHSRV_udtMIN((uint16)UINT8_MAX,
                                                   u16LocalSum));
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INFOCRASH_vidEndConfirmCrash                               */
/* !Description :  Fonction de finalisation de la confirmation information    */
/*                 crash                                                      */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  HHAMLAOU                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  input boolean Crash_fps_mux;                                              */
/*  input uint8 Confirm_crash_count;                                          */
/*  input uint8 Step_dec_crash_counter;                                       */
/*  output uint8 Confirm_crash_count;                                         */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INFOCRASH_vidEndConfirmCrash(void)
{
   sint16  s16LocalDiff;
   boolean bLocalCrashFpsMux;


   VEMS_vidGET(Crash_fps_mux,bLocalCrashFpsMux);

   if (bLocalCrashFpsMux == 0)
   {
      s16LocalDiff = (sint16)(Confirm_crash_count - Step_dec_crash_counter);
      Confirm_crash_count = (uint8)(MATHSRV_udtMAX(s16LocalDiff, 0));
   }
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  INFOCRASH_vidInhOrAuthInfoCrash                            */
/* !Description :  Fonction d'inhibition/autorisation de l'information crash  */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  HHAMLAOU                                                   */
/* !Trace_To    :  VEMS_R_08_07842_002.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  GDGAR_bGetFRM(argin uint16 u16IndexFRM);             */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Crash_fps_mux;                                              */
/*  input boolean INFOCRASH_bCrashMuxPrev;                                    */
/*  input boolean Manu_Inh_info_crash;                                        */
/*  input boolean Crash_fps_confirmed;                                        */
/*  input uint8 Confirm_crash_count;                                          */
/*  input uint8 Thd_crash_absent;                                             */
/*  input uint8 Thd_crash_confirmed;                                          */
/*  output boolean Crash_fps_detected;                                        */
/*  output boolean Crash_fps_confirmed;                                       */
/*  output boolean Ext_bVehCollWarnFil;                                       */
/*  output boolean Ext_bDgoDft_Info_Crash;                                    */
/*  output boolean Ext_bMonRunDft_Info_Crash;                                 */
/*  output boolean INFOCRASH_bCrashMuxPrev;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void INFOCRASH_vidInhOrAuthInfoCrash(void)
{
   boolean  bLocalCrashFpsMux;
   boolean  bLocalAcvCrashCfm;
   boolean  bLocalInh_Info_Crash;
   uint8    u8LocalCrashFpsConfirmed;


   bLocalAcvCrashCfm = GDGAR_bGetFRM(FRM_FRM_ACVCRASHCFM);
   bLocalInh_Info_Crash = GDGAR_bGetFRM(FRM_FRM_INH_INFO_CRASH);
   VEMS_vidGET(Crash_fps_mux, bLocalCrashFpsMux);

   if (  (bLocalAcvCrashCfm != 0)
      && (INFOCRASH_bCrashMuxPrev != 0))
   {
      VEMS_vidSET(Crash_fps_detected, 0);
      VEMS_vidSET(Crash_fps_confirmed, 1);
      VEMS_vidSET(Ext_bVehCollWarnFil, 1);
      Ext_bDgoDft_Info_Crash = 1;
   }
   else
   {
      if (Manu_Inh_info_crash != 0)
      {
         VEMS_vidSET(Crash_fps_detected, 0);
         VEMS_vidSET(Crash_fps_confirmed, 0);
         VEMS_vidSET(Ext_bVehCollWarnFil, 0);
         Ext_bDgoDft_Info_Crash = 0;
      }
      else
      {
         VEMS_vidSET(Crash_fps_detected, bLocalCrashFpsMux);
         VEMS_vidGET(Crash_fps_confirmed, u8LocalCrashFpsConfirmed);
         MATHSRV_vidSchmittTriggerU16( (uint16)(Confirm_crash_count),
                                       (uint16)(Thd_crash_absent),
                                       (uint16)(Thd_crash_confirmed),
                                       MATHSRV_RISING_SCHMITT_TRIGGER,
                                       &u8LocalCrashFpsConfirmed);

         VEMS_vidSET(Ext_bVehCollWarnFil, u8LocalCrashFpsConfirmed);
         Ext_bDgoDft_Info_Crash = u8LocalCrashFpsConfirmed;
         VEMS_vidSET(Crash_fps_confirmed, u8LocalCrashFpsConfirmed);
      }
   }

   if (bLocalInh_Info_Crash != 0)
   {
      Ext_bMonRunDft_Info_Crash = 0;
   }
   else
   {
      Ext_bMonRunDft_Info_Crash = 1;
   }

   INFOCRASH_bCrashMuxPrev = bLocalCrashFpsMux;
}
/*------------------------------- end of file --------------------------------*/