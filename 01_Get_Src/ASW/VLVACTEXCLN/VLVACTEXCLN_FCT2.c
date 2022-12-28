/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : VLVACTEXCLN                                             */
/* !Description     : VLVACTEXCLN component.                                  */
/*                                                                            */
/* !Module          : VLVACTEXCLN                                             */
/* !Description     : NETTOYAGE DE L’ELECTROVANNE DE LA VVT ECHAPPEMENT       */
/*                                                                            */
/* !File            : VLVACTEXCLN_FCT2.C                                      */
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
/*   1 / VLVACTEXCLN_vidClnAlgCalc                                            */
/*   2 / VLVACTEXCLN_vidClnCnd                                                */
/*   3 / VLVACTEXCLN_vidRctCnd                                                */
/*   4 / VLVACTEXCLN_vidErrCntRst                                             */
/*   5 / VLVACTEXCLN_vidRctClnVarUdt                                          */
/*   6 / VLVACTEXCLN_vidRctCndFrtcln                                          */
/*   7 / VLVACTEXCLN_vidPctcnd                                                */
/*   8 / VLVACTEXCLN_vidPctClnVarUdt                                          */
/*   9 / VLVACTEXCLN_vidManCleanVarUpdate                                     */
/*   10 / VLVACTEXCLN_vidFrstCleanVarUpdte                                    */
/*                                                                            */
/* !Reference   : V02 NT 08 08235 / 12                                        */
/* !OtherRefs   : VEMS V02 ECU#055441                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/VLVACTEX/VLVACTEXCLN/VLVACTEXCLN$*/
/* $Revision::   1.3      $$Author::   mbenfrad       $$Date::   12 Jul 2013 $*/
/* $Author::   mbenfrad                               $$Date::   12 Jul 2013 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "VLVACTEXCLN.h"
#include "VLVACTEXCLN_L.h"
#include "VLVACTEXCLN_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnAlgCalc                                  */
/* !Description :  calculer la durée de chaque impulsion de la commande       */
/*                 envoyée pour le nettoyage et selectionner le mode          */
/*                 (préventif ou curatif).                                    */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_E_08_08235_005.01                                     */
/*                 VEMS_E_08_08235_006.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidClnCnd();                                 */
/*  extf argret void VLVACTEXCLN_vidCmdcmp();                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnAlgCalc(void)
{
   VLVACTEXCLN_vidClnCnd();
   VLVACTEXCLN_vidCmdcmp();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidClnCnd                                      */
/* !Description :  selectionner le mode curatif ou préventif.                 */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void VLVACTEXCLN_vidRctCnd();                                 */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXCLN_vidPctcnd();                                 */
/*  extf argret void VLVACTEXCLN_vidFrstCleaCond();                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input sint16 Vcpe_cam_position_error;                                     */
/*  input uint16 VlvAct_AgExNormClnThd_C;                                     */
/*  input boolean VlvAct_bDgoClnErrVlvActEx;                                  */
/*  input boolean VlvAct_bExHealClnStMonGlblReq;                              */
/*  input boolean VlvAct_bExNormClnStReq;                                     */
/*  input boolean VlvAct_bExFrstClnStReq;                                     */
/*  output boolean VlvAct_bExMngClnStReq;                                     */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidClnCnd(void)
{
   boolean bLocalVlvAct_bExMngClnStReq;
   sint16  s16LocalVcpe_cam_position_error;
   uint16  u16LocalAbsVcpe_cam;


   VLVACTEXCLN_vidRctCnd();

   VEMS_vidGET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);
   u16LocalAbsVcpe_cam =
      (uint16)MATHSRV_udtABS(s16LocalVcpe_cam_position_error);

   if (u16LocalAbsVcpe_cam <= VlvAct_AgExNormClnThd_C)
   {
      VLVACTEXCLN_vidPctcnd();
   }
   VLVACTEXCLN_vidFrstCleaCond();
   if (  (VlvAct_bDgoClnErrVlvActEx == 0)
      && (  (VlvAct_bExHealClnStMonGlblReq != 0)
         || (VlvAct_bExNormClnStReq != 0)
         || (VlvAct_bExFrstClnStReq != 0)))
   {
      bLocalVlvAct_bExMngClnStReq = 1;
   }
   else
   {
      bLocalVlvAct_bExMngClnStReq = 0;
   }
   VEMS_vidSET(VlvAct_bExMngClnStReq, bLocalVlvAct_bExMngClnStReq);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidRctCnd                                      */
