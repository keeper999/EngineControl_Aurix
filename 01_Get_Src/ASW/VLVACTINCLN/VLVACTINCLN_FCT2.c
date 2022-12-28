/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTINCLN                                             */
/* !Description     : VLVACTINCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTINCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ADMISSION         */
/*                                                                            */
/* !File            : VLVACTINCLN_FCT2.C                                      */
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
/*   1 / VLVACTINCLN_vidClnAlgCalc                                            */
/*   2 / VLVACTINCLN_vidClnCnd                                                */
/*   3 / VLVACTINCLN_vidRctCnd                                                */
/*   4 / VLVACTINCLN_vidErrCntRst                                             */
/*   5 / VLVACTINCLN_vidRctClnVarUdt                                          */
/*   6 / VLVACTINCLN_vidRctCndFrtcln                                          */
/*   7 / VLVACTINCLN_vidPctcnd                                                */
/*   8 / VLVACTINCLN_vidPctClnVarUdt                                          */
/*   9 / VLVACTINCLN_vidManCleanVarUpdate                                     */
/*   10 / VLVACTINCLN_vidFrstCleanVarUpdte                                    */
/*                                                                            */
/* !Reference   : V02 NT 08 08234 / 13                                        */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTIN/VLVACTINCLN/VLVACTINCLN$*/
/* $Revision::   1.1      $$Author::   mbenfrad       $$Date::   18 Mar 2013 $*/
/* $Author::   mbenfrad                               $$Date::   18 Mar 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.H"
#include "VLVACTINCLN.h"
#include "VLVACTINCLN_L.h"
#include "VLVACTINCLN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnAlgCalc                                  */
/* !Description :  calculer la durée de chaque impulsion de la commande       */
/*                 envoyée pour le nettoyage et selectionner le mode          */
/*                 (préventif ou curatif).                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_E_08_08234_005.01                                     */
/*                 VEMS_E_08_08234_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidClnCnd();                                 */
/*  extf argret void VLVACTINCLN_vidCmdcmp();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnAlgCalc(void)
{
   VLVACTINCLN_vidClnCnd();
   VLVACTINCLN_vidCmdcmp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidClnCnd                                      */
/* !Description :  selectionner le mode curatif ou préventif.                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTINCLN_vidRctCnd();                                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINCLN_vidPctcnd();                                 */
/*  extf argret void VLVACTINCLN_vidFrstCleaCond();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input uint16 VlvAct_AgInNormClnThd_C;                                     */
/*  input boolean VlvAct_bDgoClnErrVlvActIn;                                  */
/*  input boolean VlvAct_bInHealClnStMonGlblReq;                              */
/*  input boolean VlvAct_bInNormClnStReq;                                     */
/*  input boolean VlvAct_bInFrstClnStReq;                                     */
/*  output boolean VlvAct_bInMngClnStReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidClnCnd(void)
{
   boolean bLocalVlvAct_bInMngClnStReq;
   sint16  s16LocalVcpi_cam_position_error;
   uint16  u16LocalAbsVcpi_cam;


   VLVACTINCLN_vidRctCnd();

   VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
   u16LocalAbsVcpi_cam =
      (uint16)MATHSRV_udtABS(s16LocalVcpi_cam_position_error);

   if (u16LocalAbsVcpi_cam <= VlvAct_AgInNormClnThd_C)
   {
      VLVACTINCLN_vidPctcnd();
   }
   VLVACTINCLN_vidFrstCleaCond();
   if (  (VlvAct_bDgoClnErrVlvActIn == 0)
      && (  (VlvAct_bInHealClnStMonGlblReq != 0)
         || (VlvAct_bInNormClnStReq != 0)
         || (VlvAct_bInFrstClnStReq != 0)))
   {
      bLocalVlvAct_bInMngClnStReq = 1;
   }
   else
   {
      bLocalVlvAct_bInMngClnStReq = 0;
   }
   VEMS_vidSET(VlvAct_bInMngClnStReq, bLocalVlvAct_bInMngClnStReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidRctCnd                                      */
