/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : HRDRCVMNG                                               */
/* !Description     : HRDRCVMNG component.                                    */
/*                                                                            */
/* !Module          : HRDRCVMNG                                               */
/* !Description     : GESTIONNAIRE DES RECONFIGURATIONS NON CALIBRABLES .     */
/*                                                                            */
/* !File            : HRDRCVMNG_FCT1.C                                        */
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
/*   1 / HRDRCVMNG_vidInitialization                                          */
/*   2 / HRDRCVMNG_vidXvv                                                     */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/Ref/modules/GDGAR/HRDRCVMNG/HRDRCVMNG_FCT1.C_v$*/
/* $Revision::   1.0      $$Author::   acabresp       $$Date::   22 Jun 2009 $*/
/******************************************************************************/

#include "STD_TYPES.h"
#include "MATHSRV.h"
#include "HRDRCVMNG.h"
#include "HRDRCVMNG_L.h"
#include "HRDRCVMNG_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Fonction d'initialisation des sorties                       */
/* !Number      : FCT1.1                                                      */
/* !Reference   : V02 NT 09 03395 / 1                                         */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   input boolean FRM_bEnaDeacVSCtlEng;                                      */
/*   input boolean FRM_bEnaDeacVSCtlTra;                                      */
/*   input boolean FRM_bEnaDeacVSCtlVSLim;                                    */
/*   input boolean FRM_bEnaDeacVSCtlVSMax;                                    */
/*   input boolean FRM_bEnaDeacVSCtlVSReg;                                    */
/*   input boolean FRM_bEnaDeacVSCtlVeh;                                      */
/*                                                                            */
/*   output boolean HRDRCVMNG_bTimerInput;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HRDRCVMNG_vidInitialization(void)
{
   HRDRCVMNG_bTimerInput = 0;
   VEMS_vidSET(FRM_bEnaDeacVSCtlEng, 0);
   VEMS_vidSET(FRM_bEnaDeacVSCtlTra, 0);
   VEMS_vidSET(FRM_bEnaDeacVSCtlVSLim, 0);
   VEMS_vidSET(FRM_bEnaDeacVSCtlVSMax, 0);
   VEMS_vidSET(FRM_bEnaDeacVSCtlVSReg, 0);
   VEMS_vidSET(FRM_bEnaDeacVSCtlVeh, 0);
}


/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/*                                                                            */
/* !Description : Les différents booléens d’initialisations sont mis à 1 sur  */
/*                front montant de l’indicateur d'autorisation de surveillance*/
/*                intersystème ( Diag _on ) et uniquement lorsque clef de     */
/*                contact est à 1.                                            */
/* !Number      : FCT1.2                                                      */
/* !Reference   : V02 NT 09 03395 / 1                                         */
/* !Requirement : VEMS_R_09_02056_041.01                                      */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*                                                                            */
/*   input boolean Diag_on;                                                   */
/*   input boolean Clef_de_contact;                                           */
/*   input boolean HRDRCVMNG_bTimerInput;                                     */
/*   input uint16 Fgid_ti_VsctlDiagIni_C;                                     */
/*   input uint8 HRDRCVMNG_u8TimerCount;                                      */
/*   input boolean HRDRCVMNG_bTimerOutput;                                    */
/*   input boolean Fgid_b_VsctlDiagIni;                                       */
/*   input boolean FRM_bEnaDeacVSCtlVSMax;                                    */
/*   input boolean FRM_bEnaDeacVSCtlVSLim;                                    */
/*   input boolean FRM_bEnaDeacVSCtlEng;                                      */
/*   input boolean FRM_bEnaDeacVSCtlVSReg;                                    */
/*   input boolean FRM_bEnaDeacVSCtlTra;                                      */
/*   input boolean FRM_bEnaDeacVSCtlVeh;                                      */
/*                                                                            */
/*   output boolean HRDRCVMNG_bTimerInput;                                    */
/*   output uint8 HRDRCVMNG_u8TimerCount;                                     */
/*   output boolean HRDRCVMNG_bTimerOutput;                                   */
/*   output boolean Fgid_b_VsctlDiagIni;                                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !LastAuthor  : B.KBOUBI                                                    */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void HRDRCVMNG_vidXvv(void)
{
   boolean bLocalDiag_on;
   boolean bLocalClef_de_contact;
   boolean bLocalTimerInPrev;
   uint16  u16LocalCounter;


   VEMS_vidGET(Diag_on, bLocalDiag_on);
   VEMS_vidGET(Clef_de_contact, bLocalClef_de_contact);

   bLocalTimerInPrev = HRDRCVMNG_bTimerInput;

   if (  (bLocalDiag_on != 0)
      && (bLocalClef_de_contact !=0 ))
   {
      HRDRCVMNG_bTimerInput = 1;
   }
   else
   {
      HRDRCVMNG_bTimerInput = 0;
   }

   if (  (HRDRCVMNG_bTimerInput != 0)
      && (bLocalTimerInPrev == 0))
   {
      u16LocalCounter = (uint16)(Fgid_ti_VsctlDiagIni_C / 4);
      HRDRCVMNG_u8TimerCount = (uint8)MATHSRV_udtMIN(u16LocalCounter, 250);

      if (HRDRCVMNG_u8TimerCount == 0)
      {
         HRDRCVMNG_bTimerOutput = 1;
      }
      else
      {
         HRDRCVMNG_bTimerOutput = 0;
      }
   }
   else
   {
      if (HRDRCVMNG_u8TimerCount > 0)
      {
         HRDRCVMNG_u8TimerCount = (uint8)(HRDRCVMNG_u8TimerCount - 1);

         if (HRDRCVMNG_u8TimerCount == 0)
         {
            HRDRCVMNG_bTimerOutput = 1;
         }
         else
         {
            HRDRCVMNG_bTimerOutput = 0;
         }
      }
   }

   if (  (HRDRCVMNG_bTimerOutput != 0)
      && (HRDRCVMNG_bTimerInput != 0))
   {
      Fgid_b_VsctlDiagIni = 1;
   }
   else
   {
      Fgid_b_VsctlDiagIni = 0;
   }

   if (Fgid_b_VsctlDiagIni != 0)
   {
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSMax, 1);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSLim, 1);
      VEMS_vidSET(FRM_bEnaDeacVSCtlEng, 1);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSReg, 1);
      VEMS_vidSET(FRM_bEnaDeacVSCtlTra, 1);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVeh, 1);
   }
   else
   {
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSMax, 0);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSLim, 0);
      VEMS_vidSET(FRM_bEnaDeacVSCtlEng, 0);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVSReg, 0);
      VEMS_vidSET(FRM_bEnaDeacVSCtlTra, 0);
      VEMS_vidSET(FRM_bEnaDeacVSCtlVeh, 0);
   }
}
/*------------------------------- end of file --------------------------------*/