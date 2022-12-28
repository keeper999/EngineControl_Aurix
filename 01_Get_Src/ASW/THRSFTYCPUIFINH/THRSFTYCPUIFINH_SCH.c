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
/* !File            : THRSFTYCPUIFINH_SCH.C                                   */
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
/*   1 / Thr_EveRst_IfInhThrCpuSfty                                           */
/*   2 / Thr_SdlFast_IfInhThrCpuSfty                                          */
/*   3 / Thr_EveTestAbort_IfInhThrCpuSfty                                     */
/*   4 / Thr_EveTestEnd_IfInhThrCpuSfty                                       */
/*                                                                            */
/* !Reference   : PTS_DOC_5060895 / 03                                        */
/* !OtherRefs   : VEMS V02 ECU#065162                                         */
/* !OtherRefs   : VEMS V02 ECU#066733                                         */
/*                                                                            */
/**************************** </AUTO_FILE_HEADER> *****************************/
/******************************************************************************/
/* PVCS Information                                                           */
/* $Archive::   P:/EBx_V46/LDA/REF/modules/THR/THRSFTYCPUIFINH/THRSFTYCPUIFIN$*/
/* $Revision::   1.7      $$Author::   wbouach        $$Date::   25 Jun 2014 $*/
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
#include "GDGAR.h"

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveRst_IfInhThrCpuSfty                                 */
/* !Description :  Evènement Reset de la fonction Thr.                        */
/* !Number      :  SCH.1                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_E_09_03124_002.01                                     */
/*                 VEMS_E_09_03124_003.01                                     */
/*                 VEMS_E_09_03124_004.01                                     */
/*                 VEMS_R_09_03124_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYCPUIFINH_vidReadMcwInhib();                       */
/*  extf argret void THRSFTYCPUIFINH_vidInitOutput();                         */
/*  extf argret void THRSFTYCPUIFINH_vidInit();                               */
/*  extf argret void THRSFTYCPUIFINH_vidRnitBswAbtcnt();                      */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveRst_IfInhThrCpuSfty                                     */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveRst_IfInhThrCpuSfty(void)
{
   THRSFTYCPUIFINH_vidReadMcwInhib();
   THRSFTYCPUIFINH_vidInitOutput();
   THRSFTYCPUIFINH_vidInit();
   THRSFTYCPUIFINH_vidRnitBswAbtcnt();
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_SdlFast_IfInhThrCpuSfty                                */
/* !Description :  Moniteur rapide de la fonction papillon.                   */
/* !Number      :  SCH.2                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_E_09_03124_002.01                                     */
/*                 VEMS_E_09_03124_003.01                                     */
/*                 VEMS_E_09_03124_004.01                                     */
/*                 VEMS_R_09_03124_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYCPUIFINH_vidMcwInhApiMngt();                      */
/*  extf argret void THRSFTYCPUIFINH_vidReadMcwInhib();                       */
/*  extf argret void THRSFTYCPUIFINH_vidMcwdgInhTest1();                      */
/*  extf argret void THRSFTYCPUIFINH_vidMcwdgInhTest2();                      */
/*  extf argret void THRSFTYCPUIFINH_vidOldStructMang();                      */
/*  extf argret void THRSFTYCPUIFINH_vidMcwInhTstEnd();                       */
/*  extf VEMS_vidGET(argin, argio);                                           */
/*  extf argret void GDGAR_vidGdu(argin uint16 u16IdxDft, argin boolean bDgo, */
/* argin boolean bMonRun, argin boolean Ns_bMonWait);                         */
/*  input uint8 THRSFTYCPUIFINH_u8Inhib;                                      */
/*  input boolean Thr_bAuth_IfInhThrCpuSfty_C;                                */
/*  input st01 Tpac_throttle_control_state;                                   */
/*  input uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;                              */
/*  input boolean Thr_bDgoReadPinInhThr_Cpu;                                  */
/*  input boolean Thr_bDgoInhThr_CpuSfty;                                     */
/*  input boolean Thr_bMonRunReadPinInhThr_Cpu;                               */
/*  input boolean Thr_bMonRunInhThr_CpuSfty;                                  */
/*  output uint8 THRSFTYCPUIFINH_u8TpacThrStPrev2;                            */
/*  output uint8 THRSFTYCPUIFINH_u8TpacThrStPrev;                             */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_SdlFast_IfInhThrCpuSfty                                    */
/*                                                                            */
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_SdlFast_IfInhThrCpuSfty(void)
{
   boolean bLocalThr_bDgoReadPinInhThr_Cpu;
   boolean bLocalThr_bMonRunReadPinInhThrCp;
   boolean bLocalThr_bDgoInhThr_CpuSfty;
   boolean bLocalThr_bMonRunInhThr_CpuSfty;
   uint8   u8LocalTpac_throttle_control_st;


   if (THRSFTYCPUIFINH_u8Inhib != 0x5A)
   {
      THRSFTYCPUIFINH_vidMcwInhApiMngt();
      THRSFTYCPUIFINH_vidReadMcwInhib();
      if (Thr_bAuth_IfInhThrCpuSfty_C != 0)
      {
         THRSFTYCPUIFINH_vidMcwdgInhTest1();
         THRSFTYCPUIFINH_vidMcwdgInhTest2();
      }
      THRSFTYCPUIFINH_vidOldStructMang();
      THRSFTYCPUIFINH_vidMcwInhTstEnd();

      VEMS_vidGET(Tpac_throttle_control_state, u8LocalTpac_throttle_control_st);
      THRSFTYCPUIFINH_u8TpacThrStPrev2 = THRSFTYCPUIFINH_u8TpacThrStPrev;
      THRSFTYCPUIFINH_u8TpacThrStPrev = u8LocalTpac_throttle_control_st;

      VEMS_vidGET(Thr_bDgoReadPinInhThr_Cpu, bLocalThr_bDgoReadPinInhThr_Cpu);
      VEMS_vidGET(Thr_bDgoInhThr_CpuSfty, bLocalThr_bDgoInhThr_CpuSfty);
      VEMS_vidGET(Thr_bMonRunReadPinInhThr_Cpu,
                  bLocalThr_bMonRunReadPinInhThrCp);
      VEMS_vidGET(Thr_bMonRunInhThr_CpuSfty,
                  bLocalThr_bMonRunInhThr_CpuSfty);

      GDGAR_vidGdu(GD_DFT_READPININHTHR_CPU,
                   bLocalThr_bDgoReadPinInhThr_Cpu,
                   bLocalThr_bMonRunReadPinInhThrCp,
                   DIAG_DISPO);

      GDGAR_vidGdu(GD_DFT_INHTHR_CPUSFTY,
                   bLocalThr_bDgoInhThr_CpuSfty,
                   bLocalThr_bMonRunInhThr_CpuSfty,
                   DIAG_DISPO);
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveTestAbort_IfInhThrCpuSfty                           */
/* !Description :  Evènement d'abandon des tests fonctionnels d'inhibition    */
/* !Number      :  SCH.3                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_E_09_03124_002.01                                     */
/*                 VEMS_E_09_03124_003.01                                     */
/*                 VEMS_E_09_03124_004.01                                     */
/*                 VEMS_R_09_03124_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYCPUIFINH_vidReadMcwInhib();                       */
/*  extf argret void THRSFTYCPUIFINH_vidInit();                               */
/*  extf argret void THRSFTYCPUIFINH_vidBswAbortcount();                      */
/*  input uint8 THRSFTYCPUIFINH_u8Inhib;                                      */
/*  input boolean Thr_bAcvTestAbortSfty_C;                                    */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveTestAbort_IfInhThrCpuSfty                               */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveTestAbort_IfInhThrCpuSfty(void)
{
   if (THRSFTYCPUIFINH_u8Inhib != 0x5A)
   {
      if (Thr_bAcvTestAbortSfty_C != 0)
      {
         THRSFTYCPUIFINH_vidReadMcwInhib();
         THRSFTYCPUIFINH_vidInit();
         THRSFTYCPUIFINH_vidBswAbortcount();
      }
   }
}

/*************************** <AUTO_FUNCTION_HEADER> ***************************/
/*                                                                            */
/* !Function    :  Thr_EveTestEnd_IfInhThrCpuSfty                             */
/* !Description :  Evènement de fin des tests fonctionnels d'inhibition       */
/* !Number      :  SCH.4                                                      */
/* !Author      :  O.BOUZID                                                   */
/* !Trace_To    :  VEMS_E_09_03124_002.01                                     */
/*                 VEMS_E_09_03124_003.01                                     */
/*                 VEMS_E_09_03124_004.01                                     */
/*                 VEMS_R_09_03124_001.01                                     */
/*                                                                            */
/******************************************************************************/
/*                                                                            */
/*  extf argret void THRSFTYCPUIFINH_vidMcwIhBswTstEd();                      */
/*  extf argret void THRSFTYCPUIFINH_vidMcwInhTstEnd();                       */
/*  input uint8 THRSFTYCPUIFINH_u8Inhib;                                      */
/*  input boolean Thr_bAcvBswTestEndSfty_C;                                   */
/*                                                                            */
/************************** </AUTO_FUNCTION_HEADER> ***************************/
/* !Trigger  : Thr_EveTestEnd_IfInhThrCpuSfty                                 */
/*                                                                            */
/******************************************************************************/
/************************* <AUTO_FUNCTION_PROTOTYPE> **************************/
void Thr_EveTestEnd_IfInhThrCpuSfty(void)
{
   if (THRSFTYCPUIFINH_u8Inhib != 0x5A)
   {
      if (Thr_bAcvBswTestEndSfty_C != 0)
      {
         THRSFTYCPUIFINH_vidMcwIhBswTstEd();
         THRSFTYCPUIFINH_vidMcwInhTstEnd();
      }
   }
}
/*------------------------------- end of file --------------------------------*/