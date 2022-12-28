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
/* !File            : THRSFTYCPUIFINH_FCT1.C                                  */
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
/*   1 / THRSFTYCPUIFINH_vidInit                                              */
/*   2 / THRSFTYCPUIFINH_vidInitOutput                                        */
/*   3 / THRSFTYCPUIFINH_vidReadMcwInhib                                      */
/*   4 / THRSFTYCPUIFINH_vidMcwdgInhTest1                                     */
/*   5 / THRSFTYCPUIFINH_vidMcwdgInhTest2                                     */
/*   6 / THRSFTYCPUIFINH_vidMcwInhApiMngt                                     */
/*   7 / THRSFTYCPUIFINH_vidOldStructMang                                     */
/*   8 / THRSFTYCPUIFINH_vidFuncGenerator                                     */
/*   9 / THRSFTYCPUIFINH_vidMcwIhBswTstEd                                     */
/*   10 / THRSFTYCPUIFINH_vidMcwInhTstEnd                                     */
/*                                                                            */
/* !Reference   : PTS_DOC_5060895 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065162                                         */
/* !OtherRefs   : VEMS V02 ECU#066733                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/THR/THRSFTYCPUIFINH/THRSFTYCPUIFIN$*/
/* $Revision::   1.8      $$Author::   wbouach        $$Date::   25 Jun 2014 $*/
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
#include "MCWDG.h"
#include "GDGAR.h"
#include "VEMS.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidInit                                    */
/* !Description :  Initialisation des sorties                                 */
/* !Number      :  FCT1.1                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Thr_bMonRunReadPinInhThr_Cpu;                              */
/*  output boolean Thr_bDgoReadPinInhThr_Cpu;                                 */
/*  output boolean Thr_bMonRunInhThr_CpuSfty;                                 */
/*  output boolean Thr_bDgoInhThr_CpuSfty;                                    */
/*  output boolean Thr_bAcv_TestInhThr;                                       */
/*  output boolean Thr_bSwAuthEndTestInh;                                     */
/*  output boolean Thr_bBswAuthEndTestInh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidInit(void)
{
   VEMS_vidSET(Thr_bMonRunReadPinInhThr_Cpu, 0);
   VEMS_vidSET(Thr_bDgoReadPinInhThr_Cpu, 0);
   VEMS_vidSET(Thr_bMonRunInhThr_CpuSfty, 0);
   VEMS_vidSET(Thr_bDgoInhThr_CpuSfty, 0);
   VEMS_vidSET(Thr_bAcv_TestInhThr, 0);
   Thr_bSwAuthEndTestInh = 0;
   Thr_bBswAuthEndTestInh = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidInitOutput                              */