/* !Description :  Le nettoyage en mode curatif est lancé lorsque l’erreur    */
/*                 Vcpe_cam_position_error est supérieure à un seuil durant   */
/*                 une certaine période.                                      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINCLN_vidErrCntRst();                              */
/*  extf argret void VLVACTINCLN_vidRctCndFrtcln();                           */
/*  input sint16 Vcpi_cam_position_error;                                     */
/*  input uint16 VlvAct_AgInHealClnErrThd_C;                                  */
/*  input boolean VlvAct_bAcvInHealCln;                                       */
/*  input uint16 VlvAct_tiInHealClnMonErrDly;                                 */
/*  input uint16 VlvAct_tiInHealClnMonErrDly_C;                               */
/*  input uint8 VlvAct_CtInHealClnErr;                                        */
/*  input uint8 VlvAct_noHealClnActInDftThd_C;                                */
/*  input boolean VLVACTINCLN_bVlAcvInHealCln_Prev;                           */
/*  input boolean VLVACTINCLN_bFrtErrCntRst_Prev;                             */
/*  input uint8 VlvAct_tiInHealClnIdc;                                        */
/*  input uint8 VlvAct_tiInClnEndThd_C;                                       */
/*  input boolean VLVACTINCLN_bTriggerPrev;                                   */
/*  input uint16 VLVACTINCLN_u16TimerCount;                                   */
/*  input boolean VLVACTINCLN_bTimeout;                                       */
/*  input uint8 VlvAct_ctInHealClnDone;                                       */
/*  input uint8 VlvAct_ctInHealClnDoneThd_C;                                  */
/*  input boolean VlvAct_bInhInHealClnDoneCt_C;                               */
/*  input boolean VlvAct_bInHealClnStFrstReq;                                 */
/*  output boolean VlvAct_bMonRunClnErrVlvActIn;                              */
/*  output boolean VlvAct_bAcvInHealCln;                                      */
/*  output uint16 VlvAct_tiInHealClnMonErrDly;                                */
/*  output boolean VlvAct_bDgoClnErrVlvActIn;                                 */
/*  output uint16 VLVACTINCLN_u16TimerCount;                                  */
/*  output boolean VLVACTINCLN_bTimeout;                                      */
/*  output boolean VlvAct_bInHealClnStMonReq;                                 */
/*  output boolean VlvAct_bInHealClnStMonGlblReq;                             */
/*  output boolean VLVACTINCLN_bTriggerPrev;                                  */
/*  output boolean VLVACTINCLN_bFrtErrCntRst_Prev;                            */
/*  output boolean VLVACTINCLN_bVlAcvInHealCln_Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidRctCnd(void)
{
   boolean bLocalFrtErrCntRst;
   boolean bLocalTrigger;
   uint16  u16LocalAbsVcpi_cam;
   sint16  s16LocalVcpi_cam_position_error;
   sint16  s16LocaltiInHealClnMonErrDly;


   VlvAct_bMonRunClnErrVlvActIn = 1;
   VEMS_vidGET(Vcpi_cam_position_error, s16LocalVcpi_cam_position_error);
   u16LocalAbsVcpi_cam =
      (uint16)MATHSRV_udtABS(s16LocalVcpi_cam_position_error);

   if (u16LocalAbsVcpi_cam > VlvAct_AgInHealClnErrThd_C)
   {
      VlvAct_bAcvInHealCln = 1;
   }
   else
   {
      VlvAct_bAcvInHealCln = 0;
   }
   if (VlvAct_bAcvInHealCln != 0)
   {
      s16LocaltiInHealClnMonErrDly =(sint16)(VlvAct_tiInHealClnMonErrDly - 1);
      VlvAct_tiInHealClnMonErrDly =
         (uint16)MATHSRV_udtMAX(s16LocaltiInHealClnMonErrDly , 0);
   }
   else
   {
      VlvAct_tiInHealClnMonErrDly = VlvAct_tiInHealClnMonErrDly_C;
   }

   if (VlvAct_CtInHealClnErr > VlvAct_noHealClnActInDftThd_C)
   {
      VlvAct_bDgoClnErrVlvActIn = 1;
   }
   else
   {
      VlvAct_bDgoClnErrVlvActIn = 0;
   }

   if (  (VlvAct_bAcvInHealCln == 0)
      && (VLVACTINCLN_bVlAcvInHealCln_Prev != 0))
   {
      bLocalFrtErrCntRst = 1;
   }
   else
   {
      bLocalFrtErrCntRst = 0;
   }

   if (  (VLVACTINCLN_bFrtErrCntRst_Prev == 0)
      && (bLocalFrtErrCntRst != 0))
   {
      VLVACTINCLN_vidErrCntRst();
   }
   VLVACTINCLN_vidRctCndFrtcln();

   if (  (VlvAct_tiInHealClnIdc >= VlvAct_tiInClnEndThd_C)
      && (VlvAct_tiInHealClnMonErrDly == 0))
   {
      bLocalTrigger = 1;
   }
   else
   {
      bLocalTrigger = 0;
   }

   if (  (VLVACTINCLN_bTriggerPrev == 0)
      && (bLocalTrigger != 0))
   {
      VLVACTINCLN_u16TimerCount = VlvAct_tiInHealClnMonErrDly_C;
      if (VLVACTINCLN_u16TimerCount == 0)
      {
         VLVACTINCLN_bTimeout = 1;
      }
      else
      {
         VLVACTINCLN_bTimeout = 0;
      }
   }
   else
   {
      if (VLVACTINCLN_u16TimerCount > 0)
      {
         VLVACTINCLN_u16TimerCount = (uint16)(VLVACTINCLN_u16TimerCount - 1);
         if (VLVACTINCLN_u16TimerCount == 0)
         {
            VLVACTINCLN_bTimeout = 1;
         }
         else
         {
            VLVACTINCLN_bTimeout = 0;
         }
      }
   }
   if (  (VLVACTINCLN_bTimeout != 0)
      && (VlvAct_bAcvInHealCln != 0)
      && (VlvAct_tiInHealClnMonErrDly == 0))
   {
      VlvAct_bInHealClnStMonReq = 1;
      if (  (VlvAct_ctInHealClnDone < VlvAct_ctInHealClnDoneThd_C)
         || ( VlvAct_bInhInHealClnDoneCt_C != 0))
      {
         VlvAct_bInHealClnStMonGlblReq = 1;
      }
      else
      {
         VlvAct_bInHealClnStMonGlblReq = 0;
      }
   }
   else
   {
      VlvAct_bInHealClnStMonReq = 0;
      if (  (VlvAct_bInHealClnStFrstReq != 0)
         && (  (VlvAct_ctInHealClnDone < VlvAct_ctInHealClnDoneThd_C)
            || ( VlvAct_bInhInHealClnDoneCt_C != 0)))
      {
         VlvAct_bInHealClnStMonGlblReq = 1;
      }
      else
      {
         VlvAct_bInHealClnStMonGlblReq = 0;
      }
   }

   VLVACTINCLN_bTriggerPrev = bLocalTrigger;
   VLVACTINCLN_bFrtErrCntRst_Prev = bLocalFrtErrCntRst;
   VLVACTINCLN_bVlAcvInHealCln_Prev = VlvAct_bAcvInHealCln;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidErrCntRst                                   */