/* !Description :  Le nettoyage en mode curatif est lancé lorsque l’erreur    */
/*                 Vcpe_cam_position_error est supérieure à un seuil durant   */
/*                 une certaine période.                                      */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXCLN_vidErrCntRst();                              */
/*  extf argret void VLVACTEXCLN_vidRctCndFrtcln();                           */
/*  input sint16 Vcpe_cam_position_error;                                     */
/*  input uint16 VlvAct_AgExHealClnErrThd_C;                                  */
/*  input uint8 VlvAct_CtExHealClnErr;                                        */
/*  input uint8 VlvAct_noHealClnActExDftThd_C;                                */
/*  input boolean VlvAct_bAcvExHealCln;                                       */
/*  input uint16 VlvAct_tiExHealClnMonErrDly;                                 */
/*  input uint16 VlvAct_tiExHealClnMonErrDly_C;                               */
/*  input boolean VLVACTEXCLN_bVlAcvExHealCln_Prev;                           */
/*  input boolean VLVACTEXCLN_bFrtErrCntRst_Prev;                             */
/*  input uint8 VlvAct_tiExHealClnIdc;                                        */
/*  input uint8 VlvAct_tiExClnEndThd_C;                                       */
/*  input boolean VLVACTEXCLN_bTriggerPrev;                                   */
/*  input uint16 VLVACTEXCLN_u16TimerCount;                                   */
/*  input boolean VLVACTEXCLN_bTimeout;                                       */
/*  input uint8 VlvAct_ctExHealClnDone;                                       */
/*  input uint8 VlvAct_ctExHealClnDoneThd_C;                                  */
/*  input boolean VlvAct_bInhExHealClnDoneCt_C;                               */
/*  input boolean VlvAct_bExHealClnStFrstReq;                                 */
/*  output boolean VlvAct_bMonRunClnErrVlvActEx;                              */
/*  output boolean VlvAct_bAcvExHealCln;                                      */
/*  output boolean VlvAct_bDgoClnErrVlvActEx;                                 */
/*  output uint16 VlvAct_tiExHealClnMonErrDly;                                */
/*  output uint16 VLVACTEXCLN_u16TimerCount;                                  */
/*  output boolean VLVACTEXCLN_bTimeout;                                      */
/*  output boolean VlvAct_bExHealClnStMonReq;                                 */
/*  output boolean VlvAct_bExHealClnStMonGlblReq;                             */
/*  output boolean VLVACTEXCLN_bTriggerPrev;                                  */
/*  output boolean VLVACTEXCLN_bFrtErrCntRst_Prev;                            */
/*  output boolean VLVACTEXCLN_bVlAcvExHealCln_Prev;                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidRctCnd(void)
{
   /*1_Reactive_conditions */
   boolean bLocalFrtErrCntRst;
   boolean bLocalTrigger;
   uint16  u16LocalAbsVcpe_cam;
   sint16  s16LocalVcpe_cam_position_error;
   sint16  s16LocaltiExHealClnMonErrDly;

   VlvAct_bMonRunClnErrVlvActEx = 1;
   VEMS_vidGET(Vcpe_cam_position_error, s16LocalVcpe_cam_position_error);
   u16LocalAbsVcpe_cam =
      (uint16)MATHSRV_udtABS(s16LocalVcpe_cam_position_error);

   if (u16LocalAbsVcpe_cam > VlvAct_AgExHealClnErrThd_C)
   {
      VlvAct_bAcvExHealCln = 1;
   }
   else
   {
      VlvAct_bAcvExHealCln = 0;
   }

   if (VlvAct_CtExHealClnErr > VlvAct_noHealClnActExDftThd_C)
   {
      VlvAct_bDgoClnErrVlvActEx = 1;
   }
   else
   {
      VlvAct_bDgoClnErrVlvActEx = 0;
   }
   if (VlvAct_bAcvExHealCln != 0)
   {
      s16LocaltiExHealClnMonErrDly =(sint16)(VlvAct_tiExHealClnMonErrDly - 1);
      VlvAct_tiExHealClnMonErrDly =
         (uint16)MATHSRV_udtMAX(s16LocaltiExHealClnMonErrDly , 0);
   }
   else
   {
      VlvAct_tiExHealClnMonErrDly = VlvAct_tiExHealClnMonErrDly_C;
   }
   if (  (VlvAct_bAcvExHealCln == 0)
      && (VLVACTEXCLN_bVlAcvExHealCln_Prev != 0))
   {
      bLocalFrtErrCntRst = 1;
   }
   else
   {
      bLocalFrtErrCntRst = 0;
   }

   if (  (VLVACTEXCLN_bFrtErrCntRst_Prev == 0)
      && (bLocalFrtErrCntRst != 0))
   {
      VLVACTEXCLN_vidErrCntRst();
   }

   VLVACTEXCLN_vidRctCndFrtcln();

   if (  (VlvAct_tiExHealClnIdc >= VlvAct_tiExClnEndThd_C)
      && (VlvAct_tiExHealClnMonErrDly == 0))
   {
      bLocalTrigger = 1;
   }
   else
   {
      bLocalTrigger = 0;
   }
   if (  (VLVACTEXCLN_bTriggerPrev == 0)
      && (bLocalTrigger != 0))
   {
      VLVACTEXCLN_u16TimerCount = VlvAct_tiExHealClnMonErrDly_C;
      if (VLVACTEXCLN_u16TimerCount == 0)
      {
         VLVACTEXCLN_bTimeout = 1;
      }
      else
      {
         VLVACTEXCLN_bTimeout = 0;
      }
   }
   else
   {
      if (VLVACTEXCLN_u16TimerCount > 0)
      {
         VLVACTEXCLN_u16TimerCount = (uint16)(VLVACTEXCLN_u16TimerCount - 1);
         if (VLVACTEXCLN_u16TimerCount == 0)
         {
            VLVACTEXCLN_bTimeout = 1;
         }
         else
         {
            VLVACTEXCLN_bTimeout = 0;
         }
      }
   }
   if (  (VLVACTEXCLN_bTimeout != 0)
      && (VlvAct_bAcvExHealCln != 0)
      && (VlvAct_tiExHealClnMonErrDly == 0))
   {
      VlvAct_bExHealClnStMonReq = 1;
      if (  (VlvAct_ctExHealClnDone < VlvAct_ctExHealClnDoneThd_C)
         || ( VlvAct_bInhExHealClnDoneCt_C != 0))
      {
         VlvAct_bExHealClnStMonGlblReq = 1;
      }
      else
      {
         VlvAct_bExHealClnStMonGlblReq = 0;
      }
   }
   else
   {
      VlvAct_bExHealClnStMonReq = 0;
      if (  (VlvAct_bExHealClnStFrstReq != 0)
         && (  (VlvAct_ctExHealClnDone < VlvAct_ctExHealClnDoneThd_C)
            || ( VlvAct_bInhExHealClnDoneCt_C != 0)))
      {
         VlvAct_bExHealClnStMonGlblReq = 1;
      }
      else
      {
         VlvAct_bExHealClnStMonGlblReq = 0;
      }
   }

   VLVACTEXCLN_bTriggerPrev =  bLocalTrigger;
   VLVACTEXCLN_bFrtErrCntRst_Prev = bLocalFrtErrCntRst;
   VLVACTEXCLN_bVlAcvExHealCln_Prev = VlvAct_bAcvExHealCln;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidErrCntRst                                   */
