/***************************** <AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/*                                                                            */
/* !Layer           : APPLI                                                   */
/*                                                                            */
/* !Component       : THRSFTYCPUIFINH                                         */
/* !Description     : THRSFTYCPUIFINH Component                               */
/*                                                                            */
/* !Module          : THRSFTYCPUIFINH                                         */
/* !Description     : Test de coupure du driver throttle par le               */
/*                    microcontrolleur watchdog.                              */
/*                                                                            */
/* !File            : THRSFTYCPUIFINH_FCT2.C                                  */
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
/*   1 / THRSFTYCPUIFINH_vidRnitBswAbtcnt                                     */
/*   2 / THRSFTYCPUIFINH_vidBswAbortcount                                     */
/*   3 / THRSFTYCPUIFINH_vidMcwdgInhThr                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5060895 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065162                                         */
/* !OtherRefs   : VEMS V02 ECU#066733                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/THR/THRSFTYCPUIFINH/THRSFTYCPUIFIN$*/
/* $Revision::   1.0      $$Author::   wbouach        $$Date::   25 Jun 2014 $*/
/* $Author::   wbouach                                $$Date::   25 Jun 2014 $*/
/******************************************************************************/
/* !VnrOff  : Names imposed by the customer                                   */
/******************************************************************************/
/* !CompReq :                                                                 */
/******************************************************************************/
#include "STD_TYPES.h"
#include "THRSFTYCPUIFINH.h"
#include "THRSFTYCPUIFINH_L.h"
#include "THRSFTYCPUIFINH_IM.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidRnitBswAbtcnt                           */
/* !Description :  cette fonction permet de réinitialiser le compteur         */
/*                 d’abandon (Abort).                                         */
/* !Number      :  FCT2.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output uint8 Thr_ctAbortTestInhibitSfty;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidRnitBswAbtcnt(void)
{
   VEMS_vidSET(Thr_ctAbortTestInhibitSfty, 0);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidBswAbortcount                           */
/* !Description :  cette fonction permet de compter le nombre d’abandon       */
/*                 (Abort) par le basic software lors des tests d’inhibit     */
/*                 safety.                                                    */
/* !Number      :  FCT2.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input uint8 Thr_ctAbortTestInhibitSfty;                                   */
/*  output uint8 Thr_ctAbortTestInhibitSfty;                                  */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidBswAbortcount(void)
{
   uint8 u8LocalThr_ctAbortTestInhibitSty;


   VEMS_vidGET(Thr_ctAbortTestInhibitSfty, u8LocalThr_ctAbortTestInhibitSty);
   if (u8LocalThr_ctAbortTestInhibitSty < 255)
   {
      u8LocalThr_ctAbortTestInhibitSty =
         (uint8)(u8LocalThr_ctAbortTestInhibitSty + 1);
   }
   VEMS_vidSET(Thr_ctAbortTestInhibitSfty, u8LocalThr_ctAbortTestInhibitSty);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwdgInhThr                             */
/* !Description :  Durant la durée du test 1 on vérifie si le Pin d’inhibition*/
/*                 du MCW est différent de l’état inhibition.Le cas échéant on*/
/*                 monte le défaut Thr_bDgoReadPinInhThr_Cpu.                 */
/* !Number      :  FCT2.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Tpim_filtered_inhibit_input;                                */
/*  output boolean Thr_bDgoReadPinInhThr_Cpu;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwdgInhThr(void)
{
   boolean bLocalTpim_filtered_inhibit_in;
   boolean bLocalDgoReadPinInhThr_Cpu;


   VEMS_vidGET(Tpim_filtered_inhibit_input, bLocalTpim_filtered_inhibit_in);
   if (bLocalTpim_filtered_inhibit_in != MCWDG_bMCW_INHIBIT_ACTIVE)
   {
      bLocalDgoReadPinInhThr_Cpu = 1;
   }
   else
   {
      bLocalDgoReadPinInhThr_Cpu = 0;
   }
   VEMS_vidSET(Thr_bDgoReadPinInhThr_Cpu, bLocalDgoReadPinInhThr_Cpu);
}

/*------------------------------- end of file --------------------------------*/