/* !Description :  Quand l’erreur Vcpe_cam_position_error est revenue dans des*/
/*                 limites acceptables le compteur de nettoyages en mode      */
/*                 curatif est réinitialisé.                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VlvAct_CtInHealClnErr;                                       */
/*  output boolean VlvAct_bInHealClnEnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidErrCntRst(void)
{
   VlvAct_CtInHealClnErr = 0;
   VlvAct_bInHealClnEnd = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidRctClnVarUdt                                */
/* !Description :  A chaque fois qu’un cycle de nettoyage en mode curatif se  */
/*                 termine on incrémente le compteur VlvAct_CtInHealClnErr.   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctInHealClnDone;                                       */
/*  input uint8 VlvAct_CtInHealClnErr;                                        */
/*  output uint8 VlvAct_tiInHealClnIdc;                                       */
/*  output boolean VlvAct_bInHealClnEnd;                                      */
/*  output uint8 VlvAct_ctInHealClnDone;                                      */
/*  output uint8 VlvAct_CtInHealClnErr;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidRctClnVarUdt(void)
{
   VlvAct_tiInHealClnIdc = 0;
   VlvAct_bInHealClnEnd  = 1;

   if (VlvAct_ctInHealClnDone < 255)
   {
      VlvAct_ctInHealClnDone = (uint8)(VlvAct_ctInHealClnDone + 1);
   }
   else
   {
      VlvAct_ctInHealClnDone = 255;
   }

   if (VlvAct_CtInHealClnErr < 200)
   {
      VlvAct_CtInHealClnErr = (uint8)(VlvAct_CtInHealClnErr + 1);
   }
   else
   {
      VlvAct_CtInHealClnErr = 200;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidRctCndFrtcln                                */