/* !Description :  Initialisation des variables internes du module            */
/*                 THRSFTYCPUIFINH.                                           */
/* !Number      :  FCT1.2                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean THRSFTYCPUIFINH_bTimeOut1;                                 */
/*  output uint16 THRSFTYCPUIFINH_u16Timer1;                                  */
/*  output boolean THRSFTYCPUIFINH_bTimeOut2;                                 */
/*  output uint16 THRSFTYCPUIFINH_u16Timer2;                                  */
/*  output boolean THRSFTYCPUIFINH_bTimeOut3;                                 */
/*  output uint16 THRSFTYCPUIFINH_u16Timer3;                                  */
/*  output uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;                             */
/*  output uint8 THRSFTYCPUIFINH_u8TpacThrStPrev2;                            */
/*  output boolean THRSFTYCPUIFINH_bEndTestInhPrev;                           */
/*  output boolean Thr_bEndTestInh_CpuSfty;                                   */
/*  output boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;                          */
/*  output boolean THRSFTYCPUIFINH_bInitTimer;                                */
/*  output boolean THRSFTYCPUIFINH_bInitTimerPrev;                            */
/*  output boolean THRSFTYCPUIFINH_bResulOut1Prev;                            */
/*  output boolean THRSFTYCPUIFINH_bResulOut2Prev;                            */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidInitOutput(void)
{
   /*03_Mcwdg_InhTest1*/
   THRSFTYCPUIFINH_bTimeOut1 = 0;
   THRSFTYCPUIFINH_u16Timer1 = 0;

   /*04_Mcwdg_InhTest2*/
   THRSFTYCPUIFINH_bTimeOut2 = 0;
   THRSFTYCPUIFINH_u16Timer2 = 0;

   /*05_Mcwdg_Mcw_Inh_api_Mngt*/
   THRSFTYCPUIFINH_bTimeOut3 = 0;
   THRSFTYCPUIFINH_u16Timer3 = 0;
   THRSFTYCPUIFINH_u8TpacThrStPrev = 0;
   THRSFTYCPUIFINH_u8TpacThrStPrev2 = 0;

   /*06_OldStruct*/
   THRSFTYCPUIFINH_bEndTestInhPrev = 0;

   /*Outputs initialization*/
   VEMS_vidSET(Thr_bEndTestInh_CpuSfty, 0);

   /*03_Mcwdg_InhTest2*/
   THRSFTYCPUIFINH_bMonRunRdCpuPrev = 0;
   THRSFTYCPUIFINH_bInitTimer = 0;
   THRSFTYCPUIFINH_bInitTimerPrev = 0;

   /*04_Mcwdg_Mcw_Inh_api_Mngt*/
   THRSFTYCPUIFINH_bResulOut1Prev = 0;
   THRSFTYCPUIFINH_bResulOut2Prev = 0;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidReadMcwInhib                            */
/* !Description :  L’appel à l’API MCWDG_bReadInhibitState retourne la valeur */
/*                 de l’ inhibition status du microcontrolleur watchdog ( PIN */
/*                 DI2( ou EN)).                                              */
/* !Number      :  FCT1.3                                                     */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_R_08_07842_005.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret boolean  MCWDG_bReadInhibitState(argin uint8 u8McwInhPin);    */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  output boolean Tpim_filtered_inhibit_input;                               */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidReadMcwInhib(void)
{
   boolean bLocalTpim_filtered_inhibit_in;


   bLocalTpim_filtered_inhibit_in =
      MCWDG_bReadInhibitState(MCWDG_u8MCW_INHIBITION_OUT1);
   VEMS_vidSET(Tpim_filtered_inhibit_input, bLocalTpim_filtered_inhibit_in);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwdgInhTest1                           */
/* !Description :  Le defaut "ReadPinEnaThr_Cpu" correspond à une incohérence */
/*                 au niveau de la relecture par le MCP du statut de la PIN   */
/*                 DI2 (ou EN)  (valeur attentue durant le test               */
/*                 EN=MCWDG_bMCW_INHIBIT_ACTIVE1 pour couper le papillon).    */
/* !Number      :  FCT1.4                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void THRSFTYCPUIFINH_vidMcwdgInhThr();                        */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bCdnTestInh_CpuSfty;                                    */
/*  input boolean Thr_bMonRunReadPinInhThr_Cpu;                               */
/*  input boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;                           */
/*  input uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;                              */
/*  input uint8 THRSFTYCPUIFINH_u8TpacThrStPrev2;                             */
/*  input uint16 Thr_tiDlyAuthMcwInhTest1_C;                                  */
/*  input uint16 THRSFTYCPUIFINH_u16Timer1;                                   */
/*  input boolean THRSFTYCPUIFINH_bTimeOut1;                                  */
/*  output boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;                          */
/*  output uint16 THRSFTYCPUIFINH_u16Timer1;                                  */
/*  output boolean THRSFTYCPUIFINH_bTimeOut1;                                 */
/*  output boolean Thr_bMonRunReadPinInhThr_Cpu;                              */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwdgInhTest1(void)
{
   boolean bLocalThr_bCdnTestInh_CpuSfty;
   boolean bLocalMonRunReadPinInhThr_Cpu;


   VEMS_vidGET(Thr_bCdnTestInh_CpuSfty, bLocalThr_bCdnTestInh_CpuSfty);
   /*saving the previous value of Thr_bMonRunReadPinInhThr_Cpu*/
   VEMS_vidGET(Thr_bMonRunReadPinInhThr_Cpu, THRSFTYCPUIFINH_bMonRunRdCpuPrev);

   if (  (THRSFTYCPUIFINH_u8TpacThrStPrev == TPAC_MCW_INHIBIT_TEST)
      && (THRSFTYCPUIFINH_u8TpacThrStPrev2 != TPAC_MCW_INHIBIT_TEST))
   {
      /*1st Timer*/
      THRSFTYCPUIFINH_u16Timer1 = Thr_tiDlyAuthMcwInhTest1_C;
      if (THRSFTYCPUIFINH_u16Timer1 == 0)
      {
         THRSFTYCPUIFINH_bTimeOut1 = 1;
      }
      else
      {
         THRSFTYCPUIFINH_bTimeOut1 = 0;
      }
   }
   else
   {
      /*1st Timer*/
      if (THRSFTYCPUIFINH_u16Timer1 > 0)
      {
         THRSFTYCPUIFINH_u16Timer1 = (uint16)(THRSFTYCPUIFINH_u16Timer1 - 1);
         if (THRSFTYCPUIFINH_u16Timer1 == 0)
         {
            THRSFTYCPUIFINH_bTimeOut1 = 1;
         }
         else
         {
            THRSFTYCPUIFINH_bTimeOut1 = 0;
         }
      }
   }

   if (  (bLocalThr_bCdnTestInh_CpuSfty != 0)
      && (THRSFTYCPUIFINH_u8TpacThrStPrev == TPAC_MCW_INHIBIT_TEST)
      && (THRSFTYCPUIFINH_bTimeOut1 == 0))
   {
      bLocalMonRunReadPinInhThr_Cpu = 1;
      THRSFTYCPUIFINH_vidMcwdgInhThr();
   }
   else
   {
      bLocalMonRunReadPinInhThr_Cpu = 0;
   }
   VEMS_vidSET(Thr_bMonRunReadPinInhThr_Cpu, bLocalMonRunReadPinInhThr_Cpu);

}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwdgInhTest2                           */
/* !Description :  Le defaut “ InhThr_cpuSfty” correspond à une incohérence au*/
/*                 niveau de la relecture par le MCP de la position papillon( */
/*                 valeur attentue durant le test = position de Limp Home).   */
/* !Number      :  FCT1.5                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bCdnTestInh_CpuSfty;                                    */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_bAuthDiagInhThr_CpuSfty;                                */
/*  input boolean Thr_bDgoReadPinInhThr_Cpu;                                  */
/*  input boolean ThrSftyMng_bThrPosnLihDrift;                                */
/*  input boolean Thr_bMonRunReadPinInhThr_Cpu;                               */
/*  input boolean THRSFTYCPUIFINH_bMonRunRdCpuPrev;                           */
/*  input boolean THRSFTYCPUIFINH_bInitTimer;                                 */
/*  input boolean THRSFTYCPUIFINH_bInitTimerPrev;                             */
/*  input uint16 Thr_tiDlyAuthMcwInhTest2_C;                                  */
/*  input uint16 THRSFTYCPUIFINH_u16Timer2;                                   */
/*  input boolean THRSFTYCPUIFINH_bTimeOut2;                                  */
/*  output boolean Thr_bDgoInhThr_CpuSfty;                                    */
/*  output boolean THRSFTYCPUIFINH_bInitTimer;                                */
/*  output uint16 THRSFTYCPUIFINH_u16Timer2;                                  */
/*  output boolean THRSFTYCPUIFINH_bTimeOut2;                                 */
/*  output boolean THRSFTYCPUIFINH_bInitTimerPrev;                            */
/*  output boolean Thr_bMonRunInhThr_CpuSfty;                                 */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwdgInhTest2(void)
{
   boolean bLocalThr_bCdnTestInh_CpuSfty;
   boolean bLocalThr_bMonRunInhThr_CpuSfty;
   boolean bLocalThr_bDgoInhThr_CpuSfty;
   boolean bLocalThrbDgoReadPinInhThrCp;
   boolean bLocalThrSftyMng_bThrPosnLihDrft;
   boolean bLocalThr_bMonRunRdPinInhThr_Cpu;
   boolean bLocalAuthDiagInhThrCpuSfty;
   uint8   u8LocalTpac_throttle_control_st;


   VEMS_vidGET(Thr_bCdnTestInh_CpuSfty, bLocalThr_bCdnTestInh_CpuSfty);
   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   VEMS_vidGET(Thr_bAuthDiagInhThr_CpuSfty, bLocalAuthDiagInhThrCpuSfty);
   VEMS_vidGET(Thr_bDgoReadPinInhThr_Cpu , bLocalThrbDgoReadPinInhThrCp);
   VEMS_vidGET(ThrSftyMng_bThrPosnLihDrift , bLocalThrSftyMng_bThrPosnLihDrft);
   VEMS_vidGET(Thr_bMonRunReadPinInhThr_Cpu, bLocalThr_bMonRunRdPinInhThr_Cpu);

   if (  (bLocalAuthDiagInhThrCpuSfty != 0)
      && (bLocalThrSftyMng_bThrPosnLihDrft != 0)
      && (bLocalThrbDgoReadPinInhThrCp == 0))
   {
      bLocalThr_bDgoInhThr_CpuSfty = 1;
   }
   else
   {
      bLocalThr_bDgoInhThr_CpuSfty = 0;
   }
   VEMS_vidSET(Thr_bDgoInhThr_CpuSfty, bLocalThr_bDgoInhThr_CpuSfty);

    /*Timer*/
   if (  (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST)
      && (bLocalThr_bMonRunRdPinInhThr_Cpu == 0)
      && (THRSFTYCPUIFINH_bMonRunRdCpuPrev != 0))
   {
      THRSFTYCPUIFINH_bInitTimer = 1;
   }
   else
   {
      THRSFTYCPUIFINH_bInitTimer = 0;
   }

   if (  (THRSFTYCPUIFINH_bInitTimer != 0)
      && (THRSFTYCPUIFINH_bInitTimerPrev == 0))
   {
      THRSFTYCPUIFINH_u16Timer2 = Thr_tiDlyAuthMcwInhTest2_C;

      if (THRSFTYCPUIFINH_u16Timer2 == 0)
      {
         THRSFTYCPUIFINH_bTimeOut2 = 1;
      }
      else
      {
         THRSFTYCPUIFINH_bTimeOut2 = 0;
      }
   }
   else
   {
      if (THRSFTYCPUIFINH_u16Timer2 > 0)
      {
         THRSFTYCPUIFINH_u16Timer2 = (uint16)(THRSFTYCPUIFINH_u16Timer2 - 1);
         if (THRSFTYCPUIFINH_u16Timer2 == 0)
         {
            THRSFTYCPUIFINH_bTimeOut2 = 1;
         }
         else
         {
            THRSFTYCPUIFINH_bTimeOut2 = 0;
         }
      }
   }

   if (  (bLocalThr_bCdnTestInh_CpuSfty != 0)
      && (THRSFTYCPUIFINH_bTimeOut2 == 0)
      && (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST))
   {
      bLocalThr_bMonRunInhThr_CpuSfty = 1;
   }
   else
   {
      bLocalThr_bMonRunInhThr_CpuSfty = 0;
   }
   THRSFTYCPUIFINH_bInitTimerPrev = THRSFTYCPUIFINH_bInitTimer;
   VEMS_vidSET(Thr_bMonRunInhThr_CpuSfty, bLocalThr_bMonRunInhThr_CpuSfty);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwInhApiMngt                           */
/* !Description :  L’appel à l’API "MCWDG_vidStartInhibitState" permet de     */
/*                 demander au LDB de  désactiver le pont H en imposant « ENA */
/*                 » du Mcw à 0.L’appel à l’API "MCWDG_vidStopInhibitState"   */
/*                 permet de réactiver le pont en  H à la fin du test.        */
/* !Number      :  FCT1.6                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void MCWDG_vidStartInhibitState(argin uint8 u8McwInhPin);     */
/*  extf argret void MCWDG_vidStopInhibitState(argin uint8 u8McwInhPin);      */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input boolean Thr_bCdnTestInh_CpuSfty;                                    */
/*  input boolean Thr_bMonRunInhThr_CpuSfty;                                  */
/*  input boolean Thr_bDgoReadPinInhThr_Cpu;                                  */
/*  input boolean Thr_bDgoInhThr_CpuSfty;                                     */
/*  input boolean THRSFTYCPUIFINH_bResulOutput1;                              */
/*  input boolean THRSFTYCPUIFINH_bResulOut1Prev;                             */
/*  input boolean THRSFTYCPUIFINH_bResulOutput2;                              */
/*  input boolean THRSFTYCPUIFINH_bResulOut2Prev;                             */
/*  input uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;                              */
/*  input uint16 Thr_tiDlyMaxMcwInhTest_C;                                    */
/*  input uint16 THRSFTYCPUIFINH_u16Timer3;                                   */
/*  input boolean THRSFTYCPUIFINH_bTimeOut3;                                  */
/*  input boolean Thr_bAcv_TestInhThr;                                        */
/*  output boolean THRSFTYCPUIFINH_bResulOutput1;                             */
/*  output boolean THRSFTYCPUIFINH_bResulOutput2;                             */
/*  output uint16 THRSFTYCPUIFINH_u16Timer3;                                  */
/*  output boolean THRSFTYCPUIFINH_bTimeOut3;                                 */
/*  output boolean Thr_bSwAuthEndTestInh;                                     */
/*  output boolean THRSFTYCPUIFINH_bResulOut1Prev;                            */
/*  output boolean THRSFTYCPUIFINH_bResulOut2Prev;                            */
/*  output boolean Thr_bAcv_TestInhThr;                                       */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwInhApiMngt(void)
{
   boolean bLocalThr_bCdnTestInh_CpuSfty;
   boolean bLocalThr_bMonRunInhThr_CpuSfty;
   boolean bLocalThr_bAcv_TestInhThr;
   boolean bLocalFlag1;
   boolean bLocalFlag2;
   boolean bLocalThr_bDgoReadPinInhThr_Cpu;
   boolean bLocalThr_bDgoInhThr_CpuSfty;
   uint8   u8LocalTpac_throttle_control_st;


   VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
   VEMS_vidGET(Thr_bCdnTestInh_CpuSfty, bLocalThr_bCdnTestInh_CpuSfty);
   VEMS_vidGET(Thr_bMonRunInhThr_CpuSfty, bLocalThr_bMonRunInhThr_CpuSfty);
   VEMS_vidGET(Thr_bDgoReadPinInhThr_Cpu, bLocalThr_bDgoReadPinInhThr_Cpu);
   VEMS_vidGET(Thr_bDgoInhThr_CpuSfty, bLocalThr_bDgoInhThr_CpuSfty);


   /*MCWDG_vidStartInhibitState*/
   if (  (bLocalThr_bCdnTestInh_CpuSfty != 0)
      && (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST))
   {
      THRSFTYCPUIFINH_bResulOutput1 = 1;
   }
   else
   {
      THRSFTYCPUIFINH_bResulOutput1 = 0;
   }
   if (  (THRSFTYCPUIFINH_bResulOutput1 != 0)
      && (THRSFTYCPUIFINH_bResulOut1Prev == 0))
   {
      bLocalFlag1 = 1;
      MCWDG_vidStartInhibitState(MCWDG_u8MCW_INHIBITION_OUT1);
   }
   else
   {
      bLocalFlag1 = 0;
   }

   /*MCWDG_vidStopInhibitState*/
   if (  (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST)
      && (bLocalThr_bMonRunInhThr_CpuSfty == 0)
      && (bLocalThr_bDgoReadPinInhThr_Cpu == 0)
      && (bLocalThr_bDgoInhThr_CpuSfty == 0)
      && ( bLocalFlag1 == 0))
   {
      THRSFTYCPUIFINH_bResulOutput2 = 1;
   }
   else
   {
      THRSFTYCPUIFINH_bResulOutput2 = 0;
   }
   if (  (THRSFTYCPUIFINH_bResulOutput2 != 0)
      && (THRSFTYCPUIFINH_bResulOut2Prev == 0))
   {
      bLocalFlag2 = 1;
      MCWDG_vidStopInhibitState(MCWDG_u8MCW_INHIBITION_OUT1);
   }
   else
   {
      bLocalFlag2 = 0;
   }

   /*Timer*/
   if (  (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST)
      && (THRSFTYCPUIFINH_u8TpacThrStPrev != TPAC_MCW_INHIBIT_TEST))
   {
      THRSFTYCPUIFINH_u16Timer3 = Thr_tiDlyMaxMcwInhTest_C;
      if (THRSFTYCPUIFINH_u16Timer3 == 0)
      {
         THRSFTYCPUIFINH_bTimeOut3 = 1;
      }
      else
      {
         THRSFTYCPUIFINH_bTimeOut3 = 0;
      }
   }
   else
   {
      if (THRSFTYCPUIFINH_u16Timer3 > 0)
      {
         THRSFTYCPUIFINH_u16Timer3 = (uint16)(THRSFTYCPUIFINH_u16Timer3 - 1);
         if (THRSFTYCPUIFINH_u16Timer3 == 0)
         {
            THRSFTYCPUIFINH_bTimeOut3 = 1;
         }
         else
         {
            THRSFTYCPUIFINH_bTimeOut3 = 0;
         }
      }
   }

   if (  (THRSFTYCPUIFINH_bTimeOut3 != 0)
      && (u8LocalTpac_throttle_control_st == TPAC_MCW_INHIBIT_TEST))
   {
      Thr_bSwAuthEndTestInh = 1;
   }

   /*Mis à jour des variables Prev*/
   THRSFTYCPUIFINH_bResulOut1Prev = THRSFTYCPUIFINH_bResulOutput1;
   THRSFTYCPUIFINH_bResulOut2Prev = THRSFTYCPUIFINH_bResulOutput2;

   if (bLocalFlag2 != 0)
   {
      bLocalThr_bAcv_TestInhThr = 0;
   }
   else
   {
      if (bLocalFlag1 != 0)
      {
         bLocalThr_bAcv_TestInhThr = 1;
      }
      else
      {
         VEMS_vidGET(Thr_bAcv_TestInhThr, bLocalThr_bAcv_TestInhThr);
      }
   }
   VEMS_vidSET(Thr_bAcv_TestInhThr, bLocalThr_bAcv_TestInhThr);
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidOldStructMang                           */
/* !Description :  Ce block gère la compatibilité avec une architecture       */
/*                 précédente.                                                */
/* !Number      :  FCT1.7                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYCPUIFINH_vidFuncGenerator();                      */
/*  input boolean Thr_bSwAuthEndTestInh;                                      */
/*  input boolean THRSFTYCPUIFINH_bEndTestInhPrev;                            */
/*  output boolean Thr_bRiseEdge_EndTestInh;                                  */
/*  output boolean THRSFTYCPUIFINH_bEndTestInhPrev;                           */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidOldStructMang(void)
{
   if (  (Thr_bSwAuthEndTestInh != 0)
      && (THRSFTYCPUIFINH_bEndTestInhPrev == 0))
   {
      Thr_bRiseEdge_EndTestInh = 1;
      THRSFTYCPUIFINH_vidFuncGenerator();
   }
   else
   {
      Thr_bRiseEdge_EndTestInh = 0;
   }
   THRSFTYCPUIFINH_bEndTestInhPrev = Thr_bSwAuthEndTestInh;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidFuncGenerator                           */
/* !Description :  Génération de l'événement Thr_EveChkLih_MngServo.          */
/* !Number      :  FCT1.8                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void Thr_EveChkLih_MngServo();                                */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidFuncGenerator(void)
{
   Thr_EveChkLih_MngServo();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwIhBswTstEd                           */
/* !Description :  Sortie du booléen sur événement de fin de test envoyé par  */
/*                 le basic software.                                         */
/* !Number      :  FCT1.9                                                     */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  output boolean Thr_bBswAuthEndTestInh;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwIhBswTstEd(void)
{
   Thr_bBswAuthEndTestInh = 1;
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  THRSFTYCPUIFINH_vidMcwInhTstEnd                            */
/* !Description :  Calcul de la variable Thr_bEndTestInh_CpuSfty              */
/* !Number      :  FCT1.10                                                    */
/* !Author      :  O.BOUZID                                                   */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf VEMS_vidSET(argout, argio);                                          */
/*  input boolean Thr_bSwAuthEndTestInh;                                      */
/*  input boolean Thr_bBswAuthEndTestInh;                                     */
/*  input boolean Thr_bAcvBswTestEndSfty_C;                                   */
/*  input boolean Thr_bAcvAuthEndTestInh_C;                                   */
/*  output boolean Thr_bEndTestInh_CpuSfty;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void THRSFTYCPUIFINH_vidMcwInhTstEnd(void)
{
   if (  ((Thr_bSwAuthEndTestInh != 0)
      && (  (Thr_bBswAuthEndTestInh != 0)
         || (Thr_bAcvBswTestEndSfty_C == 0))) 
      || (Thr_bAcvAuthEndTestInh_C == 0))
   {
      VEMS_vidSET(Thr_bEndTestInh_CpuSfty, 1);
   }
   else
   {
      VEMS_vidSET(Thr_bEndTestInh_CpuSfty, 0);
   }
}
/*------------------------------- end of file --------------------------------*/