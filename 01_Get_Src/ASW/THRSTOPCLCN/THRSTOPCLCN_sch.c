/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSTOPCLCN                                             */
/* !Description     : THRSTOPCLCN component.                                  */
/*                                                                            */
/* !Module          : THRSTOPCLCN                                             */
/* !Description     : Calcul des butees du papillon.                          */
/*                                                                            */
/* !File            : THRSTOPCLCN_SCH.C                                       */
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
/*   1 / Thr_EveRst_StopClcn                                                  */
/*   2 / Thr_EveIniStop_MngServo                                              */
/*   3 / Thr_EveClcnServo_StopClcn                                            */
/*   4 / Thr_EveStoreHiStop_MngServo                                          */
/*   5 / Thr_EveStoreLoStop_MngServo                                          */
/*   6 / Thr_EveChkLih_MngServo_ThrStopClcn                                   */
/*   7 / Thr_EveStoreLih_StopClcn                                             */
/*   8 / Thr_EveRstThr_stopClcn                                               */
/*   9 / Thr_EveIniLrnLih_StopClcn                                            */
/*                                                                            */
/* !Reference   : V02 NT 08 04799 / 10                                        */
/* !OtherRefs   : VEMS V02 ECU#061157                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EB_DT/LOG/ASW/Ref/modules/THR/THRSTOPCLCN/THRSTOPCLCN_sch.$*/
/* $Revision::   1.2      $$Author::   etsasson       $$Date::   20 Apr 2012 $*/
/* $Author::   etsasson                               $$Date::   20 Apr 2012 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/

#include "STD_TYPES.h"
#include "THRSTOPCLCN.h"
#include "THRSTOPCLCN_L.h"
#include "THRSTOPCLCN_IM.h"
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_StopClcn                                        */
/* !Description :  Evénement reset du calculateur                             */
/* !Number      :  SCH.1                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidInitOutput();                             */
/*  extf argret void THRSTOPCLCN_vidInitEndStopHiLow();                       */
/*  extf argret void THRSTOPCLCN_vidCalc_Lih_prec();                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_StopClcn                                            */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_StopClcn(void)
{
   THRSTOPCLCN_vidInitOutput();
   THRSTOPCLCN_vidInitEndStopHiLow();  /* EVE_2 */
   THRSTOPCLCN_vidCalc_Lih_prec();     /* EVE_3 */
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveIniStop_MngServo                                    */
/* !Description :  Demande d'initialisation des valeurs maximales lues sur les*/
/*                 deux capteurs de position papillon                         */
/* !Number      :  SCH.2                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidInitEndStopHiLow();                       */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveIniStop_MngServo                                        */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveIniStop_MngServo(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidInitEndStopHiLow();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveClcnServo_StopClcn                                  */
/* !Description :  Evénement de calcul de l'asservissement papillon motorisé  */
/*                 (front montant du signal PWM de commande)                  */
/* !Number      :  SCH.3                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidPositionFiltering();                      */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveClcnServo_StopClcn                                      */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveClcnServo_StopClcn(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidPositionFiltering();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveStoreHiStop_MngServo                                */
/* !Description :  Demande de mémorisation de la butée haute du papillon      */
/* !Number      :  SCH.4                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidOpenThrusts();                            */
/*  extf argret void THRSTOPCLCN_vidEndStopDiag();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*  input boolean Thr_bDgoEndStopReq1;                                        */
/*  input boolean Thr_bMonRunEndStopReq1;                                     */
/*  input boolean Thr_bMonWaitEndStopReq1;                                    */
/*  input boolean Thr_bDgoEndStopReq2;                                        */
/*  input boolean Thr_bMonRunEndStopReq2;                                     */
/*  input boolean Thr_bMonWaitEndStopReq2;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveStoreHiStop_MngServo                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveStoreHiStop_MngServo(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidOpenThrusts();    /* EVE_11 */
      THRSTOPCLCN_vidEndStopDiag();    /* EVE_12 */
      /* EVE_2 */
      GDGAR_vidGdu (GD_DFT_ENDSTOPREQ1,
                    Thr_bDgoEndStopReq1,
                    Thr_bMonRunEndStopReq1,
                    Thr_bMonWaitEndStopReq1);
      /* EVE_3 */
      GDGAR_vidGdu (GD_DFT_ENDSTOPREQ2,
                    Thr_bDgoEndStopReq2,
                    Thr_bMonRunEndStopReq2,
                    Thr_bMonWaitEndStopReq2);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveStoreLoStop_MngServo                                */
/* !Description :  Demande de mémorisation de la butéee basse du papillon     */
/* !Number      :  SCH.5                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidClosedThrusts();                          */
/*  extf argret void THRSTOPCLCN_vidEndStopDiag();                            */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*  input boolean Thr_bDgoEndStopReq1;                                        */
/*  input boolean Thr_bMonRunEndStopReq1;                                     */
/*  input boolean Thr_bMonWaitEndStopReq1;                                    */
/*  input boolean Thr_bDgoEndStopReq2;                                        */
/*  input boolean Thr_bMonRunEndStopReq2;                                     */
/*  input boolean Thr_bMonWaitEndStopReq2;                                    */
/*  input boolean Thr_bDgoClsIdlCtl;                                          */
/*  input boolean Thr_bMonRunClsIdlCtl;                                       */
/*  input boolean Thr_bMonWaitClsIdlCtl;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveStoreLoStop_MngServo                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveStoreLoStop_MngServo(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidClosedThrusts();  /* EVE 11 */
      THRSTOPCLCN_vidEndStopDiag();    /* EVE_12 */
      /* EVE 2 */
      GDGAR_vidGdu (GD_DFT_ENDSTOPREQ1,
                  Thr_bDgoEndStopReq1,
                  Thr_bMonRunEndStopReq1,
                  Thr_bMonWaitEndStopReq1);
      /* EVE 3 */
      GDGAR_vidGdu (GD_DFT_ENDSTOPREQ2,
                  Thr_bDgoEndStopReq2,
                  Thr_bMonRunEndStopReq2,
                  Thr_bMonWaitEndStopReq2);
      GDGAR_vidGdu (GD_DFT_CLSIDLCTL,
                  Thr_bDgoClsIdlCtl,
                  Thr_bMonRunClsIdlCtl,
                  Thr_bMonWaitClsIdlCtl);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveChkLih_MngServo_ThrStopClcn                         */
/* !Description :  Demande de vérification de la position de repos du papillon*/
/* !Number      :  SCH.6                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidCheckLimpHome();                          */
/*  extf argret void THRSTOPCLCN_vidLihDiag();                                */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveChkLih_MngServo_ThrStopClcn                             */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveChkLih_MngServo_ThrStopClcn(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidCheckLimpHome();
      THRSTOPCLCN_vidLihDiag();
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveStoreLih_StopClcn                                   */
/* !Description :  Demande de mémorisation de la position de repos du papillon*/
/* !Number      :  SCH.7                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidLimpHome();                               */
/*  extf argret void THRSTOPCLCN_vidLihDiag();                                */
/*  extf argret void THRSTOPCLCN_vidStuckThr();                               */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean bDiagStWait);                         */
/*  extf argret void THRSTOPCLCN_vidCalc_Lih_prec();                          */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*  input boolean Thr_bDgoLihReq1;                                            */
/*  input boolean Thr_bMonRunLihReq1;                                         */
/*  input boolean Thr_bMonWaitLihReq1;                                        */
/*  input boolean Thr_bDgoLihReq2;                                            */
/*  input boolean Thr_bMonRunLihReq2;                                         */
/*  input boolean Thr_bMonWaitLihReq2;                                        */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveStoreLih_StopClcn                                       */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveStoreLih_StopClcn(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidLimpHome();          /* EVE_11 */
      THRSTOPCLCN_vidLihDiag();           /* EVE_12 */
      THRSTOPCLCN_vidStuckThr();          /* EVE_13 */

      GDGAR_vidGdu (GD_DFT_LIHREQ1,       /* Call_GduLihReq1 */
                    Thr_bDgoLihReq1,
                    Thr_bMonRunLihReq1,
                    Thr_bMonWaitLihReq1);
      GDGAR_vidGdu (GD_DFT_LIHREQ2,       /* Call_GduLihReq2 */
                    Thr_bDgoLihReq2,
                    Thr_bMonRunLihReq2,
                    Thr_bMonWaitLihReq2);
      THRSTOPCLCN_vidCalc_Lih_prec();     /* EVE_2  */
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRstThr_stopClcn                                     */
/* !Description :  Evèvenement de requête de recentrage des adaptatifs        */
/*                 papillon.                                                  */
/* !Number      :  SCH.8                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidReinitSrvDiag();                          */
/*  extf argret void THRSTOPCLCN_vidCalc_Lih_prec();                          */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRstThr_stopClcn                                         */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRstThr_stopClcn(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidReinitSrvDiag();   /* EVE_1 */
      THRSTOPCLCN_vidCalc_Lih_prec();  /* EVE_3 */
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveIniLrnLih_StopClcn                                  */
/* !Description :  Evénement de l'initialisation du flag d'apprentissage au   */
/*                 power on suivant en cas de dérive de limp-home.            */
/* !Number      :  SCH.9                                                      */
/* !Author      :  etsassong                                                  */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSTOPCLCN_vidIniLrnLimpHome();                         */
/*  input uint8 THRSTOPCLCN_u8Inhib;                                          */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveIniLrnLih_StopClcn                                      */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveIniLrnLih_StopClcn(void)
{
   if (THRSTOPCLCN_u8Inhib != 0x5A)
   {
      THRSTOPCLCN_vidIniLrnLimpHome();
   }
}
/*------------------------------- End of file --------------------------------*/