/* !Description :  Le nettoyage en mode curatif est lancé lorsque l’erreur    */
/*                 Vcpe_cam_position_error est supérieure à un seuil.         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvAct_bAcvInHealCln;                                       */
/*  input boolean VlvAct_bInHealClnEnd;                                       */
/*  input boolean VLVACTINCLN_bInitTimer1_Prev;                               */
/*  input uint16 VlvAct_tiHealClnActInDly_C;                                  */
/*  input uint16 VLVACTINCLN_u16TimerCount1;                                  */
/*  input boolean VLVACTINCLN_bTimeout1;                                      */
/*  output uint16 VLVACTINCLN_u16TimerCount1;                                 */
/*  output boolean VLVACTINCLN_bTimeout1;                                     */
/*  output boolean VlvAct_bInHealClnStFrstReq;                                */
/*  output boolean VLVACTINCLN_bInitTimer1_Prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidRctCndFrtcln(void)
{
   boolean bLocalInitTimer1;


   if (  (VlvAct_bAcvInHealCln != 0)
      && (VlvAct_bInHealClnEnd == 0))
   {
      bLocalInitTimer1 = 1;
   }
   else
   {
      bLocalInitTimer1 = 0;
   }
   /*TIMER*/
   if (  (VLVACTINCLN_bInitTimer1_Prev == 0)
      && (bLocalInitTimer1 != 0))
   {
      VLVACTINCLN_u16TimerCount1 = VlvAct_tiHealClnActInDly_C;
      if (VLVACTINCLN_u16TimerCount1 == 0)
      {
         VLVACTINCLN_bTimeout1 = 1;
      }
      else
      {
         VLVACTINCLN_bTimeout1 = 0;
      }
   }
   else
   {
      if (VLVACTINCLN_u16TimerCount1 > 0)
      {
         VLVACTINCLN_u16TimerCount1 = (uint16)(VLVACTINCLN_u16TimerCount1 - 1);
         if (VLVACTINCLN_u16TimerCount1 == 0)
         {
            VLVACTINCLN_bTimeout1 = 1;
         }
         else
         {
            VLVACTINCLN_bTimeout1 = 0;
         }
      }
   }
   if (  (VLVACTINCLN_bTimeout1 != 0)
      && (bLocalInitTimer1 != 0))
   {
      VlvAct_bInHealClnStFrstReq = 1;
   }
   else
   {
      VlvAct_bInHealClnStFrstReq = 0;
   }
   VLVACTINCLN_bInitTimer1_Prev = bLocalInitTimer1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidPctcnd                                      */