/* !Description :  Quand l’erreur Vcpe_cam_position_error est revenue dans des*/
/*                 limites acceptables le compteur de nettoyages en mode      */
/*                 curatif est réinitialisé.                                  */
/* !Number      :  FCT2.4                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output uint8 VlvAct_CtExHealClnErr;                                       */
/*  output boolean VlvAct_bExHealClnEnd;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidErrCntRst(void)
{
   VlvAct_CtExHealClnErr = 0;
   VlvAct_bExHealClnEnd  = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidRctClnVarUdt                                */
/* !Description :  A chaque fois qu’un cycle de nettoyage en mode curatif se  */
/*                 termine on incrémente le compteur VlvAct_CtExHealClnErr.   */
/* !Number      :  FCT2.5                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctExHealClnDone;                                       */
/*  input uint8 VlvAct_CtExHealClnErr;                                        */
/*  output uint8 VlvAct_tiExHealClnIdc;                                       */
/*  output boolean VlvAct_bExHealClnEnd;                                      */
/*  output uint8 VlvAct_ctExHealClnDone;                                      */
/*  output uint8 VlvAct_CtExHealClnErr;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidRctClnVarUdt(void)
{
   /*Reactive_cleaning_variables_update */
   VlvAct_tiExHealClnIdc = 0;
   VlvAct_bExHealClnEnd  = 1;

   if (VlvAct_ctExHealClnDone  < 255)
   {
      VlvAct_ctExHealClnDone  = (uint8)(VlvAct_ctExHealClnDone  + 1);
   }
   else
   {
      VlvAct_ctExHealClnDone = 255;
   }

   if (VlvAct_CtExHealClnErr < 200)
   {
      VlvAct_CtExHealClnErr = (uint8)(VlvAct_CtExHealClnErr + 1);
   }
   else
   {
      VlvAct_CtExHealClnErr = 200;
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidRctCndFrtcln                                */
/* !Description :  Le nettoyage en mode curatif est lancé lorsque l’erreur    */
/*                 Vcpe_cam_position_error est supérieure à un seuil.         */
/* !Number      :  FCT2.6                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input boolean VlvAct_bAcvExHealCln;                                       */
/*  input boolean VlvAct_bExHealClnEnd;                                       */
/*  input boolean VLVACTEXCLN_bInitTimer1_Prev;                               */
/*  input uint16 VlvAct_tiHealClnActExDly_C;                                  */
/*  input uint16 VLVACTEXCLN_u16TimerCount1;                                  */
/*  input boolean VLVACTEXCLN_bTimeout1;                                      */
/*  output uint16 VLVACTEXCLN_u16TimerCount1;                                 */
/*  output boolean VLVACTEXCLN_bTimeout1;                                     */
/*  output boolean VlvAct_bExHealClnStFrstReq;                                */
/*  output boolean VLVACTEXCLN_bInitTimer1_Prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidRctCndFrtcln(void)
{
   boolean bLocalInitTimer1;


   if (  (VlvAct_bAcvExHealCln != 0)
      && (VlvAct_bExHealClnEnd == 0))
   {
      bLocalInitTimer1 = 1;
   }
   else
   {
      bLocalInitTimer1 = 0;
   }
   /*TIMER*/
   if (  (VLVACTEXCLN_bInitTimer1_Prev == 0)
      && (bLocalInitTimer1 != 0))
   {
      VLVACTEXCLN_u16TimerCount1 = VlvAct_tiHealClnActExDly_C;
      if (VLVACTEXCLN_u16TimerCount1 == 0)
      {
         VLVACTEXCLN_bTimeout1 = 1;
      }
      else
      {
         VLVACTEXCLN_bTimeout1 = 0;
      }
   }
   else
   {
      if (VLVACTEXCLN_u16TimerCount1 > 0)
      {
         VLVACTEXCLN_u16TimerCount1 = (uint16)(VLVACTEXCLN_u16TimerCount1 - 1);
         if (VLVACTEXCLN_u16TimerCount1 == 0)
         {
            VLVACTEXCLN_bTimeout1 = 1;
         }
         else
         {
            VLVACTEXCLN_bTimeout1 = 0;
         }
      }
   }
   if (  (VLVACTEXCLN_bTimeout1 != 0)
      && (bLocalInitTimer1 != 0))
   {
      VlvAct_bExHealClnStFrstReq = 1;
   }
   else
   {
      VlvAct_bExHealClnStFrstReq = 0;
   }
   VLVACTEXCLN_bInitTimer1_Prev = bLocalInitTimer1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidPctcnd                                      */
/* !Description :  Le nettoyage en mode préventif se déroule lors de phases   */
/*                 impactant peu le fonctionnement moteur (ralenti,coupure    */
/*                 d’injection).Il est lancé suivant une récurrence définit   */
/*                 par la calibration VlvAct_tiExNormClnDly_C.                */
/* !Number      :  FCT2.7                                                     */
/* !Author      :  MBENFRADJ                                                  */
/* !Trace_To    :  VEMS_E_08_08235_007.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void VLVACTEXCLN_vidPctClnVarUdt();                           */
/*  extf argret void VLVACTEXCLN_vidManCleanVarUpdate();                      */
/*  input boolean Auto_injection;                                             */
/*  input st07 Engine_running_state;                                          */
/*  input uint8 VlvAct_tiExNormClnIdc;                                        */
/*  input uint8 VlvAct_tiExClnEndThd_C;                                       */
/*  input boolean VLVACTEXCLN_bInitTimer2_Prev;                               */
/*  input uint16 VlvAct_tiExNormClnDly_C;                                     */
/*  input uint32 VLVACTEXCLN_u32TimerCount2;                                  */
/*  input boolean VlvAct_bExNormClnEnd;                                       */
/*  input boolean VLVACTEXCLN_bTimeout2;                                      */
/*  input boolean VlvAct_bExManClnEnaIdc;                                     */
/*  input uint8 VlvAct_ctExNormClnDone;                                       */
/*  input uint8 VlvAct_ctExNormClnDoneThd_C;                                  */
/*  input boolean VlvAct_bInhExNormClnDoneCt_C;                               */
/*  input boolean Srv_bAcvExNormCln;                                          */
/*  input boolean VlvAct_bExMngClnBenchEna_C;                                 */
/*  input boolean VLVACTEXCLN_bVlvActClnBeEnaPrev;                            */
/*  input boolean VLVACTEXCLN_bManCleanVarUpPrev;                             */
/*  output uint32 VLVACTEXCLN_u32TimerCount2;                                 */
/*  output boolean VLVACTEXCLN_bTimeout2;                                     */
/*  output boolean VlvAct_bExNormClnStReq;                                    */
/*  output boolean VLVACTEXCLN_bManCleanVarUpPrev;                            */
/*  output boolean VLVACTEXCLN_bVlvActClnBeEnaPrev;                           */
/*  output boolean VLVACTEXCLN_bInitTimer2_Prev;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidPctcnd(void)
{
   boolean bLocalInitTimer2;
   boolean bLocalManCleanVarUp;
   boolean bLocalAutoOrErEqEn;
   boolean bLocalAuto_injection;
   boolean bLocalSrv_bAcvExNormCln;
   uint8   u8LocalEngine_running_state;


   VEMS_vidGET(Auto_injection, bLocalAuto_injection);
   VEMS_vidGET(Engine_running_state, u8LocalEngine_running_state);

   if (VlvAct_tiExNormClnIdc >= VlvAct_tiExClnEndThd_C)
   {
      bLocalInitTimer2 = 1;
   }
   else
   {
      bLocalInitTimer2 = 0;
   }
   /*TIMER*/
   if (  (VLVACTEXCLN_bInitTimer2_Prev == 0)
      && (bLocalInitTimer2 != 0))
   {
      VLVACTEXCLN_vidPctClnVarUdt();
      VLVACTEXCLN_u32TimerCount2 = (uint32)(VlvAct_tiExNormClnDly_C * 100);
      if (VLVACTEXCLN_u32TimerCount2 == 0)
      {
         VLVACTEXCLN_bTimeout2 = 1;
      }
      else
      {
         VLVACTEXCLN_bTimeout2 = 0;
      }
   }
   else
   {
      if (VLVACTEXCLN_u32TimerCount2 > 0)
      {
         VLVACTEXCLN_u32TimerCount2 = VLVACTEXCLN_u32TimerCount2 - 1;
         if (VLVACTEXCLN_u32TimerCount2 == 0)
         {
            VLVACTEXCLN_bTimeout2 = 1;
         }
         else
         {
            VLVACTEXCLN_bTimeout2 = 0;
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
         && (  (VlvAct_bExNormClnEnd == 0)
            || (VLVACTEXCLN_bTimeout2 != 0)))
      || (VlvAct_bExManClnEnaIdc != 0))
   {
      if (  (VlvAct_ctExNormClnDone < VlvAct_ctExNormClnDoneThd_C)
         || (VlvAct_bInhExNormClnDoneCt_C != 0))
      {
         VlvAct_bExNormClnStReq = 1;
      }
      else
      {
         VlvAct_bExNormClnStReq = 0;
      }
   }
   else
   {
      VlvAct_bExNormClnStReq = 0;
   }
   /*Production du front montant*/
   VEMS_vidGET(Srv_bAcvExNormCln, bLocalSrv_bAcvExNormCln);
   bLocalManCleanVarUp = 0;
   if (  (  (bLocalSrv_bAcvExNormCln != 0)
         || (  (VlvAct_bExMngClnBenchEna_C != 0)
            && (VLVACTEXCLN_bVlvActClnBeEnaPrev == 0)))
      && (VLVACTEXCLN_bManCleanVarUpPrev == 0))
   {
      bLocalManCleanVarUp = 1;
      VLVACTEXCLN_vidManCleanVarUpdate();
   }

   VLVACTEXCLN_bManCleanVarUpPrev = bLocalManCleanVarUp;
   VLVACTEXCLN_bVlvActClnBeEnaPrev = VlvAct_bExMngClnBenchEna_C;
   VLVACTEXCLN_bInitTimer2_Prev = bLocalInitTimer2;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidPctClnVarUdt                                */
/* !Description :  mise à jour des variables VlvAct_tiExNormClnIdc et         */
/*                 VlvAct_bExNormClnEnd.                                      */
/* !Number      :  FCT2.8                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctExNormClnDone;                                       */
/*  output uint8 VlvAct_tiExNormClnIdc;                                       */
/*  output boolean VlvAct_bExNormClnEnd;                                      */
/*  output boolean VlvAct_bExManClnEnaIdc;                                    */
/*  output uint8 VlvAct_ctExNormClnDone;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidPctClnVarUdt(void)
{
   VlvAct_tiExNormClnIdc = 0;
   VlvAct_bExNormClnEnd = 1;
   VlvAct_bExManClnEnaIdc = 0;

   if (VlvAct_ctExNormClnDone  < 255)
   {
      VlvAct_ctExNormClnDone  = (uint8)(VlvAct_ctExNormClnDone  + 1);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidManCleanVarUpdate                           */
/* !Description :  Mise à jour de la variable  VlvAct_bExManClnEnaIdc         */
/* !Number      :  FCT2.9                                                     */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean VlvAct_bExManClnEnaIdc;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidManCleanVarUpdate(void)
{
   VlvAct_bExManClnEnaIdc = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  VLVACTEXCLN_vidFrstCleanVarUpdte                           */
/* !Description :  Mise à jour de VlvAct_ctExFrstClnCyc                       */
/* !Number      :  FCT2.10                                                    */
/* !Author      :  MBENFRADJ                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  input uint8 VlvAct_ctExFrstClnCyc;                                        */
/*  output uint8 VlvAct_tiExFrstClnIdc;                                       */
/*  output uint8 VlvAct_ctExFrstClnCyc;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void VLVACTEXCLN_vidFrstCleanVarUpdte(void)
{
   VlvAct_tiExFrstClnIdc = 0;
   if (VlvAct_ctExFrstClnCyc < 255)
   {
      VlvAct_ctExFrstClnCyc = (uint8)(VlvAct_ctExFrstClnCyc + 1);
   }
   else
   {
      VlvAct_ctExFrstClnCyc = 255;
   }
}
/*---------------------------- end of file -----------------------------------*/