/* !Description :  Le nettoyage en mode préventif se déroule lors de phases   */
/*                 impactant peu le fonctionnement moteur (ralenti,coupure    */
/*                 d’injection).Il est lancé suivant une récurrence définit   */
/*                 par la calibration VlvAct_tiInNormClnDly_C.                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  M.ZIDI                                                     */
/* !Trace_To    :  VEMS_E_08_08234_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTINCLN_vidPctClnVarUdt();                           */
/*  extf argret void VLVACTINCLN_vidManCleanVarUpdate();                      */
/*  input boolean Auto_injection;                                             */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 VlvAct_tiInNormClnIdc;                                        */
/*  input uint8 VlvAct_tiInClnEndThd_C;                                       */
/*  input boolean VLVACTINCLN_bInitTimer2_Prev;                               */
/*  input uint16 VlvAct_tiInNormClnDly_C;                                     */
/*  input uint32 VLVACTINCLN_u32TimerCount2;                                  */
/*  input boolean VlvAct_bInNormClnEnd;                                       */
/*  input boolean VLVACTINCLN_bTimeout2;                                      */
/*  input boolean VlvAct_bInManClnEnaIdc;                                     */
/*  input uint8 VlvAct_ctInNormClnDone;                                       */
/*  input uint8 VlvAct_ctInNormClnDoneThd_C;                                  */
/*  input boolean VlvAct_bInhInNormClnDoneCt_C;                               */
/*  input boolean Srv_bAcvVlvActNormCln;                                      */
/*  input boolean VlvAct_bInMngClnBenchEna_C;                                 */
/*  input boolean VLVACTINCLN_bVlvActClnBeEnaPrev;                            */
/*  input boolean VLVACTINCLN_bManCleanVarUpPrev;                             */
/*  output uint32 VLVACTINCLN_u32TimerCount2;                                 */
/*  output boolean VLVACTINCLN_bTimeout2;                                     */
/*  output boolean VlvAct_bInNormClnStReq;                                    */
/*  output boolean VLVACTINCLN_bVlvActClnBeEnaPrev;                           */
/*  output boolean VLVACTINCLN_bInitTimer2_Prev;                              */
/*  output boolean VLVACTINCLN_bManCleanVarUpPrev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidPctcnd(void)
{
   boolean bLocalInitTimer2;
   boolean bLocalAutoOrErEqEn;
   boolean bLocalAuto_injection;
   boolean bLocalSrv_bAcvVlvActNormCln;
   boolean bLocalManCleanVarUp;
   uint8   u8LocalEngine_running_state;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);

   if (VlvAct_tiInNormClnIdc >= VlvAct_tiInClnEndThd_C)
   {
      bLocalInitTimer2 = 1;
   }
   else
   {
      bLocalInitTimer2 = 0;
   }
   /*TIMER*/
   if (  (VLVACTINCLN_bInitTimer2_Prev == 0)
      && (bLocalInitTimer2 != 0))
   {
      VLVACTINCLN_vidPctClnVarUdt();
      VLVACTINCLN_u32TimerCount2 = (uint32)(VlvAct_tiInNormClnDly_C * 100);
      if (VLVACTINCLN_u32TimerCount2 == 0)
      {
         VLVACTINCLN_bTimeout2 = 1;
      }
      else
      {
         VLVACTINCLN_bTimeout2 = 0;
      }
   }
   else
   {
      if (VLVACTINCLN_u32TimerCount2 > 0)
      {
         VLVACTINCLN_u32TimerCount2 = VLVACTINCLN_u32TimerCount2 - 1;
         if (VLVACTINCLN_u32TimerCount2 == 0)
         {
            VLVACTINCLN_bTimeout2 = 1;
         }
         else
         {
            VLVACTINCLN_bTimeout2 = 0;
         }
      }
   }

   if (  (u8LocalEngine_running_state == ERUN_ON_IDLE)
      || (bLocalAuto_injection == 0))
   {
      bLocalAutoOrErEqEn = 1;
   }
   else
   {
      bLocalAutoOrErEqEn = 0;
   }

   if (  (  (bLocalAutoOrErEqEn != 0)
         && (  (VlvAct_bInNormClnEnd == 0)
            || (VLVACTINCLN_bTimeout2 != 0)))
      || (VlvAct_bInManClnEnaIdc != 0))
   {
      if (  (VlvAct_ctInNormClnDone < VlvAct_ctInNormClnDoneThd_C)
         || (VlvAct_bInhInNormClnDoneCt_C != 0))
      {
         VlvAct_bInNormClnStReq = 1;
      }
      else
      {
         VlvAct_bInNormClnStReq = 0;
      }
   }
   else
   {
      VlvAct_bInNormClnStReq = 0;
   }

   VEMS_vidGET(Srv_bAcvVlvActNormCln, bLocalSrv_bAcvVlvActNormCln);
   bLocalManCleanVarUp = 0;
   if (  (  (bLocalSrv_bAcvVlvActNormCln != 0)
         || (  (VlvAct_bInMngClnBenchEna_C != 0)
            && (VLVACTINCLN_bVlvActClnBeEnaPrev == 0)))
      && (VLVACTINCLN_bManCleanVarUpPrev == 0))
   {
      bLocalManCleanVarUp = 1;
      VLVACTINCLN_vidManCleanVarUpdate();
   }
   VLVACTINCLN_bVlvActClnBeEnaPrev = VlvAct_bInMngClnBenchEna_C;
   VLVACTINCLN_bInitTimer2_Prev = bLocalInitTimer2;
   VLVACTINCLN_bManCleanVarUpPrev = bLocalManCleanVarUp;
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidPctClnVarUdt                                */
/* !Description :  mise à jour des variables VlvAct_tiInNormClnIdc,           */
/*                 VlvAct_bInNormClnEnd et VlvAct_bInManClnEnaIdc.            */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctInNormClnDone;                                       */
/*  output uint8 VlvAct_tiInNormClnIdc;                                       */
/*  output boolean VlvAct_bInNormClnEnd;                                      */
/*  output boolean VlvAct_bInManClnEnaIdc;                                    */
/*  output uint8 VlvAct_ctInNormClnDone;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidPctClnVarUdt(void)
{
   VlvAct_tiInNormClnIdc = 0;
   VlvAct_bInNormClnEnd = 1;
   VlvAct_bInManClnEnaIdc = 0;

   if (VlvAct_ctInNormClnDone < 255)
   {
      VlvAct_ctInNormClnDone = (uint8)(VlvAct_ctInNormClnDone + 1);
   }
   else
   {
      VlvAct_ctInNormClnDone = 255;
   }
}
/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidManCleanVarUpdate                           */
/* !Description :  Mise à jour de la variable VlvAct_bInManClnEnaIdc.         */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VlvAct_bInManClnEnaIdc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidManCleanVarUpdate(void)
{
   VlvAct_bInManClnEnaIdc = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTINCLN_vidFrstCleanVarUpdte                           */
/* !Description :  Mise à jour de VlvAct_ctInFrstClnCyc et                    */
/*                 VlvAct_tiInFrstClnIdc.                                     */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  M.ZIDI                                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctInFrstClnCyc;                                        */
/*  output uint8 VlvAct_tiInFrstClnIdc;                                       */
/*  output uint8 VlvAct_ctInFrstClnCyc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTINCLN_vidFrstCleanVarUpdte(void)
{
   VlvAct_tiInFrstClnIdc = 0;
   if (VlvAct_ctInFrstClnCyc < 255)
   {
      VlvAct_ctInFrstClnCyc = (uint8)(VlvAct_ctInFrstClnCyc + 1);
   }
   else
   {
      VlvAct_ctInFrstClnCyc = 255;
   }
}
/*---------------------------- end of file -----------------------------------*/